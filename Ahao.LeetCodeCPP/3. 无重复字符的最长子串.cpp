using namespace std;

#include<vector>
#include<string>
#include <unordered_map>

/*
3. ���ظ��ַ�����Ӵ�
����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
*/
class Solution {
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



/*
3. ���ظ��ַ�����Ӵ�
����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> hash;
		int res = 0;
		for (int i = 0, j = 0; j < s.size(); j++)
		{
			if (++hash[s[j]] > 1)
			{
				while (i < j)
				{
					hash[s[i]]--;
					i++;
					if (hash[s[j]] == 1)
						break;
				}
			}
			res = max(res, j - i + 1);
		}
		return res;
	}
};