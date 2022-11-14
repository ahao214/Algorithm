#include<vector>

using namespace std;



/*
2162. 设置时间的最少代价
常见的微波炉可以设置加热时间，且加热时间满足以下条件：

至少为 1 秒钟。
至多为 99 分 99 秒。
你可以 最多 输入 4 个数字 来设置加热时间。如果你输入的位数不足 4 位，微波炉会自动加 前缀 0 来补足 4 位。微波炉会将设置好的四位数中，前 两位当作分钟数，后 两位当作秒数。它们所表示的总时间就是加热时间。比方说：

你输入 9 5 4 （三个数字），被自动补足为 0954 ，并表示 9 分 54 秒。
你输入 0 0 0 8 （四个数字），表示 0 分 8 秒。
你输入 8 0 9 0 ，表示 80 分 90 秒。
你输入 8 1 3 0 ，表示 81 分 30 秒。
给你整数 startAt ，moveCost ，pushCost 和 targetSeconds 。一开始，你的手指在数字 startAt 处。将手指移到 任何其他数字 ，需要花费 moveCost 的单位代价。每 输入你手指所在位置的数字一次，需要花费 pushCost 的单位代价。

要设置 targetSeconds 秒的加热时间，可能会有多种设置方法。你想要知道这些方法中，总代价最小为多少。

请你能返回设置 targetSeconds 秒钟加热时间需要花费的最少代价。

请记住，虽然微波炉的秒数最多可以设置到 99 秒，但一分钟等于 60 秒。
*/
class Solution {
public:
	void getData(int mini, int sec, vector<int>& vData) {
		vData.push_back(sec % 10);
		sec /= 10;
		vData.push_back(sec % 10);
		vData.push_back(mini % 10);
		mini /= 10;
		vData.push_back(mini % 10);
		while (vData.back() == 0) {
			vData.pop_back();
		}
		reverse(vData.begin(), vData.end());
	}

	int slove(int startAt, int moveCost, int pushCost, int mini, int sec) {
		vector<int> vData;
		getData(mini, sec, vData);
		int at = startAt;
		int res = 0;
		for (auto x : vData) {
			if (at != x) {
				at = x;
				res += moveCost;
			}
			res += pushCost;
		}
		return res;
	}

	int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
		int mini = targetSeconds / 60;
		int sec = targetSeconds % 60;

		if (mini >= 100) {
			sec += 60;
			mini--;
		}

		int ans = slove(startAt, moveCost, pushCost, mini, sec);

		if (mini >= 1 && sec < 40) {
			sec += 60;
			mini--;
			int ans1 = slove(startAt, moveCost, pushCost, mini, sec);
			ans = min(ans, ans1);
		}
		return ans;
	}
};



class Solution {
public:
	int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
		int ans = 4 * (moveCost + pushCost);

		for (int s = 0; s <= 9999; s += 1) {
			int mi = s / 100, sec = s % 100;
			if (mi * 60 + sec == targetSeconds) {
				int cur = 0;
				int v[4], x = s, last = startAt;
				for (int i = 0; i < 4; i++) {
					v[i] = x % 10, x /= 10;
				}
				reverse(v, v + 4);
				bool flag = false;
				for (int i = 0; i < 4; i++) {
					if (v[i] == 0 && flag == false) continue;
					flag = true;
					if (last == v[i]) {
						cur += pushCost;
					}
					else {
						cur += moveCost + pushCost;
						last = v[i];
					}
				}
				ans = min(ans, cur);
			}
		}
		return ans;
	}
};