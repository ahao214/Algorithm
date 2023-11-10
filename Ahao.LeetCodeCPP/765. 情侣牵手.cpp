#include<vector>
#include <unordered_map>
#include <queue>

using namespace std;


/*
765. 情侣牵手

n 对情侣坐在连续排列的 2n 个座位上，想要牵到对方的手。

人和座位由一个整数数组 row 表示，其中 row[i] 是坐在第 i 个座位上的人的 ID。情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2n-2, 2n-1)。

返回 最少交换座位的次数，以便每对情侣可以并肩坐在一起。 每次交换可选择任意两人，让他们站起来交换座位。
*/
class Solution {
public:
	vector<int> p;
	int find(int x)
	{
		if (p[x] != x)
			p[x] = find(p[x]);
		return p[x];
	}
	int minSwapsCouples(vector<int>& row) {
		int n = row.size() / 2;
		for (int i = 0; i < n; i++)
			p.push_back(i);
		int cnt = n;
		for (int i = 0; i < n * 2; i += 2)
		{
			int a = row[i] / 2, b = row[i + 1] / 2;
			if (find(a) != find(b))
			{
				p[find(a)] = find(b);
				cnt--;
			}
		}
		return n - cnt;
	}
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int tot = n / 2;

        vector<vector<int>> graph(tot);
        for (int i = 0; i < n; i += 2) {
            int l = row[i] / 2;
            int r = row[i + 1] / 2;
            if (l != r) {
                graph[l].push_back(r);
                graph[r].push_back(l);
            }
        }
        vector<int> visited(tot, 0);
        int ret = 0;
        for (int i = 0; i < tot; i++) {
            if (visited[i] == 0) {
                queue<int> q;
                visited[i] = 1;
                q.push(i);
                int cnt = 0;

                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    cnt += 1;

                    for (int y : graph[x]) {
                        if (visited[y] == 0) {
                            visited[y] = 1;
                            q.push(y);
                        }
                    }
                }
                ret += cnt - 1;
            }
        }
        return ret;
    }
};



class Solution {
public:
    int getf(vector<int>& f, int x) {
        if (f[x] == x) {
            return x;
        }
        int newf = getf(f, f[x]);
        f[x] = newf;
        return newf;
    }

    void add(vector<int>& f, int x, int y) {
        int fx = getf(f, x);
        int fy = getf(f, y);
        f[fx] = fy;
    }

    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int tot = n / 2;
        vector<int> f(tot, 0);
        for (int i = 0; i < tot; i++) {
            f[i] = i;
        }

        for (int i = 0; i < n; i += 2) {
            int l = row[i] / 2;
            int r = row[i + 1] / 2;
            add(f, l, r);
        }

        unordered_map<int, int> m;
        for (int i = 0; i < tot; i++) {
            int fx = getf(f, i);
            m[fx]++;
        }

        int ret = 0;
        for (const auto& [f, sz] : m) {
            ret += sz - 1;
        }
        return ret;
    }
};
