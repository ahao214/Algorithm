#include<vector>
#include<string>

using namespace std;



/*
1638. ͳ��ֻ��һ���ַ����Ӵ���Ŀ

���������ַ��� s �� t �������ҳ� s �еķǿ��Ӵ�����Ŀ����Щ�Ӵ������滻 һ����ͬ�ַ� �Ժ��� t �����Ӵ�������֮�������ҵ� s �� t ���� ǡ�� ֻ��һ���ַ���ͬ�����ַ����Ե���Ŀ��

�ȷ�˵�� "computer" and "computation" ֻ��һ���ַ���ͬ�� 'e'/'a' ��������һ�����ַ�������𰸼� 1 ��

���㷵���������������Ĳ�ͬ���ַ�������Ŀ��

һ�� ���ַ��� ��һ���ַ������������ַ���
*/
class Solution {
	int dp1[105][105];
	int dp2[105][105];
public:
	int countSubstrings(string s, string t) {
		int m = s.size();
		int n = t.size();
		s = "#" + s + "#";
		t = "#" + t + "#";

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				if (s[i] == t[j])
					dp1[i][j] = dp1[i - 1][j - 1] + 1;
				else
					dp1[i][j] = 0;
			}

		for (int i = m; i >= 1; i--)
			for (int j = n; j >= 1; j--)
			{
				if (s[i] == t[j])
					dp2[i][j] = dp2[i + 1][j + 1] + 1;
				else
					dp2[i][j] = 0;
			}

		int res = 0;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (s[i] != t[j])
					res += (dp1[i - 1][j - 1] + 1) * (dp2[i + 1][j + 1] + 1);
			}
		}
		return res;
	}
};


class Solution {
public:
	int countSubstrings(string s, string t) {
		int m = s.size(), n = t.size();
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int diff = 0;
				for (int k = 0; i + k < m && j + k < n; k++) {
					diff += s[i + k] == t[j + k] ? 0 : 1;
					if (diff > 1) {
						break;
					}
					else if (diff == 1) {
						ans++;
					}
				}
			}
		}
		return ans;
	}
};

