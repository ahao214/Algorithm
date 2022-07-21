#include<vector>
#include<string>
#include<unordered_map>
#include <bitset>


using namespace std;


/*
1611. 使整数变为 0 的最少操作次数
*/

class Solution {
	unordered_map<string, int>mem;
	unordered_map<string, int>mem1;
public:
	int minimumOneBitOperations(int n)
	{
		string str = bitset<32>(n).to_string();
		return dfs(str);
	}

	int dfs(string n)
	{
		if (n == "0") return 0;
		if (n == "1") return 1;
		if (mem.find(n) != mem.end()) return mem[n];

		if (n[0] == '0') return dfs(n.substr(1));

		string m = n.substr(1);
		string p = m;
		p[0] = '1';
		for (int i = 1; i < p.size(); i++)
			p[i] = '0';
		mem[n] = dfs1(m) + 1 + dfs(p);
		return mem[n];
	}

	int dfs1(string n)
	{
		if (n == "0") return 1;
		if (n == "1") return 0;
		if (mem1.find(n) != mem1.end()) return mem1[n];

		if (n[0] == '1')
			mem1[n] = dfs(n.substr(1));
		else
		{
			string m = n.substr(1);
			string p = m;
			p[0] = '1';
			for (int i = 1; i < p.size(); i++)
				p[i] = '0';
			mem1[n] = dfs1(m) + 1 + dfs(p);
		}
		return mem1[n];
	}
};

class Solution {
public:
	int minimumOneBitOperations(int n)
	{
		if (n == 0) return 0;
		string str = bitset<32>(n).to_string();
		int i = 0;
		while (i < str.size() && str[i] == '0')
			i++;
		str = str.substr(i);

		int lastDigit = 0;
		int ret = 0;
		for (int i = 0; i < str.size(); i++)
		{
			// x ^ lastDigit = str[i]
			int x;
			if (str[i] == '1')
				x = lastDigit == 1 ? 0 : 1;
			else
				x = lastDigit == 1 ? 1 : 0;
			lastDigit = x;
			ret = ret * 2 + x;
		}

		return ret;
	}
};