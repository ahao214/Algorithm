#include<vector>
#include <string>
#include <stack>

using namespace std;


/*
2434. 使用机器人打印字典序最小的字符串

给你一个字符串 s 和一个机器人，机器人当前有一个空字符串 t 。执行以下操作之一，直到 s 和 t 都变成空字符串：

删除字符串 s 的 第一个 字符，并将该字符给机器人。机器人把这个字符添加到 t 的尾部。
删除字符串 t 的 最后一个 字符，并将该字符给机器人。机器人将该字符写到纸上。
请你返回纸上能写出的字典序最小的字符串。
*/
class Solution {
public:
	string robotWithString(string s) {
		int n = s.size();
		stack<char> st;
		vector<int> sufSmallest(n);
		char curSmallest = 'z' + 1;
		for (int i = n - 1; i >= 0; i--)
		{
			curSmallest = min(curSmallest, s[i]);
			sufSmallest[i] = curSmallest;
		}

		string res;
		int i = 0;
		while (i < n)
		{
			if (st.empty() || sufSmallest[i] < st.top())
			{
				st.push(s[i]);
				i++;
			}
			else
			{
				res.push_back(st.top());
				st.pop();
			}
		}
		while (!st.empty())
		{
			res.push_back(st.top());
			st.pop();
		}

		return res;
	}
};
