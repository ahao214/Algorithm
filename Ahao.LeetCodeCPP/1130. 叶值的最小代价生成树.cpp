#include<vector>

using namespace std;

/*
1130. Ҷֵ����С����������

����һ������������ arr�����������������������Ķ�������

ÿ���ڵ㶼�� 0 ������ 2 ���ӽڵ㡣
���� arr �е�ֵ���������������ÿ��Ҷ�ڵ��ֵһһ��Ӧ��
ÿ����Ҷ�ڵ��ֵ����������������������Ҷ�ڵ�����ֵ�ĳ˻���
�����������Ķ������У�����ÿ����Ҷ�ڵ��ֵ����С�����ܺ͡�����͵�ֵ��һ�� 32 λ������

���һ���ڵ��� 0 ���ӽڵ㣬��ô�ýڵ�ΪҶ�ڵ㡣
*/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 4)), mval(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            mval[j][j] = arr[j];
            dp[j][j] = 0;
            for (int i = j - 1; i >= 0; i--) {
                mval[i][j] = max(arr[i], mval[i + 1][j]);
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mval[i][k] * mval[k + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
