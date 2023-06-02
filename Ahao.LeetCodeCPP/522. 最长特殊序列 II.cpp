#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        auto is_subseq = [](const string& s, const string& t) -> bool {
            int pt_s = 0, pt_t = 0;
            while (pt_s < s.size() && pt_t < t.size()) {
                if (s[pt_s] == t[pt_t]) {
                    ++pt_s;
                }
                ++pt_t;
            }
            return pt_s == s.size();
        };

        int n = strs.size();
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            bool check = true;
            for (int j = 0; j < n; ++j) {
                if (i != j && is_subseq(strs[i], strs[j])) {
                    check = false;
                    break;
                }
            }
            if (check) {
                ans = max(ans, static_cast<int>(strs[i].size()));
            }
        }
        return ans;
    }
};



/*
522. 最长特殊序列 II
*/
class Solution {
public:
    bool check(string& a, string& b)
    {
        int k = 0;
        for (auto c : b)
        {
            if (k < a.size() && c == a[k])
                k++;
        }
        return k == a.size();
    }

    int findLUSlength(vector<string>& strs) {
        int res = -1;
        for (int i = 0; i < strs.size(); i++)
        {
            bool isSub = false;
            for (int j = 0; j < strs.size(); j++)
            {
                if (i != j && check(strs[i], strs[j]))
                {
                    isSub = true;
                    break;
                }
            }
            if (!isSub)
                res = max(res, (int)strs[i].size());
        }
        return res;
    }
};