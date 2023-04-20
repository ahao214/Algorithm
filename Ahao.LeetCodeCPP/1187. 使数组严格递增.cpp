#include<vector>
#include <algorithm>

using namespace std;

/*
1187. ʹ�����ϸ����

���������������� arr1 �� arr2������ʹ arr1 �ϸ��������Ҫ����С����������������Ϊ 0����

ÿһ�����������У�����Էֱ�� arr1 �� arr2 �и�ѡ��һ���������ֱ�Ϊ i �� j��0 <= i < arr1.length �� 0 <= j < arr2.length��Ȼ����и�ֵ���� arr1[i] = arr2[j]��

����޷��� arr1 �ϸ�������뷵�� -1��
*/


constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int n = arr1.size();
        int m = arr2.size();
        vector<vector<int>> dp(n + 1, vector<int>(min(m, n) + 1, INF));
        dp[0][0] = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= min(i, m); j++) {
                /* �����ǰԪ�ش������е����һ��Ԫ�� */
                if (arr1[i - 1] > dp[i - 1][j]) {
                    dp[i][j] = arr1[i - 1];
                }
                if (j > 0 && dp[i - 1][j - 1] != INF) {
                    /* �����ϸ���� dp[i - 1][j - 1] ����СԪ�� */
                    auto it = upper_bound(arr2.begin() + j - 1, arr2.end(), dp[i - 1][j - 1]);
                    if (it != arr2.end()) {
                        dp[i][j] = min(dp[i][j], *it);
                    }
                }
                if (i == n && dp[i][j] != INF) {
                    return j;
                }
            }
        }
        return -1;
    }
};


constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        /* �Ҳ��ڱ� inf */
        arr1.push_back(INF);
        /* ����ڱ� -1 */
        arr1.insert(arr1.begin(), -1);
        int n = arr1.size();
        int m = arr2.size();

        vector<int> dp(n, INF);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            /* arr1[i] ����Ԫ�ز������滻 */
            if (arr1[i - 1] < arr1[i]) {
                dp[i] = min(dp[i], dp[i - 1]);
            }
            /* �滻 arr1[i] ��ߵ����� j ��Ԫ�� */
            for (int j = 1; j < i; j++) {
                /* arr2 �������滻�����Ϊ���� arr1[i - j - 1] ����СԪ�� */
                int k = upper_bound(arr2.begin(), arr2.end(), arr1[i - j - 1]) - arr2.begin();
                /* arr2 �������滻���յ��������С�� arr1[i] */
                if (k + j - 1 < m && arr2[k + j - 1] < arr1[i]) {
                    dp[i] = min(dp[i], dp[i - j - 1] + j);
                }
            }

        }
        return dp[n - 1] == INF ? -1 : dp[n - 1];
    }
};



constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        /* �Ҳ��ڱ� inf */
        arr1.push_back(INF);
        /* ����ڱ� -1 */
        arr1.insert(arr1.begin(), -1);
        int n = arr1.size();
        int m = arr2.size();

        vector<int> dp(n, INF);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            /* arr1[i] ����Ԫ�ز������滻 */
            if (arr1[i - 1] < arr1[i]) {
                dp[i] = min(dp[i], dp[i - 1]);
            }
            /* �̶��滻Ԫ�ص��Ҳ��յ� */
            int k = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            /* ö�ٴ� i ��������滻Ԫ�صĸ��� */
            for (int j = 1; j <= min(i - 1, k); ++j) {
                /* �滻������ j ��Ԫ�ص���������������� arr1[i - j - 1] */
                if (arr1[i - j - 1] < arr2[k - j]) {
                    dp[i] = min(dp[i], dp[i - j - 1] + j);
                }
            }
        }
        return dp[n - 1] == INF ? -1 : dp[n - 1];
    }
};
