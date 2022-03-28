class Solution {
public:
	bool hasAlternatingBits(int n) {
		int prev = 2;
		while (n != 0) {
			int cur = n % 2;
			if (cur == prev) {
				return false;
			}
			prev = cur;
			n /= 2;
		}
		return true;
	}

	bool hasAlternatingBits2(int n) {
		long a = n ^ (n >> 1);
		return (a & (a + 1)) == 0;
	}

};
