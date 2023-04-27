#include<vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
1048. ��ַ�����

����һ���������� words ������ÿ�����ʶ���СдӢ����ĸ��ɡ�

������ǿ��� ���ı������ַ���˳�� ���� wordA ���κεط���� ǡ��һ�� ��ĸʹ���� wordB ����ô������Ϊ wordA �� wordB �� ǰ�� ��

���磬"abc" �� "abac" �� ǰ�� ���� "cba" ���� "bcad" �� ǰ��
�����ǵ��� [word_1, word_2, ..., word_k] ��ɵ����У�k >= 1������ word1 �� word2 ��ǰ��word2 �� word3 ��ǰ���������ơ�һ������ͨ���� k == 1 �� ������ ��

�Ӹ��������б� words ��ѡ�񵥴���ɴ��������� ������ ����ܳ��� ��


ʾ�� 1��

���룺words = ["a","b","ba","bca","bda","bdca"]
�����4
���ͣ��������֮һΪ ["a","ba","bda","bdca"]
ʾ�� 2:

���룺words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
�����5
���ͣ����еĵ��ʶ����Է��뵥���� ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
ʾ�� 3:

���룺words = ["abcd","dbqca"]
�����1
���ͣ�����["abcd"]���������֮һ��
["abcd"��"dbqca"]����һ����Ч�ĵ���������Ϊ��ĸ��˳�򱻸ı��ˡ�


��ʾ��

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] ����СдӢ����ĸ��ɡ�
*/



class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> cnt;
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
            });
        int res = 0;
        for (string word : words) {
            cnt[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (cnt.count(prev)) {
                    cnt[word] = max(cnt[word], cnt[prev] + 1);
                }
            }
            res = max(res, cnt[word]);
        }
        return res;
    }
};
