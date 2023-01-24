#include<vector>

using namespace std;


/*
1828. ͳ��һ��Բ�е����Ŀ

����һ������ points ������ points[i] = [xi, yi] ����ʾ�� i �����ڶ�άƽ���ϵ����ꡣ�������ܻ��� ��ͬ �����ꡣ

ͬʱ����һ������ queries ������ queries[j] = [xj, yj, rj] ����ʾһ��Բ���� (xj, yj) �Ұ뾶Ϊ rj ��Բ��

����ÿһ����ѯ queries[j] �������ڵ� j ��Բ �� �����Ŀ�����һ������Բ�� �߽��� ������ͬ����Ϊ����Բ �� ��

���㷵��һ������ answer ������ answer[j]�ǵ� j ����ѯ�Ĵ𰸡�
*/
class Solution {
public:
	vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
		vector<int> ans;
		for (auto& q : queries)
		{
			int X = q[0], Y = q[1], R = q[2];
			int cnt = 0;
			for (auto& p : points)
			{
				int x = p[0], y = p[1];
				if ((X - x) * (X - x) + (Y - y) * (Y - y) <= R * R)
					cnt++;
			}
			ans.push_back(cnt);
		}
		return ans;
	}
};


class Solution {
public:
	vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
		int m = points.size(), n = queries.size();
		vector<int> ans(n);
		for (int i = 0; i < n; ++i) {
			int cx = queries[i][0], cy = queries[i][1], cr = queries[i][2];
			for (int j = 0; j < m; ++j) {
				int px = points[j][0], py = points[j][1];
				if ((cx - px) * (cx - px) + (cy - py) * (cy - py) <= cr * cr) {
					++ans[i];
				}
			}
		}
		return ans;
	}
};
