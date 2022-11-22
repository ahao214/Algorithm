#include<vector>
#include <unordered_set>
#include <string>

using namespace std;


/*
1496. 判断路径是否相交
给你一个字符串 path，其中 path[i] 的值可以是 'N'、'S'、'E' 或者 'W'，分别表示向北、向南、向东、向西移动一个单位。

你从二维平面上的原点 (0, 0) 处开始出发，按 path 所指示的路径行走。

如果路径在任何位置上与自身相交，也就是走到之前已经走过的位置，请返回 true ；否则，返回 false 。
*/
class Solution {
public:
	//定义一个哈希表，将走过的点放入到哈希表中，判断是否有重复的点
	bool isPathCrossing(string path) {
		unordered_set<string> hash;
		hash.insert("0 0");
		int x = 0, y = 0;
		for (auto c : path)
		{
			if (c == 'N') x--;
			else if (c == 'S') x++;
			else if (c == 'W') y--;
			else y++;

			string s = to_string(x) + ' ' + to_string(y);
			if (hash.count(s)) return true;
		}
		return false;
	}
};
