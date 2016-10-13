#include<stdio.h>
#include<iostream>
#include <limits.h>    
#include <bitset>
using namespace std;
#define MaxN 2038074750//��ɸѡ���ķ�Χ
char IsPrime[MaxN / 2];//��Ϊ����2��ż���϶���������,����ֻ��Ҫ�洢��������ɸѡ,0��ʾΪ����,1��ʾ����
int main()
{
	int N = 0, i;
	cin >> N;
	if (N > 100000000 || N < 1) //�ж��û�������Ƿ�Ϸ�
	{
		cout << "error input" << endl;
		system("pause");
		return 1;
	}
	int *Pri = new int[N];//����һ������ΪN������Pri���ڴ���Ѿ��ҵ�������
	Pri[0] = 2;//��һ������Ϊ2
	int PriN = 1;//PriN��ʾ�Ѿ��ҵ�������,��Ϊ��һ�������Ѿ���Ϊ2,���Գ�ֵΪ1
	if (1 == N)//����û�����NΪ1,��ֱ�����
	{
		cout << Pri[0] << endl;
		system("pause");
		return 0;
	}
	for (i = 3; i <= MaxN; i = i + 2) {//���øİ�������ɸѡ��,��ԭ�������ɸѡ��,��������ڶԿռ临�ӶȵĿ���,ֻ����������ɸѡ
		if (!IsPrime[i / 2 - 1]) {//IsPrime��ʾ���д�ɸѡ������
			Pri[PriN++] = i;//û����һ��ɸѡ,��С���Ǹ�û�б�ɸ��ȥ�Ķ�Ϊ����
			if (PriN >= N)//����ҵ�������>N,��ֹͣѭ��
			{
				cout << Pri[PriN - 1] << endl;
				system("pause");
				return 0;
			}
		}
		for (int j = 1; j < PriN; ++j) {//����ɸѡ���ĺ����㷨,��֤ÿ��������ֻ����һ��ɸѡ�ж�
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