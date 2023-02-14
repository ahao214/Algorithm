#include<vector>

using namespace std;


/*
2555. 两个线段获得的最多奖品

在 X轴 上有一些奖品。给你一个整数数组 prizePositions ，它按照 非递减 顺序排列，其中 prizePositions[i] 是第 i 件奖品的位置。数轴上一个位置可能会有多件奖品。再给你一个整数 k 。

你可以选择两个端点为整数的线段。每个线段的长度都必须是 k 。你可以获得位置在任一线段上的所有奖品（包括线段的两个端点）。注意，两个线段可能会有相交。

比方说 k = 2 ，你可以选择线段 [1, 3] 和 [2, 4] ，你可以获得满足 1 <= prizePositions[i] <= 3 或者 2 <= prizePositions[i] <= 4 的所有奖品 i 。
请你返回在选择两个最优线段的前提下，可以获得的 最多 奖品数目。
*/
class Solution {
public:
	int maximizeWin(vector<int>& prizePositions, int k) {
		int n = prizePositions.size();
		if (prizePositions[n - 1] - prizePositions[0] <= 2 * k)
			return prizePositions.size();

		vector<int> pre(n);
		vector<int> post(n);

		int i = 0;
		int mx = 0;

		for (int j = 0; j < n; j++) {
			while (prizePositions[j] - prizePositions[i] > k)
				i++;
			int len = j - i + 1;
			mx = max(mx, len);
			pre[j] = mx;
		}

		int j = n - 1;
		mx = 0;
		for (int i = n - 1; i >= 0; i--) {
			while (prizePositions[j] - prizePositions[i] > k)
				j--;
			int len = j - i + 1;
			mx = max(mx, len);
			post[i] = mx;
		}
		int res = 0;
		for (int k = 0; k + 1 < n; k++) {
			res = max(res, pre[k] + post[k + 1]);
		}
		return res;
	}
};