#include<vector>
#include <string>
#include <set>

using namespace std;

/*
820. ���ʵ�ѹ������

�������� words �� ��Ч���� �����������ַ��� s ���±����� indices ��ɣ������㣺

words.length == indices.length
�����ַ��� s �� '#' �ַ���β
����ÿ���±� indices[i] ��s ��һ���� indices[i] ��ʼ������һ�� '#' �ַ��������������� '#'���� ���ַ��� ǡ���� words[i] ���
����һ���������� words �����سɹ��� words ���б������С�����ַ��� s �ĳ��� ��
*/
class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		set<string> st(words.begin(), words.end());
		for (auto& word : words)
		{
			for (int k = 1; k < word.size(); k++)
				st.erase(word.substr(k));
		}
		int res = 0;
		for (auto& word : st)
			res += word.size() + 1;
		return res;
	}
};

