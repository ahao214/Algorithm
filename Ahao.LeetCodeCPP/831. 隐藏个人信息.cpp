#include<vector>
#include <string>

using namespace std;


/*
831. ���ظ�����Ϣ

����һ��������Ϣ�ַ��� s �����ܱ�ʾһ�� �����ַ ��Ҳ���ܱ�ʾһ�� �绰���� �����ذ����¹��� ���� ������Ϣ��Ľ����

�����ʼ���ַ��

һ�������ʼ���ַ�����²�����ɣ�

һ�� ���� ���ɴ�СдӢ����ĸ��ɣ��������
һ�� '@' �ַ����������
һ�� ���� ���ɴ�СдӢ����ĸ��һ��λ���м�� '.' �ַ���ɡ�'.' �����������ĵ�һ���������һ���ַ���
Ҫ�����ص����ʼ���ַ�еĸ�����Ϣ��

���� �� ���� ���ֵĴ�дӢ����ĸӦ��ת����СдӢ����ĸ��
���� �м����ĸ����������һ�������һ����ĸ�⣩������ 5 �� "*****" �滻��
�绰���룺

һ���绰����Ӧ����������ʽ��ɣ�

�绰��������� 10-13 λ�������
�� 10 λ���� ���غ���
ǰ��ʣ�µ� 0-3 λ������ ���Ҵ���
���� {'+', '-', '(', ')', ' '} ��Щ �ָ��ַ� ��ĳ����ʽ���������ֽ��зָ�
Ҫ�����ص绰�����еĸ�����Ϣ��

�Ƴ����� �ָ��ַ�
���ظ�����Ϣ��ĵ绰����Ӧ��������ָ�ʽ��
"***-***-XXXX" ������Ҵ���Ϊ 0 λ����
"+*-***-***-XXXX" ������Ҵ���Ϊ 1 λ����
"+**-***-***-XXXX" ������Ҵ���Ϊ 2 λ����
"+***-***-***-XXXX" ������Ҵ���Ϊ 3 λ����
"XXXX" ����� 4 λ ���غ���
*/


class Solution {
public:
	string workEmail(string t)
	{
		string s;
		for (auto c : t)
			s += tolower(c);
		int a = s.find('@'), b = s.find('.');
		string name1 = s.substr(0, a);
		string name2 = s.substr(a + 1, b - a - 1);
		string name3 = s.substr(b + 1);
		return name1[0] + string(5, '*') + name1.back() + '@' + name2 + '.' + name3;
	}

	string workPhone(string t)
	{
		string s;
		for (auto c : t)
		{
			if (isdigit(c))
				s += c;
		}
		if (s.size() == 10)
			return "***-***-" + s.substr(6);
		return "+" + string(s.size() - 10, '*') + "-***-***-" + s.substr(s.size() - 4);
	}

	string maskPII(string s) {
		if (s.find('@') != -1)
			return workEmail(s);
		else
			return workPhone(s);
	}
};


class Solution {
public:
	vector<string> country = { "", "+*-", "+**-", "+***-" };

	string maskPII(string s) {
		string res;
		int at = s.find("@");
		if (at != string::npos) {
			transform(s.begin(), s.end(), s.begin(), ::tolower);
			return s.substr(0, 1) + "*****" + s.substr(at - 1);
		}
		s = regex_replace(s, regex("[^0-9]"), "");
		return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);
	}
};

