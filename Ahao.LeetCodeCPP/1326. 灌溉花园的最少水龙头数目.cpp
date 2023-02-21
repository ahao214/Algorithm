#include<vector>
#include <numeric>
#include <algorithm>

using namespace std;

/*
1326. ��Ȼ�԰������ˮ��ͷ��Ŀ

�� x ������һ��һά�Ļ�԰����԰����Ϊ n���ӵ� 0 ��ʼ������ n ������

��԰���ܹ��� n + 1 ��ˮ��ͷ���ֱ�λ�� [0, 1, ..., n] ��

����һ������ n ��һ������Ϊ n + 1 ���������� ranges ������ ranges[i] ���±�� 0 ��ʼ����ʾ������򿪵� i ����ˮ��ͷ�����Թ�ȵ�����Ϊ [i -  ranges[i], i + ranges[i]] ��

���㷵�ؿ��Թ��������԰�� ����ˮ��ͷ��Ŀ �������԰ʼ�մ����޷���ȵ��ĵط������㷵�� -1 ��
*/


//��̬�滮
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals;
        for (int i = 0; i <= n; i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            intervals.emplace_back(start, end);
        }
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (auto [start, end] : intervals) {
            if (dp[start] == INT_MAX) {
                return -1;
            }
            for (int j = start; j <= end; j++) {
                dp[j] = min(dp[j], dp[start] + 1);
            }
        }
        return dp[n];
    }
};


// ̰���㷨
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> rightMost(n + 1);
        iota(rightMost.begin(), rightMost.end(), 0);
        for (int i = 0; i <= n; i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            rightMost[start] = max(rightMost[start], end);
        }
        int last = 0, ret = 0, pre = 0;
        for (int i = 0; i < n; i++) {
            last = max(last, rightMost[i]);
            if (i == last) {
                return -1;
            }
            if (i == pre) {
                ret++;
                pre = last;
            }
        }
        return ret;
    }
};
