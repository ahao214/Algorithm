#include<vector>

using namespace std;

/*
1223. ������ģ��

��һ������ģ������ÿ��Ͷ����ʱ������һ�� 1 �� 6 ���������

����������ʹ����ʱ�и�Լ��������ʹ��Ͷ������ʱ������ �������� i �Ĵ������ܳ��� rollMax[i]��i �� 1 ��ʼ��ţ���

���ڣ�����һ���������� rollMax ��һ������ n�������������� n �����ӿɵõ��Ĳ�ͬ�������е�������

�����������������ٴ���һ��Ԫ�ز�ͬ������Ϊ�����������ǲ�ͬ�ġ����ڴ𰸿��ܴܺ������뷵�� ģ 10^9 + 7 ֮��Ľ����

ʾ�� 1��

���룺n = 2, rollMax = [1,1,2,2,2,3]
�����34
���ͣ������� 2 �����ӣ����û��Լ���Ļ������� 6 * 6 = 36 �ֿ��ܵ���ϡ����Ǹ��� rollMax ���飬���� 1 �� 2 �����������һ�Σ����Բ���������� (1,1) �� (2,2)����ˣ����մ��� 36-2 = 34��
ʾ�� 2��

���룺n = 2, rollMax = [1,1,1,1,1,1]
�����30
ʾ�� 3��

���룺n = 3, rollMax = [1,1,1,2,2,3]
�����181


��ʾ��

1 <= n <= 5000
rollMax.length == 6
1 <= rollMax[i] <= 15
*/

class Solution {
public:
    static constexpr int mod = 1E9 + 7;
    int dieSimulator(int n, vector<int>& rollMax) {
        vector d(n + 1, vector(6, vector<int>(16)));
        for (int j = 0; j < 6; j++) {
            d[1][j][1] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 1; k <= rollMax[j]; k++) {
                    for (int p = 0; p < 6; p++) {
                        if (p != j) {
                            d[i][p][1] = (d[i][p][1] + d[i - 1][j][k]) % mod;
                        }
                        else if (k + 1 <= rollMax[j]) {
                            d[i][p][k + 1] = (d[i][p][k + 1] + d[i - 1][j][k]) % mod;
                        }
                    }
                }
            }
        }

        int res = 0;
        for (int j = 0; j < 6; j++) {
            for (int k = 1; k <= rollMax[j]; k++) {
                res = (res + d[n][j][k]) % mod;
            }
        }
        return res;
    }
};