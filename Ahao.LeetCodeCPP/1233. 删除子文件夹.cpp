#include<vector>
#include <string>

using namespace std;


/*
1233. 删除子文件夹

你是一位系统管理员，手里有一份文件夹列表 folder，你的任务是要删除该列表中的所有 子文件夹，并以 任意顺序 返回剩下的文件夹。

如果文件夹 folder[i] 位于另一个文件夹 folder[j] 下，那么 folder[i] 就是 folder[j] 的 子文件夹 。

文件夹的「路径」是由一个或多个按以下格式串联形成的字符串：'/' 后跟一个或者多个小写英文字母。

例如，"/leetcode" 和 "/leetcode/problems" 都是有效的路径，而空字符串和 "/" 不是。
*/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans = { folder[0] };
        for (int i = 1; i < folder.size(); ++i) {
            if (int pre = ans.end()[-1].size(); !(pre < folder[i].size() && ans.end()[-1] == folder[i].substr(0, pre) && folder[i][pre] == '/')) {
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};
