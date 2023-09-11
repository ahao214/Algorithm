#include<vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
630. �γ̱� III

������ n �Ų�ͬ�����߿γ̣����� 1 �� n ��š�����һ������ courses ������ courses[i] = [durationi, lastDayi] ��ʾ�� i �ſν��� ���� �� durationi ��Σ����ұ����ڲ����� lastDayi ��ʱ����ɡ�

���ѧ�ڴӵ� 1 �쿪ʼ���Ҳ���ͬʱ�޶����ż��������ϵĿγ̡�

�������������޶��Ŀγ���Ŀ��
*/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& c0, const auto& c1) {
            return c0[1] < c1[1];
            });

        priority_queue<int> q;
        // ���ȶ��������пγ̵���ʱ��
        int total = 0;

        for (const auto& course : courses) {
            int ti = course[0], di = course[1];
            if (total + ti <= di) {
                total += ti;
                q.push(ti);
            }
            else if (!q.empty() && q.top() > ti) {
                total -= q.top() - ti;
                q.pop();
                q.push(ti);
            }
        }

        return q.size();
    }
};
