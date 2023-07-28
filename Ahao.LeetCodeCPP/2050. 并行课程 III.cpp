#include<vector>
#include <unordered_map>
#include <functional>

using namespace std;

/*
2050. ���пγ� III

����һ������ n ����ʾ�� n �ڿΣ��γ̱�Ŵ� 1 �� n ��ͬʱ����һ����ά�������� relations ������ relations[j] = [prevCoursej, nextCoursej] ����ʾ�γ� prevCoursej �����ڿγ� nextCoursej ֮ǰ ��ɣ����޿εĹ�ϵ����ͬʱ����һ���±�� 0 ��ʼ���������� time ������ time[i] ��ʾ��ɵ� (i+1) �ſγ���Ҫ���ѵ� �·� ����

����������¹������������пγ�����Ҫ�� ���� �·�����

���һ�ſε��������޿ζ��Ѿ���ɣ�������� ���� ʱ�俪ʼ���ſγ̡�
����� ͬʱ �� �����ſγ� ��
���㷵��������пγ�����Ҫ�� ���� �·�����

ע�⣺�������ݱ�֤һ������������пγ̣�Ҳ�������޿εĹ�ϵ����һ�������޻�ͼ����
*/


class Solution {
public:
	int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
		int mx = 0;
		vector<vector<int>> prev(n + 1);
		for (auto& relation : relations) {
			int x = relation[0], y = relation[1];
			prev[y].emplace_back(x);
		}
		unordered_map<int, int> memo;
		function<int(int)> dp = [&](int i) -> int {
			if (!memo.count(i)) {
				int cur = 0;
				for (int p : prev[i]) {
					cur = max(cur, dp(p));
				}
				cur += time[i - 1];
				memo[i] = cur;
			}
			return memo[i];
		};

		for (int i = 1; i <= n; i++) {
			mx = max(mx, dp(i));
		}
		return mx;
	}
};
