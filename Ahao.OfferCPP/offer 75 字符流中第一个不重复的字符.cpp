#include<vector>
#include<unordered_map>


using namespace std;



/*
offer 75 字符流中第一个不重复的字符
*/
class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch) {
		//判断hmap是否有ch这个字符
		if (hmap.find(ch) == hmap.end())
			hmap.insert(make_pair(ch, 1));
		else
			hmap[ch]++;
		v.push_back(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce() {
		for (auto i : v) {
			if (hmap[i] == 1)
				return i;
		}
		return '#';
	}

private:
	unordered_map<char, int> hmap;
	vector<char> v;
};
