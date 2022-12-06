using namespace std;
#include<string>

/*
38. �������
����һ�������� n �����������еĵ� n �
��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������
*/
class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) return "1";
		string s = countAndSay(n - 1), ans;
		for (int i = 0, j = 0; i < s.length(); i++) {
			while (j < s.length() && s[i] == s[j]) j++;
			ans += to_string(j - i) + s[i];
			i = j - 1;
		}
		return ans;
	}
};


/*
38. �������
����һ�������� n �����������еĵ� n �

��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������

����Խ����������ɵݹ鹫ʽ����������ַ������У�

countAndSay(1) = "1"
countAndSay(n) �Ƕ� countAndSay(n-1) ��������Ȼ��ת������һ�������ַ�����
*/
class Solution {
public:
	string countAndSay(int n) {
		string s = "1";
		for (int i = 0; i < n - 1; i++)
		{
			string ns;
			//����������
			for (int j = 0; j < s.size(); j++)
			{
				int k = j;
				while (k < s.size() && s[k] == s[j]) k++;
				ns += to_string(k - j) + s[j];
				j = k - 1;
			}
			s = ns;
		}
		return s;
	}
};


