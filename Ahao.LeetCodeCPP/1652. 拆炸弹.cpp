#include<vector>

using namespace std;



/*
1652. 拆炸弹
你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 n 的 循环 数组 code 以及一个密钥 k 。

为了获得正确的密码，你需要替换掉每一个数字。所有数字会 同时 被替换。

如果 k > 0 ，将第 i 个数字用 接下来 k 个数字之和替换。
如果 k < 0 ，将第 i 个数字用 之前 k 个数字之和替换。
如果 k == 0 ，将第 i 个数字用 0 替换。
由于 code 是循环的， code[n-1] 下一个元素是 code[0] ，且 code[0] 前一个元素是 code[n-1] 。

给你 循环 数组 code 和整数密钥 k ，请你返回解密后的结果来拆除炸弹！
*/

class Solution {
public:
	vector<int> decrypt(vector<int>& code, int k) {
		int n = code.size();
		vector<int> res(n);
		if (k == 0) {
			return res;
		}
		code.resize(n * 2);
		copy(code.begin(), code.begin() + n, code.begin() + n);
		int l = k > 0 ? 1 : n + k;
		int r = k > 0 ? k : n - 1;
		int w = 0;
		for (int i = l; i <= r; i++) {
			w += code[i];
		}
		for (int i = 0; i < n; i++) {
			res[i] = w;
			w -= code[l];
			w += code[r + 1];
			l++;
			r++;
		}
		return res;
	}
};




class Solution {
public:
	vector<int> decrypt(vector<int>& code, int k) {
		int n = code.size();
		vector<int> res(n);
		for (int i = 0; i < n; i++)
		{
			if (k == 0) res[i] = 0;
			else if (k > 0)
			{
				for (int j = 1; j <= k; j++)
					res[i] += code[(i + j) % n];
			}
			else {
				for (int j = -1; j >= k; j--)
					res[i] += code[(i + j + n) % n];
			}
		}
		return res;
	}
};