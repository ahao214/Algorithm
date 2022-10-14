#include<vector>
#include<unordered_map>


using namespace std;


/*
1743. ������Ԫ�ضԻ�ԭ����
����һ���� n ����ͬԪ����ɵ��������� nums �������Ѿ��ǲ���������ݡ������㻹�ǵ� nums �е�ÿһ������Ԫ�ء�

����һ����ά�������� adjacentPairs ����СΪ n - 1 ������ÿ�� adjacentPairs[i] = [ui, vi] ��ʾԪ�� ui �� vi �� nums �����ڡ�

��Ŀ���ݱ�֤������Ԫ�� nums[i] �� nums[i+1] ��ɵ�����Ԫ�ضԶ������� adjacentPairs �У�������ʽ������ [nums[i], nums[i+1]] ��Ҳ������ [nums[i+1], nums[i]] ����Щ����Ԫ�ضԿ��� ������˳�� ���֡�

���� ԭʼ���� nums ��������ڶ��ֽ�𣬷��� ��������һ�� ���ɡ�
*/
class Solution {
public:
	/*
	��ά�����У����ִ�����1�εģ���ԭ�������λֵ
	*/

	unordered_map<int, vector<int>> g;
	vector<int> path;

	//u�ǵ�ǰ�ڵ� father�Ǹ��ڵ�
	void dfs(int u, int father)
	{
		path.push_back(u);
		for (int x : g[u])
		{
			if (x != father)
				dfs(x, u);
		}
	}

	vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
		unordered_map<int, int> cnt;
		//����ÿ�������ֵĴ���
		for (auto& e : adjacentPairs)
		{
			int a = e[0], b = e[1];
			g[a].push_back(b), g[b].push_back(a);
			cnt[a]++, cnt[b]++;
		}

		int root = 0;
		for (auto [k, v] : cnt)
		{
			if (v == 1)
			{
				root = k;
				break;
			}
		}
		dfs(root, -1);
		return path;
	}
};
