#include <algorithm>

using namespace std;

/*
440. 字典序的第K小数字
给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。
*/
class Solution {
public:
	typedef long long ll;
	int f(int cur, ll n)
	{
		//返回以cur开头的数字的数量
		//cur
		//0-9
		//00-09
		ll left = cur, right = cur;
		int res = 0;
		while (left <= n)
		{
			res += min(right, n) - left + 1;
			left = left * 10;
			right = right * 10 + 9;
		}
	}
	int findKthNumber(int n, int k) {
		int cur = 1;
		k--;
		while (k > 0)
		{
			int num = f(cur, n);
			if (k < num)
			{
				k -= 1;
				cur *= 10;
			}
			else {
				k -= num;
				cur++;
			}
		}
		return cur;
	}
};


class Solution {
public:
	int getSteps(int curr, long n) {
		int steps = 0;
		long first = curr;
		long last = curr;
		while (first <= n) {
			steps += min(last, n) - first + 1;
			first = first * 10;
			last = last * 10 + 9;
		}
		return steps;
	}

	int findKthNumber(int n, int k) {
		int curr = 1;
		k--;
		while (k > 0) {
			int steps = getSteps(curr, n);
			if (steps <= k) {
				k -= steps;
				curr++;
			}
			else {
				curr = curr * 10;
				k--;
			}
		}
		return curr;
	}
};
