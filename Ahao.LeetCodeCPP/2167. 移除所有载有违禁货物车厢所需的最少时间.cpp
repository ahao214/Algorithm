#include<vector>
#include <string>

using namespace std;


/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */



 /*
2167. 移除所有载有违禁货物车厢所需的最少时间
给你一个下标从 0 开始的二进制字符串 s ，表示一个列车车厢序列。s[i] = '0' 表示第 i 节车厢 不 含违禁货物，而 s[i] = '1' 表示第 i 节车厢含违禁货物。

作为列车长，你需要清理掉所有载有违禁货物的车厢。你可以不限次数执行下述三种操作中的任意一个：

从列车 左 端移除一节车厢（即移除 s[0]），用去 1 单位时间。
从列车 右 端移除一节车厢（即移除 s[s.length - 1]），用去 1 单位时间。
从列车车厢序列的 任意位置 移除一节车厢，用去 2 单位时间。
返回移除所有载有违禁货物车厢所需要的 最少 单位时间数。

注意，空的列车车厢序列视为没有车厢含违禁货物。
*/
class Solution {
public:
	int minimumTime(string s)
	{
		int n = s.size();
		vector<int>a(n + 5);
		for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
		int now = 1e9;
		int ans = now;
		for (int i = n; i >= 0; i--)
		{
			now = min(now + 2 * a[i + 1], n - i);
			ans = min(ans, now + i);
		}
		return ans;
	}
};



class Solution {
public:
	int minimumTime(string s)
	{
		int n = s.size();
		vector<int> left(n + 1);
		vector<int> right(n + 1);

		for (int i = 0; i < n; i++) {
			left[i + 1] = left[i];
			if (s[i] == '1') {
				left[i + 1] += 2;
			}
			left[i + 1] = min(left[i + 1], i + 1);
		}

		int ans = n;
		for (int i = n - 1; i >= 0; i--) {
			right[i] = right[i + 1];
			if (s[i] == '1') {
				right[i] += 2;
			}
			right[i] = min(right[i], n - i);
			ans = min(ans, right[i] + left[i]);
		}
		return ans;
	}
};


const int MAXN = 2e5 + 50;
int dp[MAXN];
class Solution {
public:
	int minimumTime(string s) {
		int n = s.size();
		int ans = n;
		dp[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			dp[i] = min(dp[i + 1], n - i - 1) + (s[i] == '1' ? 2 : 0);
		}
		for (int i = 0; i < n; i++) {
			ans = min(ans, i + min(dp[i], n - i));
		}
		return ans;
	}
};