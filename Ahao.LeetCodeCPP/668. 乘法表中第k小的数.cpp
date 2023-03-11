#include <algorithm>
using namespace std;


/*
668. �˷����е�kС����

����ÿһ���˶��� �˷������������ڳ˷����п����ҵ��� k С��������

�˷����Ǵ�СΪ m x n ��һ�������������� mat[i][j] == i * j���±�� 1 ��ʼ����

������������ m��n �� k�������ڴ�СΪ m x n �ĳ˷����У��ҳ������ص� k С�����֡�
*/


class Solution {
public:
	int findKthNumber(int m, int n, int k) {
		int left = 1, right = m * n;
		while (left < right) {
			int x = left + (right - left) / 2;
			int count = x / n * n;
			for (int i = x / n + 1; i <= m; ++i) {
				count += x / i;
			}
			if (count >= k) {
				right = x;
			}
			else {
				left = x + 1;
			}
		}
		return left;
	}
};





class Solution {
public:
	int get(int m, int n, int mid)
	{
		int res = 0;
		for (int i = 1; i <= n; i++)
			res += min(m, mid / i);
		return res;
	}
	int findKthNumber(int m, int n, int k) {
		int left = 1, right = m * n;
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (get(m, n, mid) >= k) right = mid;
			else left = mid + 1;
		}
		return right;
	}
};