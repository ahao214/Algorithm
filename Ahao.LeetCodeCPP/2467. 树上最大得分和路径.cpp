#include<vector>

using namespace std;


/*
2467. 树上最大得分和路径

一个 n 个节点的无向树，节点编号为 0 到 n - 1 ，树的根结点是 0 号节点。给你一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi] ，表示节点 ai 和 bi 在树中有一条边。

在每一个节点 i 处有一扇门。同时给你一个都是偶数的数组 amount ，其中 amount[i] 表示：

如果 amount[i] 的值是负数，那么它表示打开节点 i 处门扣除的分数。
如果 amount[i] 的值是正数，那么它表示打开节点 i 处门加上的分数。
游戏按照如下规则进行：

一开始，Alice 在节点 0 处，Bob 在节点 bob 处。
每一秒钟，Alice 和 Bob 分别 移动到相邻的节点。Alice 朝着某个 叶子结点 移动，Bob 朝着节点 0 移动。
对于他们之间路径上的 每一个 节点，Alice 和 Bob 要么打开门并扣分，要么打开门并加分。注意：
如果门 已经打开 （被另一个人打开），不会有额外加分也不会扣分。
如果 Alice 和 Bob 同时 到达一个节点，他们会共享这个节点的加分或者扣分。换言之，如果打开这扇门扣 c 分，那么 Alice 和 Bob 分别扣 c / 2 分。如果这扇门的加分为 c ，那么他们分别加 c / 2 分。
如果 Alice 到达了一个叶子结点，她会停止移动。类似的，如果 Bob 到达了节点 0 ，他也会停止移动。注意这些事件互相 独立 ，不会影响另一方移动。
请你返回 Alice 朝最优叶子结点移动的 最大 净得分。
*/
class Solution {
	int b[100005];
	vector<int>next[100005];
	int result = INT_MIN / 2;
	int bob;
	vector<int> amount;
public:
	int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
		this->amount = amount;
		this->bob = bob;

		int n = amount.size();
		for (int i = 0; i < n; i++) {
			b[i] = INT_MAX / 2;
		}
		for (auto& edge : edges) {
			int a = edge[0];
			int b = edge[1];

			next[a].push_back(b);
			next[b].push_back(a);
		}
		dfs(0, -1, 0);
		dfs2(0, -1, 0, 0);
		return result;
	}

	void dfs(int cur, int parent, int step) {
		if (cur == bob) {
			b[cur] = 0;
			return;
		}
		int toBob = INT_MAX / 2;
		for (int nxt : next[cur]) {
			if (nxt == parent) {
				continue;
			}
			dfs(nxt, cur, step + 1);
			toBob = min(toBob, b[nxt] + 1);
		}
		b[cur] = toBob;
		return;
	}

	void dfs2(int cur, int parent, int step, int score) {
		if (step == b[cur]) {
			score += amount[cur] / 2;
		}
		else if (step < b[cur]) {
			score += amount[cur];
		}
		if (next[cur].size() == 1 && next[cur][0] == parent) {
			result = max(result, score);
			return;
		}
		for (int nxt : next[cur]) {
			if (nxt == parent) {
				continue;
			}
			dfs2(nxt, cur, step + 1, score);
		}
	}
};


