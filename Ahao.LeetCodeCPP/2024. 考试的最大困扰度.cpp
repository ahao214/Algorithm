#include<vector>
#include <string>

using namespace std;


/*
2024. 考试的最大困扰度

一位老师正在出一场由 n 道判断题构成的考试，每道题的答案为 true （用 'T' 表示）或者 false （用 'F' 表示）。老师想增加学生对自己做出答案的不确定性，方法是 最大化 有 连续相同 结果的题数。（也就是连续出现 true 或者连续出现 false）。

给你一个字符串 answerKey ，其中 answerKey[i] 是第 i 个问题的正确结果。除此以外，还给你一个整数 k ，表示你能进行以下操作的最多次数：

每次操作中，将问题的正确答案改为 'T' 或者 'F' （也就是将 answerKey[i] 改为 'T' 或者 'F' ）。
请你返回在不超过 k 次操作的情况下，最大 连续 'T' 或者 'F' 的数目。
*/
class Solution {
public:
	int lts(const string& s, int k, char c)
	{
		int n = s.size(), left = 0, right = 0, s1 = 0, s2 = 0, res = 0;
		while (right < n)
		{
			if (s[right] != c) s2++;
			while (s2 - s1 > k)
			{
				if (s[left] != c) s1++;
				left++;
			}
			res = max(res, right - left + 1);
		}
		return res;
	}

	int maxConsecutiveAnswers(string answerKey, int k) {
		return max(lts(answerKey, k, 'T'), lts(answerKey, k, 'F'));
	}
};