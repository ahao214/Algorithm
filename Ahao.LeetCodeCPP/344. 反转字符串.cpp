#include<string>
#include<vector>

using namespace std;

/*
344. ��ת�ַ���

��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������

��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
*/

class Solution {
public:
	void reverseString(vector<char>& s) {
		int n = s.size();
		for (int left = 0, right = n - 1; left < right; ++left, --right) {
			swap(s[left], s[right]);
		}
	}
};
