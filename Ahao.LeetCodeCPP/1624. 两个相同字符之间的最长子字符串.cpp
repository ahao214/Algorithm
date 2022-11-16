#include<string>
#include<vector>


using namespace std;

class Solution {
public:
	int maxLengthBetweenEqualCharacters(string s) {
		vector<int> firstIndex(26, -1);
		int maxLength = -1;
		for (int i = 0; i < s.size(); i++) {
			if (firstIndex[s[i] - 'a'] < 0) {
				firstIndex[s[i] - 'a'] = i;
			}
			else {
				maxLength = max(maxLength, i - firstIndex[s[i] - 'a'] - 1);
			}
		}
		return maxLength;
	}
};




/*
1624. ������ͬ�ַ�֮�������ַ���
����һ���ַ��� s�����㷵�� ������ͬ�ַ�֮�������ַ����ĳ��� �����㳤��ʱ�����������ַ���������������������ַ��������� -1 ��

���ַ��� ���ַ����е�һ�������ַ����С�
*/
class Solution {
public:
	int maxLengthBetweenEqualCharacters(string s) {
		int res = -1;
		for (char c = 'a'; c <= 'z'; c++)
		{
			int left = s.size(), right = 0;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == c)
				{
					left = min(left, i);
					right = max(right, i);
				}
			}
			res = max(res, right - left - 1);
		}
		return res;
	}
};
