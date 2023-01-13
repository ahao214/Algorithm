#include<string>
#include<unordered_set>

using namespace std;



/*
1763. ����������ַ���
��һ���ַ��� s ������ÿһ����ĸ�Ĵ�д��Сд��ʽ ͬʱ ������ s �У��ͳ�����ַ��� s �� ���� �ַ������ȷ�˵��"abABB" �������ַ�������Ϊ 'A' �� 'a' ͬʱ�����ˣ��� 'B' �� 'b' Ҳͬʱ�����ˡ�Ȼ����"abA" ���������ַ�����Ϊ 'b' �����ˣ��� 'B' û�г��֡�

����һ���ַ��� s �����㷵�� s ��� �������ַ��� ������ж���𰸣����㷵�� ���� ���ֵ�һ��������������������ַ��������㷵��һ�����ַ�����
*/
class Solution {
public:
	bool check(string s)
	{
		unordered_set<char> hash;
		for (auto c : s)
			hash.insert(c);
		for (auto c : s)
			if (hash.count(c ^ 32) == 0)
				return false;
		return true;
	}
	string longestNiceSubstring(string s) {
		string res;
		for (int i = 0; i < s.size(); i++)
			for (int j = i; j < s.size(); j++)
			{
				string str = s.substr(i, j - i + 1);
				if (check(str) && res.size() < str.size())
					res = str;
			}
		return res;
	}
};




class Solution {
public:
	bool check(const string& s, int a, int b) {
		set<char> st;
		for (int i = a; i <= b; ++i) {
			st.insert(s[i]);
		}
		for (int i = a; i <= b; ++i) {
			char c = s[i];
			if (c <= 'z' && c >= 'a') {
				if (!st.count(c - 'a' + 'A')) return false;
			}
			else {
				if (!st.count(c - 'A' + 'a')) return false;
			}
		}
		return true;
	}
	string longestNiceSubstring(string s) {
		int n = s.size(), ml = 0, le = 0, ri = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (check(s, i, j)) {
					if (j - i > ml) {
						ml = j - i;
						le = i;
						ri = j;
					}
				}
			}
		}
		if (ml) {
			return s.substr(le, ri - le + 1);
		}
		else {
			return "";
		}
	}
};