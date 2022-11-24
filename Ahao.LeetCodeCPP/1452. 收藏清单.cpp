#include<vector>
#include<string>
#include <algorithm>

using namespace std;



/*
1452. �ղ��嵥
����һ������ favoriteCompanies ������ favoriteCompanies[i] �ǵ� i ���û��ղصĹ�˾�嵥���±�� 0 ��ʼ����

���ҳ����������κ����ղصĹ�˾�嵥���Ӽ����ղ��嵥�������ظ��嵥�±ꡣ�±���Ҫ���������С�
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