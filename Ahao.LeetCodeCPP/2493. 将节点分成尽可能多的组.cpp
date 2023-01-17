#include<vector>
#include <unordered_map>
#include <queue>

using namespace std;



/*
2493. ���ڵ�ֳɾ����ܶ����
����һ�������� n ����ʾһ�� ���� ͼ�еĽڵ���Ŀ���ڵ��Ŵ� 1 �� n ��

ͬʱ����һ����ά�������� edges ������ edges[i] = [ai, bi] ��ʾ�ڵ� ai �� bi ֮����һ�� ˫�� �ߡ�ע�������ͼ�����ǲ���ͨ�ġ�

���㽫ͼ����Ϊ m ���飨��Ŵ� 1 ��ʼ������������Ҫ��

ͼ��ÿ���ڵ㶼ֻ����һ���顣
ͼ��ÿ�������ӵ������� [ai, bi] ����� ai ���ڱ��Ϊ x ���飬bi ���ڱ��Ϊ y ���飬��ô |y - x| = 1 ��
���㷵�������Խ��ڵ��Ϊ���ٸ��飨Ҳ�������� m �������û�취�ڸ��������·��飬���㷵�� -1 ��
*/
class Solution {
	vector<int>next[505];
public:
	int magnificentSets(int n, vector<vector<int>>& edges) {
		for (auto edge : edges) {
			int a = edge[0], b = edge[1];
			next[a].push_back(b);
			next[b].push_back(a);
		}
		unordered_map<int, int>map;
		for (int start = 1; start <= n; start++) {
			int maxDepth = 0;
			int smallestId = INT_MAX;
			vector<int>level(505);
			queue<pair<int, int>> q;
			q.push({ start,1 });
			level[start] = 1;
			while (!q.empty()) {
				auto [cur, d] = q.front();
				q.pop();
				maxDepth = max(maxDepth, d);
				smallestId = min(smallestId, cur);

				for (int nxt : next[cur]) {
					if (level[nxt] == 0) {
						level[nxt] = d + 1;
						q.push({ nxt,d + 1 });
					}
					else if (level[nxt] == d) {
						return -1;
					}
				}
			}
			map[smallestId] = max(map[smallestId], maxDepth);
		}
		int res = 0;
		for (auto [k, v] : map) {
			res += v;
		}
		return res;
	}
};