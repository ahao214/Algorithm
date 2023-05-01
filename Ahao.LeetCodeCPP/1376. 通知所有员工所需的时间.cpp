#include<vector>
#include <functional>
#include<unordered_map>
#include <queue>
#include<algorithm>

using namespace std;


/*
1376. ֪ͨ����Ա�������ʱ��

��˾���� n ��Ա����ÿ��Ա���� ID ���Ƕ�һ�޶��ģ���Ŵ� 0 �� n - 1����˾���ܸ�����ͨ�� headID ���б�ʶ��

�� manager �����У�ÿ��Ա������һ��ֱ�������ˣ����� manager[i] �ǵ� i ��Ա����ֱ�������ˡ������ܸ����ˣ�manager[headID] = -1����Ŀ��֤������ϵ���������ṹ��ʾ��

��˾�ܸ�������Ҫ��˾����Ա��ͨ��һ��������Ϣ������������֪ͨ����ֱ�������ǣ�Ȼ������Щ����֪ͨ���ǵ�������ֱ�����е�Ա������֪����������Ϣ��

�� i ��Ա����Ҫ informTime[i] ������֪ͨ��������ֱ��������Ҳ����˵�� informTime[i] ���Ӻ���������ֱ�����������Կ�ʼ������һ��Ϣ����

����֪ͨ����Ա����һ������Ϣ����Ҫ�ķ����� ��
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
		// ����һ���� manager[i] �� i ������ͼ
		unordered_map<int, vector<int>> g;
		for (int i = 0; i < n; i++) {
			g[manager[i]].emplace_back(i);
		}
		// ����һ�� dfs ������������ headID ��ʼ������
		function<int(int)> dfs = [&](int cur) -> int {
			int res = 0;
			// ������ǰ�ڵ�������ӽڵ㣬������ӽڵ㵽��ǰ�ڵ��ʱ��
			for (int neighbor : g[cur]) {
				res = max(res, dfs(neighbor));
			}
			// ���ϵ�ǰ�ڵ㵽���ϼ��ڵ��ʱ��
			return informTime[cur] + res;
		};
		// ���ش� headID ���������ӽڵ�����ʱ��
		return dfs(headID);
	}
};


class Solution {
public:
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		// ����һ�������ϣ�����ǹ�����ID��ֵ��ֱ�ӻ㱨������Ա�����б�
		unordered_map<int, vector<int>> g;
		// ������Ա����ӵ����ԵĹ����ߵ�ֵ���б��С�
		for (int i = 0; i < n; i++) {
			g[manager[i]].emplace_back(i);
		}
		// ����һ�����У���һ��Ԫ����Ա��ID���ڶ���Ԫ���Ǵ�ͷ�ڵ㵽���Ա������ʱ�䡣
		queue<pair<int, int>> q;
		// ��ӵ�һ��Ԫ�ص������С�
		q.emplace(headID, 0);
		// �����ʱ�䡣
		int res = 0;
		while (!q.empty()) {
			auto [tmp_id, val] = q.front();
			q.pop();
			// ������Ա��û�й�������Ա���������ǹ�˾���һ��Ա��������ʱ�������е����ֵ�Ƚϲ����½����
			if (!g.count(tmp_id)) {
				res = max(res, val);
			}
			else {
				// ������Ա����������Ա������ֱ�ӱ��������Ա�����뵽�����С�
				for (int neighbor : g[tmp_id]) {
					q.emplace(neighbor, val + informTime[tmp_id]);
				}
			}
		}
		return res;
	}
};



