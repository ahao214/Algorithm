#include<vector>
#include<string>

using namespace std;


/*
902. ���Ϊ N ���������
����һ���� �ǵݼ�˳�� ���е��������� digits ���������������� digits[i] ��д�����֡����磬��� digits = ['1','3','5']�����ǿ���д���֣��� '13', '551', �� '1351315'��

���� �������ɵ�С�ڻ���ڸ������� n ���������ĸ��� ��
*/

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int m = digits.size(), k = s.size();
        vector<vector<int>> dp(k + 1, vector<int>(2));
        dp[0][1] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < m; j++) {
                if (digits[j][0] == s[i - 1]) {
                    dp[i][1] = dp[i - 1][1];
                }
                else if (digits[j][0] < s[i - 1]) {
                    dp[i][0] += dp[i - 1][1];
                }
                else {
                    break;
                }
            }
            if (i > 1) {
                dp[i][0] += m + dp[i - 1][0] * m;
            }
        }
        return dp[k][0] + dp[k][1];
    }
};
