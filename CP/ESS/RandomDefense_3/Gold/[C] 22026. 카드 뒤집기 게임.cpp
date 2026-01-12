#include <vector>
#include <string>
using namespace std;
bool reversal(int N, int M, vector<string> P)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (P[i][j] == 'X')
				for (int k = j; k < N; k += M)
					P[i][k] = 'X' + 'O' - P[i][k];
	for (int i = 0; i < M; i++)
		for (int j = M; j < N; j++)
			if (P[i][j] == 'X')
				for (int k = i; k < N; k += M)
					P[k][j] = 'X' + 'O' - P[k][j];

	for (int i = M; i < N; i++)
		for (int j = M; j < N; j++)
			if (P[i][j] == 'X')
				return 0;
	return 1;
}