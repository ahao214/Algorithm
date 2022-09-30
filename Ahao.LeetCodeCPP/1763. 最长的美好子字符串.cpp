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

