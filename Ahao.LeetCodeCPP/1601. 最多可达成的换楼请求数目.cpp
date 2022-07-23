#include<vector>

using namespace std;


/*
1601. 最多可达成的换楼请求数目
*/
class Solution {
public:
	bool check(int s, int n, vector<vector<int>>& requests)
	{
		int building[20];
		for (int i = 0; i < n; i++)
			building[i] = 0;

		int m = requests.size();
		for (int i = 0; i < m; i++)
		{
			if (((s >> i) & 1) == 1)
			{
				building[requests[i][0]]--;
				building[requests[i][1]]++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (building[i] != 0)
				return false;
		}
		return true;
	}

	int count(int s)
	{
		int res = 0;
		for (int i = 0; i < 32; i++)
		{
			if (((s >> i) & 1) == 1)
				res++;
		}
		return res;
	}

	int maximumRequests(int n, vector<vector<int>>& requests) {
		int m = requests.size();
		int res = 0;
		for (int i = 0; i < (1 << m); i++)
		{
			if (check(i, n, requests))
				res = max(res, count(i));
		}
		return res;
	}
};