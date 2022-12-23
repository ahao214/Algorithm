#include<vector>
#include <algorithm>

using namespace std;


/*
452. �����������ļ���������
�ڶ�ά�ռ�����������ε����򡣶���ÿ�������ṩ��������ˮƽ�����ϣ�����ֱ���Ŀ�ʼ�ͽ������ꡣ��������ˮƽ�ģ����������겢����Ҫ�����ֻҪ֪����ʼ�ͽ����ĺ�������㹻�ˡ���ʼ��������С�ڽ������ꡣ

һ֧������������ x ��Ӳ�ͬ����ȫ��ֱ������������� x �����һ֧��������һ�������ֱ���Ŀ�ʼ�ͽ�������Ϊ xstart��xend�� ������  xstart �� x �� xend���������ᱻ��������������Ĺ���������û�����ơ� ����һ�������֮�󣬿������޵�ǰ�����������ҵ�ʹ����������ȫ��������������Ĺ�������С������

����һ������ points ������ points [i] = [xstart,xend] �������������������������������С��������
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
            });
        int pos = points[0][1];
        int ans = 1;
        for (const vector<int>& balloon : points) {
            if (balloon[0] > pos) {
                pos = balloon[1];
                ++ans;
            }
        }
        return ans;
    }
};
