#include<vector>
#include <queue>

using namespace std;


/*
2045. ����Ŀ�ĵصĵڶ���ʱ��
������һ�� ˫����ͨ ͼ��ʾ��ͼ���� n ���ڵ㣬�� 1 �� n ��ţ����� 1 �� n����ͼ�еı���һ����ά�������� edges ��ʾ������ÿ�� edges[i] = [ui, vi] ��ʾһ���ڵ� ui �ͽڵ� vi ֮���˫����ͨ�ߡ�ÿ��ڵ���� ���һ�� ����ͨ�����㲻�������ӵ�����ıߡ���������һ���ߵ�ʱ���� time ���ӡ�

ÿ���ڵ㶼��һ����ͨ�źŵƣ�ÿ change ���Ӹı�һ�Σ�����ɫ��ɺ�ɫ�����ɺ�ɫ�����ɫ��ѭ�������������źŵƶ� ͬʱ �ı䡣������� �κ�ʱ�� ����ĳ���ڵ㣬���� ֻ�� �ڽڵ� �źŵ�����ɫʱ �����뿪������źŵ���  ��ɫ ���� ���� �ڽڵ�ȴ��������뿪��

�ڶ�С��ֵ �� �ϸ���� ��Сֵ������ֵ����С��ֵ��

���磬[2, 3, 4] �еڶ�С��ֵ�� 3 ���� [2, 2, 4] �еڶ�С��ֵ�� 4 ��
���� n��edges��time �� change �����شӽڵ� 1 ���ڵ� n ��Ҫ�� �ڶ���ʱ�� ��
*/
class Solution {
public:
	struct Point {
		//kind:0 �����· 1�Ǵζ�·
		int dis, v, kind;
		bool operator< (const Point& p) const {
			return dis > p.dis;
		}
	};

	int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
		vector<vector<int>> g(n);
		for (auto& e : edges) {
			//[1,n] -> [0,n-1]
			g[e[0] - 1].push_back(e[1] - 1);
			g[e[1] - 1].push_back(e[0] - 1);
		}
		priority_queue<Point> heap;
		vector<vector<int>> dis(n, vector<int>(2, 1e8)), vis(n, vector<int>(2));
		dis[0][0] = 0;
		heap.push({ 0,0,0 });
		while (!heap.empty()) {
			auto cur = heap.top().v, kind = heap.top().kind;
			heap.pop();
			if (vis[cur][kind]) continue;
			vis[cur][kind] = 1;
			//���̵�
			int d = dis[cur][kind] + time;
			if ((dis[cur][kind] / change) % 2) {
				d += change - dis[cur][kind] % change;
			}
			for (auto v : g[cur]) {
				if (d < dis[v][0]) {
					dis[v][1] = dis[v][0];
					heap.push({ dis[v][1],v,1 });
					dis[v][0] = d;
					heap.push({ dis[v][0],v,0 });
				}
				else if (d > dis[v][0] && d < dis[v][1]) {
					dis[v][1] = d;
					heap.push({ dis[v][1],v,1 });
				}
			}
		}
		return dis[n - 1][1];
	}
};