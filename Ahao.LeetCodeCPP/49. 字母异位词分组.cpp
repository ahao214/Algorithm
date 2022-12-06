using namespace std;

#include<vector>
#include<string>
#include <unordered_map>
#include <queue>

/*
49. ��ĸ��λ�ʷ���
����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�

��ĸ��λ�� ������������Դ���ʵ���ĸ�õ���һ���µ��ʣ�����Դ�����е���ĸͨ��ǡ��ֻ��һ�Ρ�
*/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> record;
		for (int i = 0; i < strs.size(); i++)
		{
			string key = strs[i];
			sort(key.begin(), key.end());
			record[key].push_back(strs[i]);
		}
		vector<vector<string>> ans;
		for (auto it = record.begin(); it != record.end(); it++)
		{
			ans.push_back(it->second);
		}
		return ans;
	}
};



/*
49. ��ĸ��λ�ʷ���
����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�

��ĸ��λ�� ������������Դ���ʵ���ĸ�õ���һ���µ��ʣ�����Դ�����е���ĸͨ��ǡ��ֻ��һ�Ρ�
*/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> dict;
		for (auto& str : strs)
		{
			string key = str;
			sort(key.begin(), key.end());
			dict[key].push_back(str);
		}

		vector<vector<string>> res;
		for (auto i = dict.begin(); i != dict.end(); i++)
		{
			res.push_back(i->second);
		}
		return res;
	}
};