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
