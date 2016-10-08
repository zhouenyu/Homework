#include<stdio.h>
#include<iostream>
#include <limits.h>    
#include <bitset>
using namespace std;
#define MaxN 2038074750
char IsPrime[MaxN / 2];
int main()
{
	int N, i;
	cin >> N;
	if (N > 100000000 || N < 1)
	{
		cout << "error input" << endl;
		system("pause");
		return 1;
	}
	int *Pri = new int[N];
	Pri[0] = 2;
	int PriN = 1;
	if (1 == N)
	{
		cout << Pri[0] << endl;
		system("pause");
		return 0;
	}
	for (i = 3; i <= MaxN; i = i + 2) {
		if (!IsPrime[i / 2 - 1]) {
			Pri[PriN++] = i;
			if (PriN >= N)
			{
				cout << Pri[PriN - 1] << endl;
				system("pause");
				return 0;
			}
		}
		for (int j = 1; j < PriN; ++j) {
			int PriJ = Pri[j];
			int change = i*PriJ;
			if (change >= MaxN || change < 0)
				break;
			IsPrime[change / 2 - 1] = 1;
			if (i % PriJ == 0)
				break;
		}
	}
	system("pause");
	return 0;
}