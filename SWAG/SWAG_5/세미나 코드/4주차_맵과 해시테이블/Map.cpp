#include <stdio.h>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    m["asdf"] = 1;
    printf("%d\n", m["asdf"]);
    m["asdf"] += 10;
    printf("%d\n", m["asdf"]);
}
