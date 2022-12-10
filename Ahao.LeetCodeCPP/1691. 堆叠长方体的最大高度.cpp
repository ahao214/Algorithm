#include<vector>
#include <algorithm>

using namespace std;



/*
1691. 堆叠长方体的最大高度
给你 n 个长方体 cuboids ，其中第 i 个长方体的长宽高表示为 cuboids[i] = [widthi, lengthi, heighti]（下标从 0 开始）。请你从 cuboids 选出一个 子集 ，并将它们堆叠起来。

如果 widthi <= widthj 且 lengthi <= lengthj 且 heighti <= heightj ，你就可以将长方体 i 堆叠在长方体 j 上。你可以通过旋转把长方体的长宽高重新排列，以将它放在另一个长方体上。

返回 堆叠长方体 cuboids 可以得到的 最大高度 。
*/
class Solution {
public:
	int maxHeight(vector<vector<int>>& cuboids) {
		for (auto& x : cuboids)
			sort(x.begin(), x.end());
		sort(cuboids.begin(), cuboids.end(), greater<vector<int>>());
		int n = cuboids.size();
		vector<int> f(n);

		int res = 0;
		for (int i = 0; i < n; i++)
		{
			f[i] = cuboids[i][2];
			for (int j = 0; j < i; j++)
			{
				if (cuboids[j][0] >= cuboids[i][0] && cuboids[j][1] >= cuboids[i][1] && cuboids[j][2] >= cuboids[i][2])
					f[i] = max(f[i], f[j] + cuboids[i][2]);
			}
			res = max(res, f[i]);
		}
		return res;
	}
};






class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (auto& v : cuboids) {
            sort(v.begin(), v.end());
        }
        sort(cuboids.begin(), cuboids.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
            });
        int ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; j++) {
                if (cuboids[i][0] >= cuboids[j][0] &&
                    cuboids[i][1] >= cuboids[j][1] &&
                    cuboids[i][2] >= cuboids[j][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
