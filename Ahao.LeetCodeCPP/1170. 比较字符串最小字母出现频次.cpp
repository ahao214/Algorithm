#include<vector>
#include <string>

using namespace std;


/*
1170. �Ƚ��ַ�����С��ĸ����Ƶ��

����һ������ f(s)��ͳ�� s  �У����ֵ���Ƚϣ���С��ĸ�ĳ���Ƶ�� ������ s ��һ���ǿ��ַ�����

���磬�� s = "dcce"����ô f(s) = 2����Ϊ�ֵ�����С��ĸ�� "c"���������� 2 �Ρ�

���ڣ����������ַ����������� queries �ʹʻ�� words ������ÿ�β�ѯ queries[i] ����ͳ�� words ������ f(queries[i]) < f(W) �� �ʵ���Ŀ ��W ��ʾ�ʻ�� words �е�ÿ���ʡ�

���㷵��һ���������� answer ��Ϊ�𰸣�����ÿ�� answer[i] �ǵ� i �β�ѯ�Ľ����
*/


class Solution {
public:
    int f(string& s) {
        int cnt = 0;
        char ch = 'z';
        for (auto c : s) {
            if (c < ch) {
                ch = c;
                cnt = 1;
            }
            else if (c == ch) {
                cnt++;
            }
        }
        return cnt;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> count(12);
        for (auto& s : words) {
            count[f(s)]++;
        }
        for (int i = 9; i >= 1; i--) {
            count[i] += count[i + 1];
        }
        vector<int> res;
        for (auto& s : queries) {
            res.push_back(count[f(s) + 1]);
        }
        return res;
    }
};
