#include<vector>
#include<string>

using namespace std;


/*
offer 46 °ÑÊý×Ö·­Òë³É×Ö·û´®
*/
class Solution {
public:
	int solve(int num) {
		string str = to_string(num);
		int len = str.size();
		if (len < 2) return len;
		vector<int> dp(len + 1);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= len; ++i)
		{
			if (str[i - 2] == '1' || (str[i - 2] == '2' && str[i - 1] <= '5'))
				dp[i] = dp[i - 1] + dp[i - 2];
			else
				dp[i] = dp[i - 1];
		}
		return dp[len];
	}
};
