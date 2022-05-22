using namespace std;

#include<vector>
#include<string>
#include <unordered_map>
#include <queue>

class Solution {
	/*
	49. ��ĸ��λ�ʷ���
	����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�

	��ĸ��λ�� ������������Դ���ʵ���ĸ�õ���һ���µ��ʣ�����Դ�����е���ĸͨ��ǡ��ֻ��һ�Ρ�
	*/
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