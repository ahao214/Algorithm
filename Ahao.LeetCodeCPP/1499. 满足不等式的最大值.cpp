#include<vector>
#include <deque>

using namespace std;


/*
1499. ���㲻��ʽ�����ֵ

����һ������ points ��һ������ k ��������ÿ��Ԫ�ض���ʾ��άƽ���ϵĵ�����꣬�����պ����� x ��ֵ��С��������Ҳ����˵ points[i] = [xi, yi] �������� 1 <= i < j <= points.length ��ǰ���£� xi < xj �ܳ�����

�����ҳ� yi + yj + |xi - xj| �� ���ֵ������ |xi - xj| <= k �� 1 <= i < j <= points.length��

��Ŀ�������ݱ�֤���ٴ���һ���ܹ����� |xi - xj| <= k �ĵ㡣
*/
class Solution {
public:
	/*
	yi + yj + |xi - xj| = yi + yj + xj - xi =(yi - xi) + (yj + xj)
		������������ֵ
	*/
	int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
		deque<int> q;	//��������
		int res = INT_MIN;

		for (int i = 0; i < points.size(); i++)
		{
			int x = points[i][0], y = points[i][1];
			while (q.size() && x - points[q.front()][0] > k) q.pop_front();
			if (q.size())
			{
				int t = q.front();
				res = max(res, x + y + points[t][1] - points[t][0]);
			}
			while (q.size() && points[q.back()][1] - points[q.back()][0] <= y - x)
				q.pop_back();
			q.push_back(i);
		}
		return res;
	}
};




class Solution {
public:
	using pii = pair<int, int>;
	int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
		int res = INT_MIN;
		priority_queue<pii, vector<pii>, greater<pii>> heap;
		for (auto& point : points) {
			int x = point[0], y = point[1];
			while (!heap.empty() && x - heap.top().second > k) {
				heap.pop();
			}
			if (!heap.empty()) {
				res = max(res, x + y - heap.top().first);
			}
			heap.emplace(x - y, x);
		}
		return res;
	}
};


class Solution {
public:
	using pii = pair<int, int>;
	int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
		int res = INT_MIN;
		deque<pii> qu;
		for (auto& point : points) {
			int x = point[0], y = point[1];
			while (!qu.empty() && x - qu.front().second > k) {
				qu.pop_front();
			}
			if (!qu.empty()) {
				res = max(res, x + y + qu.front().first);
			}
			while (!qu.empty() && y - x >= qu.back().first) {
				qu.pop_back();
			}
			qu.emplace_back(y - x, x);
		}
		return res;
	}
};
