#include<vector>
#include<string>

using namespace std;


class Solution {
	/*
	87. 扰乱字符串
	使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
	如果字符串的长度为 1 ，算法停止
	如果字符串的长度 > 1 ，执行下述步骤：
	在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
	随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
	在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
	给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。
	*/
public:
	/*
	Times:O(n^4)
	Space:O(n^3)
	*/
	bool isScramble(string s1, string s2) {
		int n = s1.size();
		vector<vector<vector<bool>>>f(n + 1, vector<vector<bool>>(n + 1, vector<bool>(n + 1)));

		for (int k = 1; k <= n; k++)
		{
			for (int i = 0; i + k - 1 < n; i++)
			{
				for (int j = 0; j + k - 1 < n; j++)
				{
					if (k == 1)
					{
						f[i][j][k] = s1[i] == s2[j];
						continue;
					}
					for (int u = 1; u < k; u++)
					{
						bool o1 = f[i][j][u] && f[i + u][j + u][k - u];
						bool o2 = f[i][j + k - u][u] && f[i + u][j][k - u];
						if (o1 || o2)
						{
							f[i][j][k] = true;
							break;
						}
					}
				}
			}
		}
		return f[0][0][n];
	}
};
