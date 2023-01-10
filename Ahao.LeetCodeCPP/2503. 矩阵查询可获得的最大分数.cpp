#include<vector>
#include <queue>

using namespace std;



/*
2503. �����ѯ�ɻ�õ�������

����һ����СΪ m x n ���������� grid ��һ����СΪ k ������ queries ��

�ҳ�һ����СΪ k ������ answer �����������ÿ������ queres[i] ����Ӿ��� ���Ͻ� ��Ԫ��ʼ���ظ����¹��̣�

��� queries[i] �ϸ� �����㵱ǰ����λ�õ�Ԫ������õ�Ԫ���ǵ�һ�η��ʣ����� 1 �֣�����������ƶ������� 4 �������ϡ��¡����ң�����һ ���� ��Ԫ��
�����㲻�ܻ���κη֣����ҽ�����һ���̡�
�ڹ��̽�����answer[i] ������Ի�õ���������ע�⣬����ÿ����ѯ������Է���ͬһ����Ԫ�� ��� ��

���ؽ������ answer ��
*/
using AI3 = array<int, 3>;
class Solution {
	int visited[1000][1000];
public:
	vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
		int m = grid.size();
		int n = grid[0].size();
		vector<pair<int, int>>dir({ {1,0},{-1,0},{0,1},{0,-1} });

		vector<pair<int, int>> qs;
		for (int i = 0; i < queries.size(); i++) {
			qs.push_back({ queries[i],i });
		}
		sort(qs.begin(), qs.end());

		vector<int>res(qs.size());
		priority_queue<AI3, vector<AI3>, greater<>> pq;
		pq.push({ grid[0][0],0,0 });
		visited[0][0] = 1;
		int count = 0;

		for (auto& [q, idx] : qs) {
			while (!pq.empty() && pq.top()[0] < q) {
				int i = pq.top()[1];
				int j = pq.top()[2];
				pq.pop();
				count++;

				for (int k = 0; k < 4; k++) {
					int x = i + dir[k].first;
					int y = j + dir[k].second;
					if (x < 0 || x >= m || y < 0 || y >= n)
						continue;
					if (visited[x][y] == 1)
						continue;
					pq.push({ grid[x][y],x,y });
					visited[x][y] = 1;
				}
			}
			res[idx] = count;
		}
		return res;
	}
};