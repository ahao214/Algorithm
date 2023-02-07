#include<vector>
#include <string>

using namespace std;


/*
1233. ɾ�����ļ���

����һλϵͳ����Ա��������һ���ļ����б� folder�����������Ҫɾ�����б��е����� ���ļ��У����� ����˳�� ����ʣ�µ��ļ��С�

����ļ��� folder[i] λ����һ���ļ��� folder[j] �£���ô folder[i] ���� folder[j] �� ���ļ��� ��

�ļ��еġ�·��������һ�����������¸�ʽ�����γɵ��ַ�����'/' ���һ�����߶��СдӢ����ĸ��

���磬"/leetcode" �� "/leetcode/problems" ������Ч��·���������ַ����� "/" ���ǡ�
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
