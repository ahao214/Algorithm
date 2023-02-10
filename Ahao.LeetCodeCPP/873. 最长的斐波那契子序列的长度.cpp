#include<vector>
#include <unordered_map>

using namespace std;


/*
873. ���쳲����������еĳ���

������� X_1, X_2, ..., X_n ����������������˵���� 쳲�����ʽ �ģ�

n >= 3
�������� i + 2 <= n������ X_i + X_{i+1} = X_{i+2}
����һ���ϸ�����������������γ����� arr ���ҵ� arr �����쳲�����ʽ�������еĳ��ȡ����һ�������ڣ�����  0 ��

������һ�£��������Ǵ�ԭ���� arr �����������ģ����� arr ��ɾ������������Ԫ�أ�Ҳ���Բ�ɾ���������ı�����Ԫ�ص�˳�����磬 [3, 5, 8] �� [3, 4, 5, 6, 7, 8] ��һ�������У�
*/
class Solution {
public:
	int lenLongestFibSubseq(vector<int>& arr) {
		int n = arr.size();
		unordered_map<int, int> pos;
		for (int i = 0; i < n; i++)
			pos[arr[i]] = i;
		vector<vector<int>> f(n, vector<int>(n));
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				int x = arr[i] - arr[j];
				f[i][j] = 2;
				if (x < arr[j] && pos.count(x))
				{
					int k = pos[x];
					f[i][j] = max(f[i][j], f[j][k] + 1);
				}
				res = max(res, f[i][j]);
			}
		}
		if (res < 3) res = 0;
		return res;
	}
};
