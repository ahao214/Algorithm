/*
�����ʽ�������ļ��ĵ�һ����N����ʾ��N��Ԫ�أ��ڶ�����N��������������M��ʾҪ���ҵ�����
�����ʽ��һ�����������Ҵ�����֣������λ�ã��������-1
����������
3
2	4	6
4
���������
2
��Ϊ����4��N�����е�λ���ǵڶ�
*/

/*
�ݹ�����㷨
���Ѿ��ź�����������δ�������a[]������Ҫ������ֵΪX����ָ��botָ�����������λ��(��Сֵ)��ָ��topָ���������Ҷ�λ��(���ֵ)��ȡbot��top���м�ֵmidָ�������м�
��top > bot ʱ���Ƚϲ���X��a[mid]����3�ֿ���
1���� X = a[mid] ���ʾ�ҵ����˳��Ƚϲ���
2���� X < a[mid] ��ѡ��ǰ��μ����Ƚϲ��ң�bot���䣬top��� mid - 1
3���� X > a[mid] ��ѡ����μ����Ƚϲ��ң�bot��� mid + 1��top����
�����Ĺ��������֣�һ�����ҵ���X = a[mid];��һ����û�ҵ����� top < bot
*/


/*
�۰���ҷ������ݹ�����㷨
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define Max 10001
using namespace std;
int a[Max], key;

int search(int bot, int top) {
	int mid;
	if (top >= bot) {
		mid = (top + bot) / 2;
		if (key == a[mid]) {
			cout << mid << endl;
			return 0;
		}
		else if (key < a[mid]) {
			search(bot, mid - 1);
		}
		else {
			search(mid + 1, top);
		}
	}
	else
	{
		printf("-1\n");
		return 0;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> key;
	search(1, n);
	return 0;
}