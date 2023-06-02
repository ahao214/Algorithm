#include<vector>
#include<string>


using namespace std;


/*
2559. ͳ�Ʒ�Χ�ڵ�Ԫ���ַ�����

����һ���±�� 0 ��ʼ���ַ������� words �Լ�һ����ά�������� queries ��

ÿ����ѯ queries[i] = [li, ri] ��Ҫ������ͳ���� words ���±��� li �� ri ��Χ�ڣ����� ������ֵ��������Ԫ����ͷ�ͽ�β���ַ�������Ŀ��

����һ���������飬��������ĵ� i ��Ԫ�ض�Ӧ�� i ����ѯ�Ĵ𰸡�

ע�⣺Ԫ����ĸ�� 'a'��'e'��'i'��'o' �� 'u' ��
*/

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int prefixSums[n + 1];
        memset(prefixSums, 0, sizeof(prefixSums));
        for (int i = 0; i < n; i++) {
            int value = isVowelString(words[i]) ? 1 : 0;
            prefixSums[i + 1] = prefixSums[i] + value;
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0], end = queries[i][1];
            ans[i] = prefixSums[end + 1] - prefixSums[start];
        }
        return ans;
    }

    bool isVowelString(const string& word) {
        return isVowelLetter(word[0]) && isVowelLetter(word.back());
    }

    bool isVowelLetter(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

