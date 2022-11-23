#include<vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;


/*
1487. 保证文件名唯一
给你一个长度为 n 的字符串数组 names 。你将会在文件系统中创建 n 个文件夹：在第 i 分钟，新建名为 names[i] 的文件夹。

由于两个文件 不能 共享相同的文件名，因此如果新建文件夹使用的文件名已经被占用，系统会以 (k) 的形式为新文件夹的文件名添加后缀，其中 k 是能保证文件名唯一的 最小正整数 。

返回长度为 n 的字符串数组，其中 ans[i] 是创建第 i 个文件夹时系统分配给该文件夹的实际名称。
*/
class Solution {
public:
	//超时了
	vector<string> getFolderNames(vector<string>& names) {
		unordered_set<string> hash;

		vector<string> res;
		for (auto name : names)
		{
			string suc;
			int k = 0;
			while (hash.count(name + suc))
			{
				k++;
				suc = "(" + to_string(k) + ")";
			}
			hash.insert(name + suc);
			res.push_back(name + suc);
		}
		return res;
	}


	vector<string> getFolderNames(vector<string>& names) {
		unordered_map<string, int> cnt;
		unordered_set<string> hash;

		vector<string> res;
		for (auto name : names)
		{
			string suc;
			int k = 0;
			if (cnt.count(name)) k = cnt[name];

			while (hash.count(name + suc))
			{
				k++;
				suc = "(" + to_string(k) + ")";
			}

			cnt[name] = k;
			hash.insert(name + suc);
			res.push_back(name + suc);
		}
		return res;
	}
};
