#include<string>

using namespace std;


/*
1768. ����ϲ��ַ���
���������ַ��� word1 �� word2 ������� word1 ��ʼ��ͨ�����������ĸ���ϲ��ַ��������һ���ַ�������һ���ַ��������ͽ����������ĸ׷�ӵ��ϲ����ַ�����ĩβ��

���� �ϲ�����ַ��� ��
*/
class Solution {
public:
	string mergeAlternately(string word1, string word2) {
		string res;
		int i = 0, j = 0;
		while (i < word1.size() || j < word2.size())
		{
			if (i < word1.size()) res += word1[i++];
			if (j < word2.size()) res += word2[j++];
		}
		return res;
	}
};



class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int i = 0, j = 0;

        string ans;
        ans.reserve(m + n);
        while (i < m || j < n) {
            if (i < m) {
                ans.push_back(word1[i]);
                ++i;
            }
            if (j < n) {
                ans.push_back(word2[j]);
                ++j;
            }
        }
        return ans;
    }
};
