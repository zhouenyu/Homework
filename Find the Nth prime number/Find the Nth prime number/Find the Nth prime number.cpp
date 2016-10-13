#include<stdio.h>
#include<iostream>
#include <limits.h>    
#include <bitset>
using namespace std;
#define MaxN 2038074750//待筛选数的范围
char IsPrime[MaxN / 2];//因为除开2的偶数肯定不是素数,所以只需要存储奇数用于筛选,0表示为素数,1表示合数
int main()
{
	int N = 0, i;
	cin >> N;
	if (N > 100000000 || N < 1) //判定用户的输出是否合法
	{
		cout << "error input" << endl;
		system("pause");
		return 1;
	}
	int *Pri = new int[N];//创建一个长度为N的数组Pri用于存放已经找到的素数
	Pri[0] = 2;//第一个素数为2
	int PriN = 1;//PriN表示已经找到的素数,因为第一个素数已经令为2,所以初值为1
	if (1 == N)//如果用户输入N为1,则直接输出
	{
		cout << Pri[0] << endl;
		system("pause");
		return 0;
	}
	for (i = 3; i <= MaxN; i = i + 2) {//采用改版后的线性筛选法,较原版的线性筛选法,本程序出于对空间复杂度的考虑,只对奇数进行筛选
		if (!IsPrime[i / 2 - 1]) {//IsPrime表示所有待筛选的奇数
			Pri[PriN++] = i;//没进行一次筛选,最小的那个没有被筛出去的都为素数
			if (PriN >= N)//如果找到的素数>N,则停止循环
			{
				cout << Pri[PriN - 1] << endl;
				system("pause");
				return 0;
			}
		}
		for (int j = 1; j < PriN; ++j) {//线性筛选法的核心算法,保证每个数合数只进行一次筛选判定
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