#include<vector>
#include<string>

using namespace std;


/*
1513. ���� 1 ���Ӵ���
����һ���������ַ��� s������ '0' �� '1' ��ɵ��ַ�������

���������ַ���Ϊ 1 �����ַ�������Ŀ��

���ڴ𰸿��ܴܺ����㽫���� 10^9 + 7 ȡģ�󷵻ء�
*/
class Solution {
public:
	/*
	���ÿһ����1�ĸ���(x)����һ����1�ĸ�����x*(x+1)/2
	����0֮����Ϊһ�Σ�ʹ��˫ָ��
	*/
	int numSub(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != '0')
			{
				int j = i + 1;
				while (j < s.size() && s[j] == '1')
					j++;
				int x = j - i;
				res = (res + x * (x + 1ll) / 2) % 1000000007;
				i = j - 1;
			}
		}
		return res;
	}
};