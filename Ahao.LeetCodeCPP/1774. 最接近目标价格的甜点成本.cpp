#include<vector>
#include <algorithm>

using namespace std;


/*
1774. ��ӽ�Ŀ��۸�����ɱ�
���������㣬������Ҫ�������ϡ�Ŀǰ���� n �ֱ�������Ϻ� m �����Ͽɹ�ѡ���������������Ҫ��ѭ���¼�������

����ѡ�� һ�� ��������ϡ�
������� һ�ֻ���� ���ϣ�Ҳ���Բ�����κ����ϡ�
ÿ�����͵����� ������� ��
���������������룺

baseCosts ��һ������Ϊ n ���������飬����ÿ�� baseCosts[i] ��ʾ�� i �ֱ�������ϵļ۸�
toppingCosts��һ������Ϊ m ���������飬����ÿ�� toppingCosts[i] ��ʾ һ�� �� i �ֱ��������ϵļ۸�
target ��һ����������ʾ����������Ŀ��۸�
��ϣ���Լ���������ܳɱ������ܽӽ�Ŀ��۸� target ��

������ӽ� target �����ɱ�������ж��ַ��������� �ɱ���Խϵ� ��һ�֡�
*/
class Solution {
public:
	int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
		int res = INT_MAX;
		int n = baseCosts.size(), m = toppingCosts.size();
		for (int i = 0; i < n; i++)
		{
			int s = baseCosts[i];
			for (int j = 0; j < 1 << m * 2; j++)
			{
				int r = s;
				bool flag = false;
				for (int k = 0; k < m; k++)
				{
					int t = j >> k * 2 & 3;
					if (t == 3)
					{
						flag = true;
						break;
					}
					r += toppingCosts[k] * t;
				}
				if (flag) continue;
				if (abs(r - target) < abs(res - target) || abs(r - target) == abs(res - target
				) && r < res)
				{
					res = r;
				}
			}
		}
		return res;
	}
};



class Solution {
public:
	void dfs(const vector<int>& toppingCosts, int p, int curCost, int& res, const int& target) {
		if (abs(res - target) < curCost - target) {
			return;
		}
		else if (abs(res - target) >= abs(curCost - target)) {
			if (abs(res - target) > abs(curCost - target)) {
				res = curCost;
			}
			else {
				res = min(res, curCost);
			}
		}
		if (p == toppingCosts.size()) {
			return;
		}
		dfs(toppingCosts, p + 1, curCost + toppingCosts[p] * 2, res, target);
		dfs(toppingCosts, p + 1, curCost + toppingCosts[p], res, target);
		dfs(toppingCosts, p + 1, curCost, res, target);
	}

	int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
		int res = *min_element(baseCosts.begin(), baseCosts.end());
		for (auto& b : baseCosts) {
			dfs(toppingCosts, 0, b, res, target);
		}
		return res;
	}
};
