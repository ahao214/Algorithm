#include<vector>

using namespace std;



//157.用Read4读取N个字符
//时间O(N) 空间O(1)
class Solution {
public:
	int read(char* buf, int n) {
		int ans = 0;
		while (ans < n) {
			int cnt = read4(buf + ans);
			ans += cnt;
			if (cnt < 4)
				break;
		}
		return min(ans, n);
	}
};