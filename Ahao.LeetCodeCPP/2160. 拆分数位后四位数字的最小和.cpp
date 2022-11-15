#include<vector>
#include <algorithm>


using namespace std;


/*
2160. 拆分数位后四位数字的最小和
给你一个四位 正 整数 num 。请你使用 num 中的 数位 ，将 num 拆成两个新的整数 new1 和 new2 。new1 和 new2 中可以有 前导 0 ，且 num 中 所有 数位都必须使用。

比方说，给你 num = 2932 ，你拥有的数位包括：两个 2 ，一个 9 和一个 3 。一些可能的 [new1, new2] 数对为 [22, 93]，[23, 92]，[223, 9] 和 [2, 329] 。
请你返回可以得到的 new1 和 new2 的 最小 和。
*/
class Solution {
public:
	int minimumSum(int num) {
		vector<int> vNum;
		for (int i = 0; i < 4; i++) {
			vNum.push_back(num % 10);
			num /= 10;
		}
		sort(vNum.begin(), vNum.end());
		int n1 = vNum[0] * 10 + vNum[2];
		int n2 = vNum[1] * 10 + vNum[3];
		return n1 + n2;
	}
};
