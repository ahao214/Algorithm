#include<vector>
#include<string>

using namespace std;



/*
1717. ɾ�����ַ��������÷�
����һ���ַ��� s ���������� x �� y �������ִ���������ֲ�������Ρ�

ɾ�����ַ��� "ab" ���õ� x �֡�
�ȷ�˵���� "cabxbae" ɾ�� ab ���õ� "cxbae" ��
ɾ�����ַ���"ba" ���õ� y �֡�
�ȷ�˵���� "cabxbae" ɾ�� ba ���õ� "cabxe" ��
�뷵�ض� s �ַ���ִ������������ɴ��ܵõ������÷֡�
*/
class Solution {
public:
	int maximumGain(string s, int x, int y) {
		if (x < y)
		{
			swap(x, y);
			for (auto& c : s)
			{
				if (c == 'a') c = 'b';
				else if (c == 'b') c = 'a';
			}
		}

		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != 'a' && s[i] != 'b') continue;
			int j = i + 1;
			while (j < s.size() && (s[j] == 'a' || s[j] == 'b')) j++;
			int a = 0, b = 0, c = 0;
			for (int k = j - 1, t = 0; k >= i; k--)
			{
				if (s[k] == 'a')
				{
					a++;
					if (t)
					{
						c++;
						t--;
					}
				}
				else
				{
					b++;
					t++;
				}
			}
			res += c * x + (min(a, b) - c) * y;
			i = j - 1;
		}
		return res;
	}
};