#include<vector>
#include <algorithm>
#include <queue>

using namespace std;


/*
1996. 游戏中弱角色的数量

你正在参加一个多角色游戏，每个角色都有两个主要属性：攻击 和 防御 。给你一个二维整数数组 properties ，其中 properties[i] = [attacki, defensei] 表示游戏中第 i 个角色的属性。

如果存在一个其他角色的攻击和防御等级 都严格高于 该角色的攻击和防御等级，则认为该角色为 弱角色 。更正式地，如果认为角色 i 弱于 存在的另一个角色 j ，那么 attackj > attacki 且 defensej > defensei 。

返回 弱角色 的数量。
*/
class Solution {
public:
	int numberOfWeekCharacters(vector<vector<int>>& properties) {
		sort(properties.begin(), properties.end(), [](const vector<int>& p1, const vector<int>& p2) {
			if (p1[0] != p2[0])
				return p1[0] < p2[0];
			return p1[1] < p2[1];
			});
		priority_queue<int> q;
		int n = properties.size(), mx = properties[n - 1][0], my = properties[n - 1][1], ans = 0;
		for (int i = n - 2; i >= 0; i--) {
			//严格高于
			if (properties[i][0] < mx && properties[i][1] < my)
				ans++;
			//x等于当前mx，但y严格低于之前的my
			else if (properties[i][0] == mx && !q.empty() && properties[i][1] < q.top())
				ans++;
			else if (properties[i][1] > my) {
				//更新mx和my 用一个更大的y更新my
				q.push(my);
				mx = properties[i][0];
				my = properties[i][1];
			}
		}
		return ans;
	}
};