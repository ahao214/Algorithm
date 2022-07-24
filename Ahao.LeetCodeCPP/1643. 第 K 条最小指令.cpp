#include<vector>
#include<string>

using namespace std;


/*
1643. 第 K 条最小指令
*/
class Solution {
public:
	int comb(int n, int m)
	{
		long long cnt = 1;
		for (int i = 0; i < m; i++)
		{
			cnt *= n - i;
			cnt /= i + 1;
		}
		return cnt;
	}

	string kthSmallestPath(vector<int>& destination, int k) {
		int V = destination[0];
		int H = destination[1];
		int n = H + V;

		string res;
		for (int i = 0; i < n; i++)
		{
			if (H == 0)
			{
				res.push_back('V');
				V--;
				continue;
			}
			else if (V == 0)
			{
				res.push_back('H');
				H--;
				continue;
			}

			int c = comb(H - 1 + V, V);
			if (k <= c)
			{
				H--;
				res.push_back('H');
			}
			else
			{
				V--;
				k -= c;
				res.push_back('V');
			}
		}
		return res;
	}
};
