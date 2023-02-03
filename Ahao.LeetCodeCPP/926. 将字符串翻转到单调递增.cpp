#include<vector>
#include <string>

using namespace std;



/*
926. ���ַ�����ת����������

���һ���������ַ���������һЩ 0������û�� 0���������һЩ 1��Ҳ����û�� 1������ʽ��ɵģ���ô���ַ����� �������� �ġ�

����һ���������ַ��� s������Խ��κ� 0 ��תΪ 1 ���߽� 1 ��תΪ 0 ��

����ʹ s ������������С��ת������
*/
class Solution {
public:
	int minFlipsMonoIncr(string s) {
		int res = 0, num = 0;
		for (auto& c : s) {
			if (c == '1') {
				num++;
			}
			else {
				res = min(num, res + 1);
			}
		}
		return res;
	}
};




/*
926. ���ַ�����ת����������

���һ���������ַ���������һЩ 0������û�� 0���������һЩ 1��Ҳ����û�� 1������ʽ��ɵģ���ô���ַ����� �������� �ġ�

����һ���������ַ��� s������Խ��κ� 0 ��תΪ 1 ���߽� 1 ��תΪ 0 ��

����ʹ s ������������С��ת������
*/
class Solution {
public:
	int minFlipsMonoIncr(string s) {
		int n = s.size();
		vector<int> c(n + 1);
		for (int i = 1; i <= n; i++)
		{
			c[i] = c[i - 1] + s[i - 1] - '0';
		}
		int res = n - c[n];
		for (int i = 1; i <= n; i++)
			res = min(res, c[i] + n - i - (c[n] - c[i]));
		return res;
	}
};