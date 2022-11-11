#include<vector>
#include <algorithm>
#include<string>

using namespace std;


/*
1668. ����ظ����ַ���
����һ���ַ��� sequence ������ַ��� word �����ظ� k ���γɵ��ַ����� sequence ��һ�����ַ�������ô���� word �� �ظ�ֵΪ k ������ word �� ����ظ�ֵ �ǵ��� word �� sequence �������ظ�ֵ����� word ���� sequence ���Ӵ�����ô�ظ�ֵ k Ϊ 0 ��

����һ���ַ��� sequence �� word �����㷵�� ����ظ�ֵ k ��
*/

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), m = word.size();
        if (n < m) {
            return 0;
        }

        vector<int> f(n);
        for (int i = m - 1; i < n; ++i) {
            bool valid = true;
            for (int j = 0; j < m; ++j) {
                if (sequence[i - m + j + 1] != word[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                f[i] = (i == m - 1 ? 0 : f[i - m]) + 1;
            }
        }

        return *max_element(f.begin(), f.end());
    }
};





class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int res = 0;
        string s = word;
        while (s.size() <= sequence.size())
        {
            if (sequence.find(s) == -1)break;
            res++;
            s += word;
        }
        return res;
    }
};
