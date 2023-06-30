#include<vector>
#include<string>
#include<unordered_set>

using namespace std;


/*
472. Á¬½Ó´Ê
*/
class Solution {
public:
	unordered_set<string> hash;

	bool check(string& word)
	{
		int n = word.size();
		vector<int> f(n + 1, INT_MIN);
		f[0] = 0;
		for (int i = 0; i <= n; i++)
		{
			if (f[i] < 0) continue;
			for (int j = n - i; j; j--)
			{
				if (hash.count(word.substr(i, j)))
				{
					f[i + j] = max(f[i + j], f[i] + 1);
					if (f[n] > 1) return true;
				}
			}
		}
		return f[n] > 1;
	}

	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		for (auto& word : words)
			hash.insert(word);
		vector<string> res;
		for (auto& word : words)
		{
			if (check(word))
				res.push_back(word);
		}
		return res;
	}
};