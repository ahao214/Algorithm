#include<vector>

using namespace std;


/*
1899. �ϲ�������Ԫ�����γ�Ŀ����Ԫ��
��Ԫ�� ��һ��������������ɵ����顣����һ����ά�������� triplets ������ triplets[i] = [ai, bi, ci] ��ʾ�� i �� ��Ԫ�� ��ͬʱ������һ���������� target = [x, y, z] ����ʾ����Ҫ�õ��� ��Ԫ�� ��

Ϊ�˵õ� target ������Ҫ�� triplets ִ������Ĳ��� ����Σ����� �� �Σ���

ѡ�������±꣨�±� �� 0 ��ʼ ������i �� j��i != j������ ���� triplets[j] Ϊ [max(ai, aj), max(bi, bj), max(ci, cj)] ��
���磬triplets[i] = [2, 5, 3] �� triplets[j] = [1, 7, 5]��triplets[j] �������Ϊ [max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5] ��
���ͨ�����ϲ������ǿ���ʹ��Ŀ�� ��Ԫ�� target ��Ϊ triplets ��һ�� Ԫ�� ���򷵻� true �����򣬷��� false ��
*/
class Solution {
public:
	bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
		int x = 0, y = 0, z = 0;
		for (auto& t : triplets)
		{
			if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;
			x = max(x, t[0]), y = max(y, t[1]), z = max(z, t[2]);
		}
		return x == target[0] && y == target[1] && z == target[2];
	}

};
