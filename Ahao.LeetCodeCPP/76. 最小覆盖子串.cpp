#include<string>
#include <unordered_map>

using namespace std;


class Solution {
	/*
	76. ��С�����Ӵ�
	����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ������ s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��
	*/
public:
	/*
	Times:O(n)
	Space:O(n)
	*/
	string minWindow(string s, string t) {
		unordered_map<char, int> hs, ht;
		for (int i = 0; i < t.length(); i++) ht[t[i]]++;

		string ans;
		for (int i = 0, j = 0, cnt = 0; i < s.length(); i++)
		{
			if (++hs[s[i]] <= ht[s[i]]) cnt++;
			while (hs[s[j]] > ht[s[j]]) hs[s[j++]]--;
			if (cnt == t.length())
			{
				if (ans.empty() || ans.length() > i - j + 1)
				{
					ans = s.substr(j, i - j + 1);
				}
			}
		}
		return ans;
	}
};