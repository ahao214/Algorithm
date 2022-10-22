#include<vector>
#include <algorithm>

using namespace std;

/*
1235. �滮��ְ����
��������ÿ���ʱ��������ְ����׬Щ�㻨Ǯ��

������ n �ݼ�ְ������ÿ�ݹ���Ԥ�ƴ� startTime[i] ��ʼ�� endTime[i] ����������Ϊ profit[i]��

����һ�ݼ�ְ������������ʼʱ�� startTime������ʱ�� endTime ��Ԥ�Ʊ��� profit �������飬������㲢���ؿ��Ի�õ���󱨳ꡣ

ע�⣬ʱ���ϳ����ص��� 2 �ݹ�������ͬʱ���С�

�����ѡ��Ĺ�����ʱ�� X ��������ô��������̽�����ʱ�� X ��ʼ����һ�ݹ�����
*/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = { startTime[i], endTime[i], profit[i] };
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int>& job1, const vector<int>& job2) -> bool {
            return job1[1] < job2[1];
            });
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int k = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, const vector<int>& job) -> bool {
                return st < job[1];
                }) - jobs.begin();
                dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
};
