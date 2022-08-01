#include<vector>
#include<string>

using namespace std;


/*
offer 20 表示数值的字符串
*/
class Solution {
public:
	bool isNumeric(string str) {
		if (str.empty())
			return false;
		size_t nPos = 0;
		nPos = str.find(" ", nPos);
		while (nPos != string::npos)
		{
			str.replace(nPos, 1, "");
			nPos = str.find(" ", nPos);
		}
		int idx = 0;
		bool numeric = scanInt(str, idx);
		if (str[idx] == '.')
		{
			++idx;
			numeric = scanUnInt(str, idx) || numeric;
		}
		if (str[idx] == 'e' || str[idx] == 'E')
		{
			++idx;
			numeric = scanInt(str, idx) && numeric;
		}
		return numeric && (idx == str.size());
	}

	bool scanInt(string& str, int& idx)
	{
		if (str[idx] == '+' || str[idx] == '-')
		{
			++idx;
		}
		return scanUnInt(str, idx);
	}


	bool scanUnInt(string& str, int& idx)
	{
		int start = idx;
		while (str[idx] != '\0' && str[idx] >= '0' && str[idx] <= '9')
		{
			++idx;
		}
		return idx > start;
	}
};
