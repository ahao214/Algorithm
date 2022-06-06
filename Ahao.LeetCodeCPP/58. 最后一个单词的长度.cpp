using namespace std;

#include<string>


class Solution {
	/*
	58. 最后一个单词的长度
	给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

	单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
	*/
public:
	int lengthOfLastWord(string s) {
		/*
		从右向左遍历,记录下第一个非空格的位置,然后继续遍历
		遍历到下一个空格的位置,记录下该位置
		两个位置相减即为答案
		Times:O(n)
		Space:O(1)
		*/

		for (int i = s.size() - 1; i >= 0; i--)
		{
			//遇见空格继续
			if (s[i] == ' ') continue;
			int j = i - 1;
			while (j >= 0 && s[j] != ' ')
				j--;
			return i - j;
		}
		return 0;
	}
};