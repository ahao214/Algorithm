using namespace std;

#include<vector>
#include<string>

class Solution {
	/*
	3. ���ظ��ַ�����Ӵ�
	����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
	*/
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> pos(128, -1);
		int ans = 0;
		for (int i = 0, j = 0; i < s.length(); i++) {
			j = max(j, pos[s[i]] + 1);
			ans = max(ans, i - j + 1);
			pos[s[i]] = i;
		}
		return ans;
	}
};