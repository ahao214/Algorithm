using namespace std;
#include<string>


class Solution {
	/*
	38. �������
	����һ�������� n �����������еĵ� n �
	��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������
	*/
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

