#include<vector>
#include <string>

using namespace std;


/*
394. �ַ�������
����һ������������ַ������������������ַ�����

�������Ϊ: k[encoded_string]����ʾ���з������ڲ��� encoded_string �����ظ� k �Ρ�ע�� k ��֤Ϊ��������

�������Ϊ�����ַ���������Ч�ģ������ַ�����û�ж���Ŀո�������ķ��������Ƿ��ϸ�ʽҪ��ġ�

���⣬�������Ϊԭʼ���ݲ��������֣����е�����ֻ��ʾ�ظ��Ĵ��� k �����粻������� 3a �� 2[4] �����롣
*/
class Solution {
public:
	string decodeString(string s) {
		string res;
		for (int i = 0; i < s.size();)
		{
			if (!isdigit(s[i]))
			{
				res += s[i++];
			}
			else
			{
				int k = 0;
				while (isdigit(s[i])) k = k * 10 + s[i++] - '0';
				int j = i + 1, sum = 1;
				while (sum > 0)
				{
					if (s[j] == '[') sum++;
					if (s[j] == ']') sum--;
					j++;
				}
				string r = decodeString(s.substr(i + 1, j - i - 2));
				while (k--) res += r;
				i = j;
			}
		}
		return res;
	}
};