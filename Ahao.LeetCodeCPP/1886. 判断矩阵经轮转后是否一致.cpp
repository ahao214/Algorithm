#include<vector>


using namespace std;


/*
1886. �жϾ�����ת���Ƿ�һ��
����������СΪ n x n �Ķ����ƾ��� mat �� target ���� �� 90 ��˳ʱ����ת ���� mat �е�Ԫ�� ���ɴ� ������ܹ�ʹ mat �� target һ�£����� true �����򣬷��� false ��
*/
class Solution {
public:
	vector<vector<int>> rotate(vector<vector<int>> a)
	{
		auto b = a;
		int n = a.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0, k = n - 1; j < n; j++, k--)
				b[i][j] = a[k][i];
		}
		return b;
	}

	bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
		for (int i = 0; i < 4; i++)
		{
			mat = rotate(mat);
			if (mat == target)
				return true;
		}
		return false;
	}

};
