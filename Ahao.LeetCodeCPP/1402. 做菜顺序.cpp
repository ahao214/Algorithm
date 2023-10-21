#include<vector>
#include<string>
#include <algorithm>

using namespace std;

/*
1402. ����˳��

һ����ʦ�ռ����� n ���˵�����̶� satisfaction �������ʦ����ÿ���˵�ʱ�䶼�� 1 ��λʱ�䡣

һ���˵� �� like-time ϵ�� ������Ϊ�������˽�����ʱ�䣨����֮ǰÿ���������ѵ�ʱ�䣩��������˵�����̶ȣ�Ҳ���� time[i]*satisfaction[i] ��

���س�ʦ��׼����һ�������Ĳ��Ⱥ���Ի�õ���� like-time ϵ�� �ܺ͡�

����԰� ���� ˳�������˵�˳����Ҳ����ѡ�������ĳЩ������ø�����ܺ͡�
*/


class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        sort(satisfaction.begin(), satisfaction.end());
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i - 1][j - 1] + satisfaction[i - 1] * j;
                if (j < i) {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};


class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int presum = 0, ans = 0;
        for (int si : satisfaction) {
            if (presum + si > 0) {
                presum += si;
                ans += presum;
            }
            else {
                break;
            }
        }
        return ans;
    }
};

