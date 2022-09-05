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
