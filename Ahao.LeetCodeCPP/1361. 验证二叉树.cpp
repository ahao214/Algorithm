#include<vector>
#include <queue>

using namespace std;


/*
1361. 验证二叉树
二叉树上有 n 个节点，按从 0 到 n - 1 编号，
其中节点 i 的两个子节点分别是 leftChild[i] 和 rightChild[i]。

只有 所有 节点能够形成且 只 形成 一颗 有效的二叉树时，返回 true；
否则返回 false。

如果节点 i 没有左子节点，那么 leftChild[i] 就等于 -1。
右子节点也符合该规则。

注意：节点没有值，本问题中仅仅使用节点编号。
*/
class Solution {
public:
	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
		vector<int> d(n);
		for (int i = 0; i < n; i++)
		{
			if (leftChild[i] != -1) d[leftChild[i]]++;
			if (rightChild[i] != -1) d[rightChild[i]]++;
		}

		int root = 0;
		while (root < n && d[root]) root++;
		if (root == n) return false;

		vector<bool> st(n);
		st[root] = true;
		queue<int> q;
		q.push(root);

		while (q.size())
		{
			int t = q.front();
			q.pop();

			int sons[] = { leftChild[t],rightChild[t] };
			for (auto s : sons)
			{
				if (s != -1)
				{
					if (st[s]) return false;
					st[s] = true;
					q.push(s);
				}
			}
		}

		for (auto state : st)
		{
			if (!state)
				return false;
		}
		return true;
	}
};
