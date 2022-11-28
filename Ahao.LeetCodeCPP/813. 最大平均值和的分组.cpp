#include<vector>

using namespace std;

/*
813. ���ƽ��ֵ�͵ķ���

�������� nums ��һ������ k �����ǽ����������� nums �ֳ� ��� k �����ڵķǿ������� �� ���� ��ÿ���������ڵ�ƽ��ֵ���ܺ͹��ɡ�

ע�����Ǳ���ʹ�� nums �����е�ÿһ�������з��飬���ҷ�����һ����Ҫ��������

�����������ܵõ������ ���� �Ƕ��١�������� 10-6 �ڱ���Ϊ����ȷ�ġ�
*/

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<double> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = prefix[i] / i;
        }
        for (int j = 2; j <= k; j++) {
            for (int i = n; i >= j; i--) {
                for (int x = j - 1; x < i; x++) {
                    dp[i] = max(dp[i], dp[x] + (prefix[i] - prefix[x]) / (i - x));
                }
            }
        }
        return dp[n];
    }
};
