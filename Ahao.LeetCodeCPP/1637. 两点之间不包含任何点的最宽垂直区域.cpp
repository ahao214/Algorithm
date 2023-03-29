#include<vector>
#include <algorithm>

using namespace std;

/*
1637. ����֮�䲻�����κε�����ֱ����

���� n ����άƽ���ϵĵ� points ������ points[i] = [xi, yi] �����㷵������֮���ڲ��������κε�� ���ֱ���� �Ŀ�ȡ�

��ֱ���� �Ķ����ǹ̶���ȣ��� y �������������һ������Ҳ���Ǹ߶�Ϊ����󣩡� ���ֱ���� Ϊ�������һ����ֱ����

��ע�⣬��ֱ���� ���� �ĵ� ���� �����ڡ�
*/


class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int mx = 0;
        for (int i = 1; i < points.size(); i++) {
            mx = max(points[i][0] - points[i - 1][0], mx);
        }
        return mx;
    }
};
