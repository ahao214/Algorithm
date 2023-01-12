#include<vector>

using namespace std;


/*
2467. �������÷ֺ�·��

һ�� n ���ڵ�����������ڵ���Ϊ 0 �� n - 1 �����ĸ������ 0 �Žڵ㡣����һ������Ϊ n - 1 �Ķ�ά�������� edges ������ edges[i] = [ai, bi] ����ʾ�ڵ� ai �� bi ��������һ���ߡ�

��ÿһ���ڵ� i ����һ���š�ͬʱ����һ������ż�������� amount ������ amount[i] ��ʾ��

��� amount[i] ��ֵ�Ǹ�������ô����ʾ�򿪽ڵ� i ���ſ۳��ķ�����
��� amount[i] ��ֵ����������ô����ʾ�򿪽ڵ� i ���ż��ϵķ�����
��Ϸ�������¹�����У�

һ��ʼ��Alice �ڽڵ� 0 ����Bob �ڽڵ� bob ����
ÿһ���ӣ�Alice �� Bob �ֱ� �ƶ������ڵĽڵ㡣Alice ����ĳ�� Ҷ�ӽ�� �ƶ���Bob ���Žڵ� 0 �ƶ���
��������֮��·���ϵ� ÿһ�� �ڵ㣬Alice �� Bob Ҫô���Ų��۷֣�Ҫô���Ų��ӷ֡�ע�⣺
����� �Ѿ��� ������һ���˴򿪣��������ж���ӷ�Ҳ����۷֡�
��� Alice �� Bob ͬʱ ����һ���ڵ㣬���ǻṲ������ڵ�ļӷֻ��߿۷֡�����֮������������ſ� c �֣���ô Alice �� Bob �ֱ�� c / 2 �֡���������ŵļӷ�Ϊ c ����ô���Ƿֱ�� c / 2 �֡�
��� Alice ������һ��Ҷ�ӽ�㣬����ֹͣ�ƶ������Ƶģ���� Bob �����˽ڵ� 0 ����Ҳ��ֹͣ�ƶ���ע����Щ�¼����� ���� ������Ӱ����һ���ƶ���
���㷵�� Alice ������Ҷ�ӽ���ƶ��� ��� ���÷֡�
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


