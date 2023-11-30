#include<vector>
#include<string>
#include <algorithm>

using namespace std;

/*
1657. ȷ�������ַ����Ƿ�ӽ�

�������ʹ�����²�����һ���ַ����õ���һ���ַ���������Ϊ�����ַ��� �ӽ� ��

���� 1�������������� ���� �ַ���
���磬abcde -> aecdb
���� 2����һ�� ���� �ַ���ÿ�γ���ת��Ϊ��һ�� ���� �ַ���������һ���ַ�ִ����ͬ�Ĳ�����
���磬aacabb -> bbcbaa������ a ת��Ϊ b �������е� b ת��Ϊ a ��
����Ը�����Ҫ������һ���ַ������ʹ�������ֲ�����

���������ַ�����word1 �� word2 ����� word1 �� word2 �ӽ� ���ͷ��� true �����򣬷��� false ��
*/


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> count1(26), count2(26);
        for (char c : word1) {
            count1[c - 'a']++;
        }
        for (char c : word2) {
            count2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count1[i] > 0 && count2[i] == 0 || count1[i] == 0 && count2[i] > 0) {
                return false;
            }
        }
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());
        return count1 == count2;
    }
};
