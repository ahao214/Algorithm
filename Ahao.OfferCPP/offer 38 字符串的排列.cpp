#include<vector>
#include<string>

using namespace std;


/*
offer 38 ×Ö·û´®µÄÅÅÁĞ
*/
class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> ans;
		PermutationCore(str, ans, 0);
		return ans;
	}

	void PermutationCore(string& str, vector<string>& ans, int i)
	{
		if (i == str.size() - 1)
		{
			if (find(ans.begin(), ans.end(), str) == ans.end())
				ans.push_back(str);
		}
		else
		{
			for (int j = i; j < str.size(); ++j)
			{
				char tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
				PermutationCore(str, ans, i + 1);
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
	}
};