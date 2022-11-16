#include<vector>

using namespace std;


/*
947. �Ƴ�����ͬ�л�ͬ��ʯͷ
n ��ʯͷ�����ڶ�άƽ���е�һЩ����������ϡ�ÿ������������ֻ����һ��ʯͷ��

���һ��ʯͷ�� ͬ�л���ͬ�� ��������ʯͷ���ڣ���ô�Ϳ����Ƴ����ʯͷ��

����һ������Ϊ n ������ stones ������ stones[i] = [xi, yi] ��ʾ�� i ��ʯͷ��λ�ã����� �����Ƴ���ʯ�� �����������
*/
class Solution {
	bool isConnected(vector<int>& a, vector<int>& b) {
		return a[0] == b[0] || a[1] == b[1];
	}
	void dfs(vector<vector<int>>& connected, vector<int>& visited, int i)
	{
		visited[i] = 1;
		for (int& index : connected[i]) {
			if (visited[index] == 0) {
				dfs(connected, visited, index);
			}
		}
	}
public:
	int removeStones(vector<vector<int>>& stones) {
		int n = stones.size();
		vector<vector<int> > connected(n);
		vector<int> visited(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (isConnected(stones[i], stones[j])) {
					connected[i].push_back(j);
					connected[j].push_back(i);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == 0)
			{
				cnt++;
				dfs(connected, visited, i);
			}
		}
		return n - cnt;
	}
};