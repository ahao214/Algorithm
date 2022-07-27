#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


/*
offer 50 第一个只出现一次的字符
*/
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.empty()) return -1;

		unordered_map<char, int> hmap;
		int len = str.size();
		for (int i = 0; i < len; i++)
		{
			if (hmap.find(str[i]) == hmap.end())
				hmap.insert(make_pair(str[i], 1));
			else
				hmap[str[i]]++;
		}
		for (int i = 0; i < len; i++)
		{
			if (hmap[str[i]] == 1)
				return i;
		}
		return -1;
	}
};