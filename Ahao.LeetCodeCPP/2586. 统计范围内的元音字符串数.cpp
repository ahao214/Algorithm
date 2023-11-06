#include<vector>
#include<string>

using namespace std;

/*
2586. ͳ�Ʒ�Χ�ڵ�Ԫ���ַ�����

����һ���±�� 0 ��ʼ���ַ������� words ������������left �� right ��

����ַ�����Ԫ����ĸ��ͷ����Ԫ����ĸ��β����ô���ַ�������һ�� Ԫ���ַ��� ������Ԫ����ĸ�� 'a'��'e'��'i'��'o'��'u' ��

���� words[i] ��Ԫ���ַ�������Ŀ������ i �ڱ����� [left, right] �ڡ�
*/

class Solution {
public:
	int vowelStrings(vector<string>& words, int left, int right) {
		const string vowel = "aeiou";
		int ans = 0;
		for (int i = left; i <= right; i++) {
			string& s = words[i];
			ans += vowel.find(s[0]) != string::npos &&
				vowel.find(s.back()) != string::npos;
		}
		return ans;
	}
};
