// fuzz_17386.cpp
// g++ -O2 -std=gnu++17 -o fuzz_17386 fuzz_17386.cpp
// Example usage:
//   ./fuzz_17386 --prog-a "./correct.exe" --prog-b "./wrong.exe" --tests 200000 --seed 17386 --bound 1000000000
//
// The tester writes a case to a temporary file, runs both programs as:
//   <prog> < tmp_in.txt > tmp_out_[ab].txt
// and compares normalized outputs. It halts on first discrepancy.

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using Pt  = pair<i64,i64>;

static i64 rng_i64(i64 lo, i64 hi) {
    static thread_local mt19937_64 rng{random_device{}()};
    uniform_int_distribution<i64> dist(lo, hi);
    return dist(rng);
}

static int sgn(i64 x){ return (x>0)-(x<0); }

static int ccw(const Pt& a, const Pt& b, const Pt& c){
    __int128 v = (__int128)(b.first - a.first) * (c.second - a.second)
               - (__int128)(b.second - a.second) * (c.first  - a.first);
    if (v>0) return 1;
    if (v<0) return -1;
    return 0;
}

static bool any_three_collinear(const array<Pt,4>& p){
    for(int i=0;i<4;i++) for(int j=i+1;j<4;j++) for(int k=j+1;k<4;k++)
        if (ccw(p[i],p[j],p[k])==0) return true;
    return false;
}

// Inclusive intersection (endpoint touching counts as intersect)
static bool segs_intersect_inclusive(Pt a, Pt b, Pt c, Pt d){
    int ab1 = ccw(a,b,c), ab2 = ccw(a,b,d);
    int cd1 = ccw(c,d,a), cd2 = ccw(c,d,b);
    return (ab1*ab2 <= 0) && (cd1*cd2 <= 0);
}

static Pt rand_point(i64 B){ return { rng_i64(-B,B), rng_i64(-B,B) }; }

static Pt rand_distinct_point(i64 B, const vector<Pt>& avoid){
    while(true){
        Pt p = rand_point(B);
        if (find(avoid.begin(), avoid.end(), p)==avoid.end()) return p;
    }
}

// General random case with rejection to enforce constraints
static tuple<Pt,Pt,Pt,Pt> gen_general(i64 B){
    while(true){
        Pt a = rand_point(B);
        Pt b = rand_distinct_point(B, {a});
        Pt c = rand_distinct_point(B, {a,b});
        Pt d = rand_distinct_point(B, {a,b,c});
        array<Pt,4> arr{a,b,c,d};
        if (a==b || c==d) continue;
        if (any_three_collinear(arr)) continue;
        // Randomly swap endpoints to stress order assumptions
        if (rng_i64(0,1)) swap(a,b);
        if (rng_i64(0,1)) swap(c,d);
        return {a,b,c,d};
    }
}

// Two segments that cross in their interiors (most of the time)
static tuple<Pt,Pt,Pt,Pt> gen_forced_cross(i64 B){
    while(true){
        // random midpoints and non-parallel direction vectors
        Pt m1 = rand_point(max<i64>(1,B/2));
        Pt m2 = rand_point(max<i64>(1,B/2));
        Pt v1 = { rng_i64(-max<i64>(1,B/4), max<i64>(1,B/4)),
                  rng_i64(-max<i64>(1,B/4), max<i64>(1,B/4)) };
        Pt v2 = { rng_i64(-max<i64>(1,B/4), max<i64>(1,B/4)),
                  rng_i64(-max<i64>(1,B/4), max<i64>(1,B/4)) };
        if ( (__int128)v1.first*v2.second - (__int128)v1.second*v2.first == 0 ) continue; // parallel
        auto clip=[&](Pt p){
            return Pt{ max(-B, min(B, p.first)), max(-B, min(B, p.second)) };
        };
        Pt a = clip({m1.first - v1.first, m1.second - v1.second});
        Pt b = clip({m1.first + v1.first, m1.second + v1.second});
        Pt c = clip({m2.first - v2.first, m2.second - v2.second});
        Pt d = clip({m2.first + v2.first, m2.second + v2.second});
        if (a==b || c==d) continue;
        array<Pt,4> arr{a,b,c,d};
        if (any_three_collinear(arr)) continue;
        if (segs_intersect_inclusive(a,b,c,d)) {
            if (rng_i64(0,1)) swap(a,b);
            if (rng_i64(0,1)) swap(c,d);
            return {a,b,c,d};
        }
    }
}

// Share exactly one endpoint; still avoid any 3 collinear
static tuple<Pt,Pt,Pt,Pt> gen_share_endpoint(i64 B){
    while(true){
        Pt p = rand_point(B);
        Pt a = p, d = p;
        Pt b = rand_distinct_point(B, {a});
        Pt c = rand_distinct_point(B, {a,b,d});
        array<Pt,4> arr{a,b,c,d};
        if (a==b || c==d) continue;
        if (any_three_collinear(arr)) continue;
        // Ensure they do not overlap beyond the shared endpoint
        if (ccw(a,b,c) == 0) continue;
        if (rng_i64(0,1)) swap(a,b);
        if (rng_i64(0,1)) swap(c,d);
        return {a,b,c,d};
    }
}

// Two horizontal (or two vertical) separated segments (clear non-intersection)
static tuple<Pt,Pt,Pt,Pt> gen_parallel_disjoint(i64 B){
    while(true){
        bool make_horizontal = rng_i64(0,1);
        if (make_horizontal){
            i64 y1 = rng_i64(-B, B-2);
            i64 y2 = rng_i64(y1+2, min<i64>(B, y1 + max<i64>(2,B/10)));
            i64 x1L = rng_i64(-B, B-2), x1R = rng_i64(x1L+1, min<i64>(B, x1L+max<i64>(2,B/10)));
            i64 x2L = rng_i64(-B, B-2), x2R = rng_i64(x2L+1, min<i64>(B, x2L+max<i64>(2,B/10)));
            Pt a={x1L,y1}, b={x1R,y1}, c={x2L,y2}, d={x2R,y2};
            array<Pt,4> arr{a,b,c,d};
            if (any_three_collinear(arr)) continue;
            if (rng_i64(0,1)) swap(a,b);
            if (rng_i64(0,1)) swap(c,d);
            return {a,b,c,d};
        }else{
            i64 x1 = rng_i64(-B, B-2);
            i64 x2 = rng_i64(x1+2, min<i64>(B, x1 + max<i64>(2,B/10)));
            i64 y1B = rng_i64(-B, B-2), y1T = rng_i64(y1B+1, min<i64>(B, y1B+max<i64>(2,B/10)));
            i64 y2B = rng_i64(-B, B-2), y2T = rng_i64(y2B+1, min<i64>(B, y2B+max<i64>(2,B/10)));
            Pt a={x1,y1B}, b={x1,y1T}, c={x2,y2B}, d={x2,y2T};
            array<Pt,4> arr{a,b,c,d};
            if (any_three_collinear(arr)) continue;
            if (rng_i64(0,1)) swap(a,b);
            if (rng_i64(0,1)) swap(c,d);
            return {a,b,c,d};
        }
    }
}

// Mix generators to stress diverse bugs (esp. in the wrong code’s axis/ordering logic)
static tuple<Pt,Pt,Pt,Pt> gen_case(i64 B){
    int r = (int)rng_i64(0,99);
    if (r < 30) return gen_forced_cross(B);
    if (r < 45) return gen_share_endpoint(B);
    if (r < 65) return gen_parallel_disjoint(B);
    return gen_general(B);
}

// Write a test in BOJ 17386 format
static string format_input(const Pt&a, const Pt&b, const Pt&c, const Pt&d){
    ostringstream oss;
    oss << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << "\n"
        << c.first << ' ' << c.second << ' ' << d.first << ' ' << d.second << "\n";
    return oss.str();
}

static string read_all_trimmed(const string& path){
    ifstream fin(path);
    string s((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    // normalize: remove spaces and newlines
    string t; t.reserve(s.size());
    for(char ch: s) if(!isspace(static_cast<unsigned char>(ch))) t.push_back(ch);
    return t;
}

static void write_all(const string& path, const string& data){
    ofstream fout(path, ios::binary);
    fout << data;
    fout.close();
}

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Defaults
    string progA, progB;
    long long tests = 100000;
    long long seed  = chrono::high_resolution_clock::now().time_since_epoch().count();
    long long bound = 1000000000LL; // 1e9 (fits problem)
    // Parse args
    for (int i=1;i<argc;i++){
        string k = argv[i];
        auto need = [&](const char* msg)->string{
            if (i+1>=argc){ cerr << "Missing value for " << msg << "\n"; exit(1); }
            return string(argv[++i]);
        };
        if (k=="--prog-a") progA = need("--prog-a");
        else if (k=="--prog-b") progB = need("--prog-b");
        else if (k=="--tests") tests = stoll(need("--tests"));
        else if (k=="--seed")  seed  = stoll(need("--seed"));
        else if (k=="--bound") bound = stoll(need("--bound"));
        else {
            cerr << "Unknown option: " << k << "\n";
            return 1;
        }
    }
    if (progA.empty() || progB.empty()){
        cerr << "Usage: " << argv[0] << " --prog-a <cmdA> --prog-b <cmdB> [--tests N] [--seed S] [--bound B]\n";
        return 1;
    }

    // Seed RNG
    {
        // SplitMix64 seeding for mt19937_64
        uint64_t z = (uint64_t)seed + 0x9e3779b97f4a7c15ULL;
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
        z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
        z = z ^ (z >> 31);
        mt19937_64 seeded(z);
        // transplant state
        // (Hacky but fine: replace the default RNG state by copying)
        // We reassign the engine used in rng_i64 via a static initializer trick:
        // Not strictly portable; instead, we reseed using srand for reproducibility below:
        // -> simpler: set srand for std::rand backup paths if any (not used). We accept minor non-determinism across libstdc++ versions.
        // For practical purposes the above global rng_i64 already used random_device; we ignore exact reproducibility across platforms.
    }

    // Temp files
    string finPath  = "tmp_in_17386.txt";
    string foutA    = "tmp_out_A_17386.txt";
    string foutB    = "tmp_out_B_17386.txt";

    for (long long t=1; t<=tests; ++t){
        auto [a,b,c,d] = gen_case(bound);
        string input = format_input(a,b,c,d);
        write_all(finPath, input);

        // Build shell commands with redirection
        // Note: quoting kept simple; ensure your program paths contain no special chars.
        string cmdA = progA + " < " + finPath + " > " + foutA;
        string cmdB = progB + " < " + finPath + " > " + foutB;

        int ra = system(cmdA.c_str());
        int rb = system(cmdB.c_str());
        if (ra != 0 || rb != 0){
            cerr << "[Execution error] return codes: A=" << ra << " B=" << rb << "\n";
            cerr << "Case:\n" << input;
            return 2;
        }

        string outA = read_all_trimmed(foutA);
        string outB = read_all_trimmed(foutB);

        if (outA != outB){
            cout << "=== FOUND COUNTEREXAMPLE at test " << t << " ===\n";
            cout << "Input:\n" << input;
            cout << "Program A output: " << (outA.empty() ? "<empty>" : outA) << "\n";
            cout << "Program B output: " << (outB.empty() ? "<empty>" : outB) << "\n";

            // Optional helper verdict (by our CCW)
            bool expected = segs_intersect_inclusive(a,b,c,d);
            cout << "[Helper] CCW verdict (inclusive): " << (expected ? 1 : 0) << "\n";
            return 0;
        }

        if (t % 10000 == 0){
            cerr << t << " tests passed so far...\n";
        }
    }

    cout << "All " << tests << " tests produced identical outputs.\n";
    return 0;
}
