#include<vector>

using namespace std;




/*
158.ÓÃRead4¶ÁÈ¡N¸ö×Ö·ûII
*/
class Solution {
	char* cache = new char[4];
	int c_idx = 0, c_size = 0;
public:
	int read(char* buf, int n) {
		int ans = 0;
		while (ans < n) {
			while (c_idx < c_size && ans < n)
			{
				buf[ans++] = cache[c_idx++];
			}
			if (ans < n)
			{
				c_size = read4(cache);
				c_idx = 0;
				if (c_size == 0)
					break;
			}
		}
		return ans;
	}
};

