#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


/*
offer 48 ������ظ��ַ������ַ���
*/
class Solution {
public:
	/**
	 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	 *
	 *
	 * @param s string�ַ���
	 * @return int����
	 */
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) return 0;
		unordered_map<char, int> um;
		int ans = -1;
		int l = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			auto itor = um.find(s[i]);
			if (itor == um.end())
			{
				um.insert(make_pair(s[i], i));
				l++;
			}
			else if (i - um[s[i]] > l)
			{
				um[s[i]] = i;
				l++;
			}
			else
			{
				l = i - um[s[i]];
				um[s[i]] = i;
			}
			ans = max(l, ans);
		}
		return ans;
	}
};
