#include<vector>
#include <string>

using namespace std;


/*
1023. 驼峰式匹配

如果我们可以将小写字母插入模式串 pattern 得到待查询项 query，那么待查询项与给定模式串匹配。（我们可以在任何位置插入每个字符，也可以插入 0 个字符。）

给定待查询列表 queries，和模式串 pattern，返回由布尔值组成的答案列表 answer。只有在待查项 queries[i] 与模式串 pattern 匹配时， answer[i] 才为 true，否则为 false。
*/
class Solution {
public:
	bool check(string& a, string& b)
	{
		int j = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (j < b.size() && a[i] == b[j]) j++;
			else if (a[i] < 'a') return false;
		}
		return j == b.size();
	}

	vector<bool> camelMatch(vector<string>& queries, string pattern) {
		vector<bool> res;
		for (auto& q : queries)
			res.push_back(check(q, pattern));
		return res;
	}
};



class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> res(n, true);
        for (int i = 0; i < n; i++) {
            int p = 0;
            for (auto c : queries[i]) {
                if (p < pattern.size() && pattern[p] == c) {
                    p++;
                }
                else if (isupper(c)) {
                    res[i] = false;
                    break;
                }
            }
            if (p < pattern.size()) {
                res[i] = false;
            }
        }
        return res;
    }
};
