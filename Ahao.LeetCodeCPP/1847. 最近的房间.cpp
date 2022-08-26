#include<vector>
#include<set>
#include<algorithm>

using namespace std;


/*
1847. ����ķ���
һ���Ƶ����� n �����䣬��Щ�����ö�ά�������� rooms ��ʾ������ rooms[i] = [roomIdi, sizei] ��ʾ��һ�������Ϊ roomIdi �ķ������������Ϊ sizei ��ÿһ������� roomIdi ��֤�� ��һ�޶� �ġ�

ͬʱ���� k ����ѯ���ö�ά���� queries ��ʾ������ queries[j] = [preferredj, minSizej] ���� j ����ѯ�Ĵ����������������ķ��� id ��

�������� ���� Ϊ minSizej ����
abs(id - preferredj) ��ֵ ��С ������ abs(x) �� x �ľ���ֵ��
�����ľ���ֵ�� ��� �ģ�ѡ�� ��С �� id ����� û�����������ķ��� ����Ϊ -1 ��

���㷵�س���Ϊ k ������ answer ������ answer[j] Ϊ�� j ����ѯ�Ľ����
*/
class Solution {
public:
	struct Query {
		int id, p, m;
		bool operator < (const Query& t)const {
			return m < t.m;
		}
	};

	vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
		int n = queries.size();
		vector<Query> q;
		for (int i = 0; i < n; i++)
			q.push_back({ i,queries[i][0],queries[i][1] });
		sort(q.begin(), q.end());
		sort(rooms.begin(), rooms.end(), [](vector<int>& a, vector<int>& b)
			{
				return a[1] < b[1];
			});
		const int INF = 1e9;
		vector<int> res(n);
		set<int> hs{ -INF,INF };
		for (int i = n - 1, j = rooms.size() - 1; i >= 0; i--)
		{
			while (j >= 0 && rooms[j][1] >= q[i].m)
				hs.insert(rooms[j--][0]);
			int p = q[i].p, id = q[i].id;
			auto k = hs.lower_bound(p);
			auto u = k;
			--u;
			if (p - *u <= *k - p)
				res[id] = *u;
			else
				res[id] = *k;
			if (abs(res[id]) == INF)
				res[id] = -1;
		}
		return res;
	}

};