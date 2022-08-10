#include<vector>
#include<string>

using namespace std;



/*
1880. 检查某单词是否等于两单词之和
字母的 字母值 取决于字母在字母表中的位置，从 0 开始 计数。即，'a' -> 0、'b' -> 1、'c' -> 2，以此类推。

对某个由小写字母组成的字符串 s 而言，其 数值 就等于将 s 中每个字母的 字母值 按顺序 连接 并 转换 成对应整数。

例如，s = "acb" ，依次连接每个字母的字母值可以得到 "021" ，转换为整数得到 21 。
给你三个字符串 firstWord、secondWord 和 targetWord ，每个字符串都由从 'a' 到 'j' （含 'a' 和 'j' ）的小写英文字母组成。

如果 firstWord 和 secondWord 的 数值之和 等于 targetWord 的数值，返回 true ；否则，返回 false 。
*/
class Solution {
public:
	int get(string s)
	{
		int res = 0;
		for (auto c : s)
			res = res * 10 + c - 'a';
		return res;
	}

	bool isSumEqual(string firstWord, string secondWord, string targetWord) {
		return get(firstWord) + get(secondWord) == get(targetWord);
	}

};


