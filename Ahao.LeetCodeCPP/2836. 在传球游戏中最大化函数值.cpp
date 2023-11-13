#include<vector>

using namespace std;


/*
2836. �ڴ�����Ϸ����󻯺���ֵ

����һ������Ϊ n �±�� 0 ��ʼ���������� receiver ��һ������ k ��

�ܹ��� n ����ң���� ��� ������ͬ����Ϊ [0, n - 1] �е���������Щ�����һ��������Ϸ��receiver[i] ��ʾ���Ϊ i ����һᴫ������Ϊ receiver[i] ����ҡ���ҿ��Դ�����Լ���Ҳ����˵ receiver[i] ���ܵ��� i ��

����Ҫ�� n �������ѡ��һ�������Ϊ��Ϸ��ʼʱΨһ�����������ң���ᱻ�� ǡ�� k �Ρ�

���ѡ����Ϊ x �������Ϊ��ʼ��ң����庯�� f(x) ��ʾ�ӱ��Ϊ x ����ҿ�ʼ��k �δ��������нӴ�������ҵı��֮ �� ���������Ҷ�δ����� �ۼӶ�� �����仰˵�� f(x) = x + receiver[x] + receiver[receiver[x]] + ... + receiver(k)[x] ��

�������ʱѡ��ʼ��� x ��Ŀ���� ��� f(x) ��

���㷵�غ����� ���ֵ ��

ע�⣺receiver ���ܺ����ظ�Ԫ�ء�
*/
using LL = long long;
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k)
    {
        int n = receiver.size();
        int M = ceil(log(k) / log(2));
        vector<vector<LL>>dp(n + 1, vector<LL>(M + 1));
        vector<vector<int>>pos(n + 1, vector<int>(M + 1));

        for (int i = 0; i < n; i++)
        {
            pos[i][0] = receiver[i];
            dp[i][0] = receiver[i];
        }

        for (int j = 1; j <= M; j++)
            for (int i = 0; i < n; i++)
            {
                pos[i][j] = pos[pos[i][j - 1]][j - 1];
                dp[i][j] = dp[i][j - 1] + dp[pos[i][j - 1]][j - 1];
            }

        vector<int>bits;
        for (int i = 0; i <= M; i++)
        {
            if ((k >> i) & 1)
                bits.push_back(i);
        }

        LL ret = 0;
        for (int i = 0; i < n; i++)
        {
            LL val = i;
            int cur = i;
            for (int j : bits)
            {
                val += dp[cur][j];
                cur = pos[cur][j];
            }
            ret = max(ret, val);
        }

        return ret;
    }
};


