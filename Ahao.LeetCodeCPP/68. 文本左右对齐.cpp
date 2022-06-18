#include<vector>
#include<string>

using namespace std;


class Solution {
	/*
	68. 文本左右对齐
	给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

	你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

	要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

	文本的最后一行应为左对齐，且单词之间不插入额外的空格。

	注意:

	单词是指由非空格字符组成的字符序列。
	每个单词的长度大于 0，小于等于 maxWidth。
	输入单词数组 words 至少包含一个单词。
	*/
public:
	/*
	Times:O(n*m)
	Space:O(n*m)
	m为单词的最大长度
	*/
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ans, cur;
		for (int i = 0, curWidth = 0; i < words.size(); i++)
		{
			//小于最大长度的时候
			if (words[i].length() + curWidth + cur.size() <= maxWidth)
			{
				curWidth += words[i].length();
				cur.push_back(words[i]);
			}
			else
			{
				ans.push_back(fillSpace(cur, maxWidth, false));
				cur = vector<string>{ words[i] };
				curWidth = words[i].length();
			}
		}
		//把最后的单词放入进去
		ans.push_back(fillSpace(cur, maxWidth, true));
		return ans;
	}

	string fillSpace(vector<string>& words, int maxWidth, bool last)
	{
		int curWidth = 0;
		for (int i = 0; i < words.size(); i++)
		{
			if (i != words.size() - 1) words[i] += ' ';
			curWidth += words[i].length();
		}
		if (last || words.size() == 1)
		{
			words[words.size() - 1] += string(maxWidth - curWidth, ' ');
		}
		else
		{
			for (int i = 0; curWidth++ < maxWidth; i = (i + 1) % (words.size() - 1))
			{
				words[i] += ' ';
			}
		}

		string ans;
		for (int i = 0; i < words.size(); i++)
			ans += words[i];
		return ans;
	}
};
