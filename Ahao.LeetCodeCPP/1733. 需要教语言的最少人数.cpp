#include<vector>

using namespace std;


/*
1733. 需要教语言的最少人数
在一个由 m 个用户组成的社交网络里，我们获取到一些用户之间的好友关系。两个用户之间可以相互沟通的条件是他们都掌握同一门语言。

给你一个整数 n ，数组 languages 和数组 friendships ，它们的含义如下：

总共有 n 种语言，编号从 1 到 n 。
languages[i] 是第 i 位用户掌握的语言集合。
friendships[i] = [u​​​​​​i​​​, v​​​​​​i] 表示 u​​​​​​​​​​​i​​​​​ 和 vi 为好友关系。
你可以选择 一门 语言并教会一些用户，使得所有好友之间都可以相互沟通。请返回你 最少 需要教会多少名用户。

请注意，好友关系没有传递性，也就是说如果 x 和 y 是好友，且 y 和 z 是好友， x 和 z 不一定是好友。
*/
class Solution {
public:
	int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
		int m = languages.size();
		vector<vector<bool>> g(m + 1, vector<bool>(n + 1));
		for (int i = 0; i < languages.size(); i++)
		{
			for (auto x : languages[i])
			{
				g[i + 1][x] = true;
			}
		}

		set<int> persons;
		for (auto& f : friendships)
		{
			int x = f[0], y = f[1];
			bool flag = false;
			for (int i = 1; i <= n; i++)
			{
				if (g[x][i] && g[y][i])
				{
					flag = true;
					break;
				}
			}
			if (flag) continue;
			persons.insert(x), persons.insert(y);
		}

		int s = 0;
		vector<int> cnt(n + 1);
		for (auto x : persons)
		{
			for (int i = 1; i <= n; i++)
			{
				if (g[x][i])
				{
					cnt[i]++;
					s = max(s, cnt[i]);
				}
			}
		}
		return persons.size() - s;
	}
};

