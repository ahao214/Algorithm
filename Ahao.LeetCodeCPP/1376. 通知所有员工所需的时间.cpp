#include<vector>
#include <functional>
#include<unordered_map>
#include <queue>
#include<algorithm>

using namespace std;


/*
1376. 通知所有员工所需的时间

公司里有 n 名员工，每个员工的 ID 都是独一无二的，编号从 0 到 n - 1。公司的总负责人通过 headID 进行标识。

在 manager 数组中，每个员工都有一个直属负责人，其中 manager[i] 是第 i 名员工的直属负责人。对于总负责人，manager[headID] = -1。题目保证从属关系可以用树结构显示。

公司总负责人想要向公司所有员工通告一条紧急消息。他将会首先通知他的直属下属们，然后由这些下属通知他们的下属，直到所有的员工都得知这条紧急消息。

第 i 名员工需要 informTime[i] 分钟来通知它的所有直属下属（也就是说在 informTime[i] 分钟后，他的所有直属下属都可以开始传播这一消息）。

返回通知所有员工这一紧急消息所需要的分钟数 。
*/
class Solution {
public:
	vector<vector<int>> son;

	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		son = vector<vector<int>>(n);

		for (int i = 0; i < n; i++)
		{
			if (i != headID)
			{
				son[manager[i]].push_back(i);
			}
		}
		return dfs(headID, informTime);
	}

	int dfs(int u, vector<int>& informTime)
	{
		int res = 0;
		for (auto s : son[u])
			res = max(res, dfs(s, informTime));
		return res + informTime[u];
	}
};


class Solution {
public:
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		// 建立一个从 manager[i] 到 i 的有向图
		unordered_map<int, vector<int>> g;
		for (int i = 0; i < n; i++) {
			g[manager[i]].emplace_back(i);
		}
		// 定义一个 dfs 函数，遍历从 headID 开始的子树
		function<int(int)> dfs = [&](int cur) -> int {
			int res = 0;
			// 遍历当前节点的所有子节点，计算从子节点到当前节点的时间
			for (int neighbor : g[cur]) {
				res = max(res, dfs(neighbor));
			}
			// 加上当前节点到其上级节点的时间
			return informTime[cur] + res;
		};
		// 返回从 headID 到其所有子节点的最大时间
		return dfs(headID);
	}
};


class Solution {
public:
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		// 创建一个无序哈希表，键是管理者ID，值是直接汇报给他的员工的列表。
		unordered_map<int, vector<int>> g;
		// 将所有员工添加到各自的管理者的值（列表）中。
		for (int i = 0; i < n; i++) {
			g[manager[i]].emplace_back(i);
		}
		// 创建一个队列，第一个元素是员工ID，第二个元素是从头节点到这个员工的总时间。
		queue<pair<int, int>> q;
		// 添加第一个元素到队列中。
		q.emplace(headID, 0);
		// 保存最长时间。
		int res = 0;
		while (!q.empty()) {
			auto [tmp_id, val] = q.front();
			q.pop();
			// 如果这个员工没有管理其他员工，它就是公司最后一个员工，将总时间与结果中的最大值比较并更新结果。
			if (!g.count(tmp_id)) {
				res = max(res, val);
			}
			else {
				// 如果这个员工管理其他员工，将直接报告给它的员工加入到队列中。
				for (int neighbor : g[tmp_id]) {
					q.emplace(neighbor, val + informTime[tmp_id]);
				}
			}
		}
		return res;
	}
};



