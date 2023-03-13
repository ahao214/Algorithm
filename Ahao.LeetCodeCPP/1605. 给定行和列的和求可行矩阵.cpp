#include<vector>

using namespace std;


/*
1605. �����к��еĺ�����о���

���������Ǹ��������� rowSum �� colSum ������ rowSum[i] �Ƕ�ά�����е� i ��Ԫ�صĺͣ� colSum[j] �ǵ� j ��Ԫ�صĺ͡�����֮�㲻֪���������ÿ��Ԫ�أ�������֪��ÿһ�к�ÿһ�еĺ͡�

���ҵ���СΪ rowSum.length x colSum.length ������ �Ǹ����� �����Ҹþ������� rowSum �� colSum ��Ҫ��

���㷵������һ��������ĿҪ��Ķ�ά������Ŀ��֤���� ����һ�� ���о���
*/
class Solution {
	/*
	k k k a
	k k k b
	k k k c
	x y z

	[a,b,c]��ʾ�еĺ�
	[x,y,z]��ʾ�еĺ�

	resΪ�������
	res[0][0] = min(x,a)
	res[0][1] = min(y,a - res[0][0])
	res[0][2] = a - res[0][0] - res[0][1] = min(z,a - res[0][0] - res[0][1])
	*/
public:
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		int m = rowSum.size();
		int n = colSum.size();
		auto res = vector<vector<int>>(m, vector<int>(n));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int v = min(rowSum[i], colSum[j]);
				res[i][j] = v;
				rowSum[i] -= v;
				colSum[j] -= v;
			}
		}
		return res;
	}
};



class Solution {
public:
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		int n = rowSum.size(), m = colSum.size();
		vector<vector<int>> matrix(n, vector<int>(m, 0));
		int i = 0, j = 0;
		while (i < n && j < m) {
			int v = min(rowSum[i], colSum[j]);
			matrix[i][j] = v;
			rowSum[i] -= v;
			colSum[j] -= v;
			if (rowSum[i] == 0) {
				++i;
			}
			if (colSum[j] == 0) {
				++j;
			}
		}
		return matrix;
	}
};
