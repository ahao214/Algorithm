using namespace std;

#include<queue>


/*
1823. �ҳ���Ϸ�Ļ�ʤ��
���� n ��С���һ������Ϸ��С�����Χ��һȦ���� ˳ʱ��˳�� �� 1 �� n ��š�ȷ�е�˵���ӵ� i ��С���˳ʱ���ƶ�һλ�ᵽ��� (i+1) ��С����λ�ã����� 1 <= i < n ���ӵ� n ��С���˳ʱ���ƶ�һλ��ص��� 1 ��С����λ�á�

��Ϸ��ѭ���¹���

�ӵ� 1 ��С�������λ�� ��ʼ ��
����˳ʱ�뷽���� k ��С��飬����ʱ��Ҫ ���� ��ʼʱ����λС��顣�����Ȧ���м�����һЩС�����ܻᱻ������ֹһ�Ρ�
�����������һ��С�����Ҫ�뿪Ȧ�ӣ������������Ϸ��
���Ȧ������Ȼ�в�ֹһ��С��飬�Ӹո������С���� ˳ʱ����һλ С��� ��ʼ���ص����� 2 ����ִ�С�
����Ȧ�������һ��С���Ӯ����Ϸ��
���������Ϸ��С������� n ����һ������ k ��������Ϸ�Ļ�ʤ�ߡ�
*/


class Solution {
public:
	//ģ��+����
	int findTheWinner(int n, int k) {
		queue<int> qu;
		for (int i = 1; i <= n; i++) {
			qu.emplace(i);
		}
		while (qu.size() > 1) {
			for (int i = 1; i < k; i++) {
				qu.emplace(qu.front());
				qu.pop();
			}
			qu.pop();
		}
		return qu.front();
	}
};


class Solution {
public:
	//����+�ݹ�
	int findTheWinner(int n, int k) {
		if (n == 1) {
			return 1;
		}
		return (k + findTheWinner(n - 1, k) - 1) % n + 1;
	}
};


class Solution {
public:
	//����+����
	int findTheWinner(int n, int k) {
		int winner = 1;
		for (int i = 2; i <= n; i++) {
			winner = (k + winner - 1) % i + 1;
		}
		return winner;
	}
};


class Solution {
public:
	int f(int n, int k)
	{
		if (n == 1) return 0;
		return (f(n - 1, k) + k) % n;
	}

	int findTheWinner(int n, int k) {
		return f(n, k) + 1;
	}
};
