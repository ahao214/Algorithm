#include<vector>

using namespace std;


/*
186.��ת�ַ����еĵ���(��)

*/

class Solution {
public:
	void reverseWords(vector<char>& s) {
		int n = s.size();
		//��ÿ�����ʽ��з�ת
		for (int i = 0, j = 0; i <= n; i++)
		{
			if (i == n || s[i] == ' ')
			{
				reverse(s.begin() + j, s.begin() + i);
				j = i + 1;
			}
		}
		reverse(s.begin(), s.end());
	}
}