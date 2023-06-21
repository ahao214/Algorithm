using namespace std;

#include<vector>
#include <numeric>
#include <algorithm>

//����
class Solution {
public:
	bool dfs(int index, vector<int>& matchsticks, vector<int>& edges, int len) {
		if (index == matchsticks.size()) {
			return true;
		}
		for (int i = 0; i < edges.size(); i++) {
			edges[i] += matchsticks[index];
			if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) {
				return true;
			}
			edges[i] -= matchsticks[index];
		}
		return false;
	}

	bool makesquare(vector<int>& matchsticks) {
		int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
		if (totalLen % 4 != 0) {
			return false;
		}
		sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // ����������

		vector<int> edges(4);
		return dfs(0, matchsticks, edges, totalLen / 4);
	}
};



//��������״̬ѹ�� + ��̬�滮
class Solution {
public:
	bool makesquare(vector<int>& matchsticks) {
		int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
		if (totalLen % 4 != 0) {
			return false;
		}
		int len = totalLen / 4, n = matchsticks.size();
		vector<int> dp(1 << n, -1);
		dp[0] = 0;
		for (int s = 1; s < (1 << n); s++) {
			for (int k = 0; k < n; k++) {
				if ((s & (1 << k)) == 0) {
					continue;
				}
				int s1 = s & ~(1 << k);
				if (dp[s1] >= 0 && dp[s1] + matchsticks[k] <= len) {
					dp[s] = (dp[s1] + matchsticks[k]) % len;
					break;
				}
			}
		}
		return dp[(1 << n) - 1] == 0;
	}
};


/*
473. ���ƴ������
�㽫�õ�һ���������� matchsticks ������ matchsticks[i] �ǵ� i �������ĳ��ȡ���Ҫ�� ���еĻ��� ƴ��һ�������Ρ��� �����۶� �κ�һ��������������԰���������һ�𣬶���ÿ���������� ʹ��һ�� ��

�������ʹ��������Σ��򷵻� true �����򷵻� false
*/
class Solution {
public:
	vector<bool> st;

	bool makesquare(vector<int>& matchsticks) {
		int sum = 0;
		for (auto u : matchsticks) sum += u;
		if (!sum || sum % 4) return false;

		sort(matchsticks.begin(), matchsticks.end());
		reverse(matchsticks.begin(), matchsticks.end());

		st = vector<bool>(matchsticks.size());
		return dfs(matchsticks, 0, 0, sum / 4);
	}

	bool dfs(vector<int>& nums, int u, int cur, int length)
	{
		if (cur == length) u++, cur = 0;
		if (u == 4) return true;
		for (int i = 0; i < nums.size(); i++)
		{
			if (!st[i] && cur + nums[i] <= length)
			{
				st[i] = true;
				if (dfs(nums, u, cur + nums[i], length)) return true;
				st[i] = false;
				if (!cur) return false;
				if (cur + nums[i] == length) return false;
				while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
			}
		}
		return false;
	}
};



/*
473. ���ƴ������
*/
class Solution {
public:
	bool makesquare(vector<int>& matchsticks) {
		if (matchsticks.size() < 4) return false; // ����С��4
		int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
		if (sum % 4) return false; // �Ͳ���4�ı���
		sort(matchsticks.begin(), matchsticks.end(), greater<int>());
		// �Ӵ�С��������ѡ�ô�ı߿�����ɹ���������췵��
		vector<int> bucket(4); // ����4���ߵ�ֵ
		return dfs(0, matchsticks, sum / 4, bucket);
	}

	bool dfs(int index, vector<int>& matchsticks, int target, vector<int>& bucket) {
		//indexΪ��ǰ���������±꣬matchsticksΪ�߳����飬targetΪĿ��߳���bucket��ʾ��ǰÿ���ߵĳ���
		if (index >= matchsticks.size()) // ÿ���߶�����
			return (bucket[0] == bucket[1]) && (bucket[1] == target) && (bucket[2] == target);
		for (int i = 0; i < 4; i++) { // ����ǰ�ı߷���4��Ͱ�зֱ���
			if (bucket[i] + matchsticks[index] > target) continue; // ˵�������Է����������
			bucket[i] += matchsticks[index]; // �������ñߺ����dfs
			if (dfs(index + 1, matchsticks, target, bucket)) return true;
			bucket[i] -= matchsticks[index]; // ע����ݵĻָ�״̬
		}
		return false;
	}
};
