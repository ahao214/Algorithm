#include<vector>

using namespace std;


/*
1007. 行相等的最少多米诺旋转
在一排多米诺骨牌中，A[i] 和 B[i] 分别代表第 i 个多米诺骨牌的上半部分和下半部分。（一个多米诺是两个从 1 到 6 的数字同列平铺形成的 —— 该平铺的每一半上都有一个数字。）

我们可以旋转第 i 张多米诺，使得 A[i] 和 B[i] 的值交换。

返回能使 A 中所有值或者 B 中所有值都相同的最小旋转次数。

如果无法做到，返回 -1.
*/
class Solution {
public:
	int helper(int val, vector<int>& A, vector<int>& B)
	{
		int n = A.size();
		int countA = 0, countB = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i] != val && B[i] != val)
			{
				return -1;
			}
			else if (A[i] != val)
			{
				countA++;
			}
			else if (B[i] != val)
			{
				countB++;
			}
		}
		return min(countA, countB);
	}

	int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
		int rotation = helper(tops[0], tops, bottoms);
		if (rotation != -1 || tops[0] == bottoms[0])
			return rotation;
		else
			return helper(bottoms[0], tops, bottoms);
	}
};

