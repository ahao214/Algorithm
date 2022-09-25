#include<vector>
#include <functional>
#include<string>

using namespace std;

/*
788. 旋转数字
*/

//方法一：枚举每一个数
class Solution {
public:
	int rotatedDigits(int n) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			string num = to_string(i);
			bool valid = true, diff = false;
			for (char ch : num) {
				if (check[ch - '0'] == -1) {
					valid = false;
				}
				else if (check[ch - '0'] == 1) {
					diff = true;
				}
			}
			if (valid && diff) {
				++ans;
			}
		}
		return ans;
	}

private:
	static constexpr int check[10] = { 0, 0, 1, -1, -1, 1, 1, -1, 0, 1 };
};


//方法二：数位动态规划
class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());

        memset(memo, -1, sizeof(memo));
        function<int(int, bool, bool)> dfs = [&](int pos, bool bound, bool diff) -> int {
            if (pos == digits.size()) {
                return diff;
            }
            if (memo[pos][bound][diff] != -1) {
                return memo[pos][bound][diff];
            }

            int ret = 0;
            for (int i = 0; i <= (bound ? digits[pos] : 9); ++i) {
                if (check[i] != -1) {
                    ret += dfs(
                        pos + 1,
                        bound && (i == digits[pos]),
                        diff || (check[i] == 1)
                    );
                }
            }
            return memo[pos][bound][diff] = ret;
        };

        int ans = dfs(0, true, false);
        return ans;
    }

private:
    static constexpr int check[10] = { 0, 0, 1, -1, -1, 1, 1, -1, 0, 1 };
    int memo[5][2][2];
};
