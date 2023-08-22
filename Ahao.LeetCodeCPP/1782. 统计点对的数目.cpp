#include<vector>
#include<unordered_map>
#include <algorithm>

using namespace std;


/*
1782. ͳ�Ƶ�Ե���Ŀ

����һ������ͼ������ͼ������ n  ����ʾͼ�нڵ����Ŀ���� edges ��ɣ����� edges[i] = [ui, vi] ��ʾ ui �� vi ֮����һ������ߡ�ͬʱ����һ�������ѯ���������� queries ��

�� j ����ѯ�Ĵ����������������ĵ�� (a, b) ����Ŀ��

a < b
cnt ���� a ���� b �����ıߵ���Ŀ���� cnt �ϸ���� queries[j] ��
���㷵��һ������ answers ������ answers.length == queries.length �� answers[j] �ǵ� j ����ѯ�Ĵ𰸡�

��ע�⣬ͼ�п��ܻ��� �ظ��� ��
*/
class Solution {
public:
	vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
		vector<int> d(n + 1);
			unordered_map<int, int> cnt;
		for (auto& e : edges)
		{
			int a = e[0], b = e[1];
			if (a > b) swap(a, b);
			cnt[a * 100000 + b]++;
			d[a]++, d[b]++;
		}
		vector<int> ds(d.begin() + 1, d.end());
		sort(ds.begin(), ds.end());

		vector<int> res;
		for (auto& q : queries)
		{
			int s1 = 0, s2 = 0, s3 = 0;
			for (auto [k, v] : cnt)
			{
				int a = k / 100000, b = k % 10000;
				if (d[a] + d[b] - v > q) s1++;
				if (d[a] + d[b] > q) s2++;
			}
			for (int i = n - 1, j = 0; i > j; i--)
			{
				while (j < i && ds[i] + ds[j] <= q) j++;
				if (j < i && ds[i] + ds[j] > q) s3 += i - j;
			}
			res.push_back(s1 + s3 - s2);
		}
		return res;
	}
};



class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n);
        unordered_map<int, int> cnt;
        for (auto edge : edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            if (x > y) {
                swap(x, y);
            }
            degree[x]++;
            degree[y]++;
            cnt[x * n + y]++;
        }

        vector<int> arr = degree;
        vector<int> ans;
        sort(arr.begin(), arr.end());
        for (int bound : queries) {
            int total = 0;
            for (int i = 0; i < n; i++) {
                int j = upper_bound(arr.begin() + i + 1, arr.end(), bound - arr[i]) - arr.begin();
                total += n - j;
            }
            for (auto& [val, freq] : cnt) {
                int x = val / n;
                int y = val % n;
                if (degree[x] + degree[y] > bound && degree[x] + degree[y] - freq <= bound) {
                    total--;
                }
            }
            ans.emplace_back(total);
        }

        return ans;
    }
};




