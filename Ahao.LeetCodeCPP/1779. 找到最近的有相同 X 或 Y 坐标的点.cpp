#include<vector>

using namespace std;


/*
1779. 找到最近的有相同 X 或 Y 坐标的点
给你两个整数 x 和 y ，表示你在一个笛卡尔坐标系下的 (x, y) 处。同时，在同一个坐标系下给你一个数组 points ，其中 points[i] = [ai, bi] 表示在 (ai, bi) 处有一个点。当一个点与你所在的位置有相同的 x 坐标或者相同的 y 坐标时，我们称这个点是 有效的 。

请返回距离你当前位置 曼哈顿距离 最近的 有效 点的下标（下标从 0 开始）。如果有多个最近的有效点，请返回下标 最小 的一个。如果没有有效点，请返回 -1 。

两个点 (x1, y1) 和 (x2, y2) 之间的 曼哈顿距离 为 abs(x1 - x2) + abs(y1 - y2) 。
*/
class Solution {
public:
	int getDis(vector<int> a, vector<int>& b)
	{
		return abs(a[0] - b[0]) + abs(a[1] - b[1]);
	}

	int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
		int res = -1;
		for (int i = 0; i < points.size(); i++)
		{
			if (points[i][0] == x || points[i][1] == y)
			{
				if (res == -1 || getDis({ x,y }, points[res]) > getDis({ x,y }, points[i]))
					res = i;
			}
		}
		return res;
	}
};


class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int best = numeric_limits<int>::max(), bestid = -1;
        for (int i = 0; i < n; ++i) {
            int px = points[i][0], py = points[i][1];
            if (x == px) {
                if (int dist = abs(y - py); dist < best) {
                    best = dist;
                    bestid = i;
                }
            }
            else if (y == py) {
                if (int dist = abs(x - px); dist < best) {
                    best = dist;
                    bestid = i;
                }
            }
        }
        return bestid;
    }
};
