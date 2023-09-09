using namespace std;


class Solution {
public:
	int trailingZeroes(int n) {
		int ans = 0;
		for (int i = 5; i <= n; i += 5) {
			for (int x = i; x % 5 == 0; x /= 5) {
				++ans;
			}
		}
		return ans;
	}
};


class Solution {
public:
	int trailingZero1(int n) {
		int ans = 0;
		while (n) {
			n /= 5;
			ans += n;
		}
		return n;
	}
};



/*
172. 阶乘后的零
时间O(NLogN) 空间O(1)
*/

class Solution {
public:
	int trailingZeroes(int n) {
		int res = 0;
		int multiple = 5;
		while (n >= multiple)
		{
			res += n / multiple;
			multiple *= 5;
		}
		return res;
	}
};




class Solution {
public:
	int trailingZeroes(int n) {
		int res = 0;
		while (n)
		{
			res += n / 5;
			n /= 5;
		}
		return res;
	}
};
