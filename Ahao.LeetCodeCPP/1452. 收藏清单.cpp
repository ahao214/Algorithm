#include<vector>
#include<string>
#include <algorithm>

using namespace std;



/*
1452. 收藏清单
给你一个数组 favoriteCompanies ，其中 favoriteCompanies[i] 是第 i 名用户收藏的公司清单（下标从 0 开始）。

请找出不是其他任何人收藏的公司清单的子集的收藏清单，并返回该清单下标。下标需要按升序排列。
*/
class Solution {
public:
	vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
		int n = favoriteCompanies.size();
		for (auto& l : favoriteCompanies) sort(l.begin(), l.end());

		vector<int> res;
		for (int i = 0; i < n; i++)
		{
			bool is_subset = false;
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					auto& A = favoriteCompanies[i], & B = favoriteCompanies[j];
					int a = 0;
					for (int b = 0; b < B.size() && a < A.size(); b++)
						if (A[a] == B[b])
							a++;

					if (a == A.size())
					{
						is_subset = true;
						break;
					}
				}
			}
			if (!is_subset)
				res.push_back(i);
		}
		return res;
	}
};