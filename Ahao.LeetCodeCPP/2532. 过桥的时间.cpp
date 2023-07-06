#include<vector>
#include <queue>

using namespace std;


/*
2532. ���ŵ�ʱ��

���� k λ���˼ƻ��� n �����ӴӾɲֿ��ƶ����²ֿ⡣������������ n �� k���Լ�һ����ά�������� time ������Ĵ�СΪ k x 4 ������ time[i] = [leftToRighti, pickOldi, rightToLefti, putNewi] ��

һ���ӽ������ֿ�ָ���ֻ��ͨ��һ����ͨ�С��ɲֿ�λ�ںӵ��Ұ����²ֿ��ںӵ��󰶡���ʼʱ������ k λ���˶����ŵ����ȴ���Ϊ���ƶ���Щ���ӣ��� i λ���ˣ��±�� 0 ��ʼ�����ԣ�

���󰶣��²ֿ⣩����ŵ��Ұ����ɲֿ⣩����ʱ leftToRighti ���ӡ�
�Ӿɲֿ�ѡ��һ�����ӣ������ص��űߣ���ʱ pickOldi ���ӡ���ͬ���˿���ͬʱ������ѡ�����ӡ�
���Ұ����ɲֿ⣩����ŵ��󰶣��²ֿ⣩����ʱ rightToLefti ���ӡ�
�����ӷ����²ֿ⣬�����ص��űߣ���ʱ putNewi ���ӡ���ͬ���˿���ͬʱ������ѡ�����ӡ�
�������������һ����������Ϊ���� i �� Ч�ʵ��� ���� j ��

leftToRighti + rightToLefti > leftToRightj + rightToLeftj
leftToRighti + rightToLefti == leftToRightj + rightToLeftj �� i > j
����ͨ����ʱ��Ҫ��ѭ���¹���

������� x �����ű�ʱ������ y ���ڹ��ţ���ô���� x ��Ҫ���űߵȴ���
���û�����ڹ��ŵĹ��ˣ���ô�����ұߵȴ��Ĺ��˿����ȹ��š����ͬʱ�ж���������ұߵȴ�����ô Ч����� �Ĺ��˻��ȹ��š�
���û�����ڹ��ŵĹ��ˣ������ұ�Ҳû���ڵȴ��Ĺ��ˣ�ͬʱ�ɲֿ⻹ʣ������һ��������Ҫ���ˣ���ʱ������ߵĹ��˿��Թ��š����ͬʱ�ж����������ߵȴ�����ô Ч����� �Ĺ��˻��ȹ��š�
���� n �����Ӷ���Ҫ�����²ֿ⣬���㷵�����һ���������ӵĹ��� ������� ��ʱ�䡣
*/

class Solution {
public:
    using PII = pair<int, int>;
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        // ����ȴ��еĹ������ȼ��ȽϹ���ʱ���ܺ�Խ�ߣ�Ч��Խ�ͣ����ȼ�Խ�ͣ�Խ���ȱ�ȡ��
        auto wait_priority_cmp = [&](int x, int y) {
            int time_x = time[x][0] + time[x][2];
            int time_y = time[y][0] + time[y][2];
            return time_x != time_y ? time_x < time_y : x < y;
        };

        priority_queue<int, vector<int>, decltype(wait_priority_cmp)> wait_left(wait_priority_cmp), wait_right(wait_priority_cmp);

        priority_queue<PII, vector<PII>, greater<PII>> work_left, work_right;

        int remain = n, cur_time = 0;
        for (int i = 0; i < k; i++) {
            wait_left.push(i);
        }
        while (remain > 0 || !work_right.empty() || !wait_right.empty()) {
            // 1. �� work_left �� work_right �еĹ�����ɹ�����������ȡ�������ֱ���õ� wait_left �� wait_right �С�
            while (!work_left.empty() && work_left.top().first <= cur_time) {
                wait_left.push(work_left.top().second);
                work_left.pop();
            }
            while (!work_right.empty() && work_right.top().first <= cur_time) {
                wait_right.push(work_right.top().second);
                work_right.pop();
            }

            if (!wait_right.empty()) {
                // 2. ���Ҳ��й����ڵȴ�����ȡ�����ȼ���͵Ĺ��˲�����
                int id = wait_right.top();
                wait_right.pop();
                cur_time += time[id][2];
                work_left.push({ cur_time + time[id][3], id });
            }
            else if (remain > 0 && !wait_left.empty()) {
                // 3. ���Ҳ໹�����ӣ���������й����ڵȴ�����ȡ�����ȼ���͵Ĺ��˲�����
                int id = wait_left.top();
                wait_left.pop();
                cur_time += time[id][0];
                work_right.push({ cur_time + time[id][1], id });
                remain--;
            }
            else {
                // 4. ����û������Ҫ���ţ�ʱ����ɵ� work_left �� work_right �е��������ʱ��
                int next_time = INT_MAX;
                if (!work_left.empty()) {
                    next_time = min(next_time, work_left.top().first);
                }
                if (!work_right.empty()) {
                    next_time = min(next_time, work_right.top().first);
                }
                if (next_time != INT_MAX) {
                    cur_time = max(next_time, cur_time);
                }
            }
        }
        return cur_time;
    }
};
