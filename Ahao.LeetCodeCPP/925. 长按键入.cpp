#include<vector>
#include<string>

using namespace std;


/*
925. 长按键入

你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。

你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
*/
class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int i = 0, j = 0;
		while (i < name.size() && j < typed.size())
		{
			if (name[i] != typed[j]) return false;
			int x = i + 1, y = j + 1;
			while (x < name.size() && name[x] == name[i])
				x++;
			while (y < typed.size() && typed[y] == typed[j])
				y++;
			if (x - i > y - j)
				return false;
			i = x, j = y;
		}
		return i == name.size() && j == typed.size();
	}
};