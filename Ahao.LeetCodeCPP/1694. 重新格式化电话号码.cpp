#include<string>

using namespace std;


/*
1694. ���¸�ʽ���绰����
����һ���ַ�����ʽ�ĵ绰���� number ��number �����֡��ո� ' '�������ۺ� '-' ��ɡ�

���㰴������ʽ���¸�ʽ���绰���롣

���ȣ�ɾ�� ���еĿո�����ۺš�
��Σ������������ ÿ 3 ��һ�� �ֿ飬ֱ�� ʣ�� 4 ����������֡�ʣ�µ����ֽ��������涨�ٷֿ飺
2 �����֣������� 2 �����ֵĿ顣
3 �����֣������� 3 �����ֵĿ顣
4 �����֣������ֱ� 2 �����ֵĿ顣
��������ۺŽ���Щ������������ע�⣬���¸�ʽ�������� ��Ӧ�� ���ɽ��� 1 �����ֵĿ飬���� ��� ���������� 2 �����ֵĿ顣

���ظ�ʽ����ĵ绰���롣
*/

class Solution {
public:
	string reformatNumber(string number) {
		string digits;
		for (char ch : number) {
			if (isdigit(ch)) {
				digits.push_back(ch);
			}
		}

		int n = digits.size();
		int pt = 0;
		string ans;
		while (n) {
			if (n > 4) {
				ans += digits.substr(pt, 3) + "-";
				pt += 3;
				n -= 3;
			}
			else {
				if (n == 4) {
					ans += digits.substr(pt, 2) + "-" + digits.substr(pt + 2, 2);
				}
				else {
					ans += digits.substr(pt, n);
				}
				break;
			}
		}
		return ans;
	}
};




/*
1694. ���¸�ʽ���绰����
����һ���ַ�����ʽ�ĵ绰���� number ��number �����֡��ո� ' '�������ۺ� '-' ��ɡ�

���㰴������ʽ���¸�ʽ���绰���롣

���ȣ�ɾ�� ���еĿո�����ۺš�
��Σ������������ ÿ 3 ��һ�� �ֿ飬ֱ�� ʣ�� 4 ����������֡�ʣ�µ����ֽ��������涨�ٷֿ飺
2 �����֣������� 2 �����ֵĿ顣
3 �����֣������� 3 �����ֵĿ顣
4 �����֣������ֱ� 2 �����ֵĿ顣
��������ۺŽ���Щ������������ע�⣬���¸�ʽ�������� ��Ӧ�� ���ɽ��� 1 �����ֵĿ飬���� ��� ���������� 2 �����ֵĿ顣

���ظ�ʽ����ĵ绰���롣
*/
class Solution {
public:
	string reformatNumber(string number) {
		string s;
		//ɾ���ո�ͺ���
		for (auto c : number)
			if (c != ' ' && c != '-')
				s += c;

		string res;
		for (int i = 0; i < s.size();)
		{
			if (s.size() - i > 4)
			{
				res += s.substr(i, 3);
				i += 3;
			}
			else
			{
				int k = s.size() - i;
				if (k <= 3) res += s.substr(i, k);
				else res += s.substr(i, 2) + '-' + s.substr(i + 2);
				i += 4;
			}
			res += '-';
		}
		res.pop_back();
		return res;
	}
};
