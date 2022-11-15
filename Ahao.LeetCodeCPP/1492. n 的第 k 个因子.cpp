#include<vector>
#include <algorithm>

using namespace std;


/*
1492. n �ĵ� k ������
�������������� n �� k ��

��������� i ���� n % i == 0 ����ô���Ǿ�˵������ i ������ n �����ӡ�

�������� n ���������ӣ������� �������� �����㷵�ص� k �����ӡ���� n ������������ k �����㷵�� -1 ��
*/
class Solution {
public:
	int kthFactor(int n, int k) {
		vector<int> res;
		for (int i = 1; i <= n / i; i++)
		{
			if (n % i == 0)
			{
				res.push_back(i);
				if (n / i != i) res.push_back(n / i);
			}
		}
		sort(res.begin(), res.end());
		if (k > res.size()) return -1;
		return res[k - 1];
	}

	int kthFactor(int n, int k) {
		for (int i = 1; i <= n; i++)
		{
			if (n % i == 0 && --k == 0)
				return i;
		}
		return -1;
	}
};