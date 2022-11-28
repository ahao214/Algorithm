#include<string>
#include <unordered_map>

using namespace std;

/*
76. ��С�����Ӵ�
����һ���ַ���  s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ������ s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��

ע�⣺

���� t ���ظ��ַ�������Ѱ�ҵ����ַ����и��ַ��������벻���� t �и��ַ�������
��� s �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�
*/

class Solution {
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


class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> hash;
		for (auto c : t) hash[c]++;
		int cnt = hash.size();

		string res;
		for (int i = 0, j = 0, c = 0; i < s.size(); i++)
		{
			if (hash[s[i]] == 1) c++;
			hash[s[i]]--;
			while (hash[s[j]] < 0) hash[s[j++]]++;
			if (c == cnt)
			{
				if (res.empty() || res.size() > i - j + 1)
					res = s.substr(j, i - j + 1);
			}
		}
		return res;
	}
};
