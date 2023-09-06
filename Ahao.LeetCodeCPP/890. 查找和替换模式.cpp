using namespace std;
#include<vector>
#include<string>
#include <unordered_map>


/*
890. ���Һ��滻ģʽ

����һ�������б� words ��һ��ģʽ  pattern������֪�� words �е���Щ������ģʽƥ�䡣

���������ĸ������ p ��ʹ�ý�ģʽ�е�ÿ����ĸ x �滻Ϊ p(x) ֮�����Ǿ͵õ�������ĵ��ʣ���ô������ģʽ��ƥ��ġ�

������һ�£���ĸ�������Ǵ���ĸ����ĸ��˫�䣺ÿ����ĸӳ�䵽��һ����ĸ��û��������ĸӳ�䵽ͬһ����ĸ����

���� words �������ģʽƥ��ĵ����б�

����԰��κ�˳�򷵻ش𰸡�
*/


class Solution {
	bool match(string& word, string& pattern) {
		unordered_map<char, char> mp;
		for (int i = 0; i < word.length(); ++i) {
			char x = word[i], y = pattern[i];
			if (!mp.count(x)) {
				mp[x] = y;
			}
			else if (mp[x] != y) { // word �е�ͬһ��ĸ����ӳ�䵽 pattern �е�ͬһ��ĸ��
				return false;
			}
		}
		return true;
	}

public:
	vector<string> findAndReplacePattern(vector<string>& words, string& pattern) {
		vector<string> ans;
		for (auto& word : words) {
			if (match(word, pattern) && match(pattern, word)) {
				ans.emplace_back(word);
			}
		}
		return ans;
	}
};



class Solution {
	string p(string word)
	{
		unordered_map<char, int> dict;
		for (auto w : word)
		{
			if (!dict.count(w))
				dict[w] = dict.size();
		}
		for (int i = 0; i < word.size(); i++)
			word[i] = 'a' + dict[word[i]];
		return word;
	}
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string>res;
		string pa = p(pattern);
		for (auto word : words)
		{
			if (p(word) == pa)
			{
				res.push_back(word);
			}
		}
		return res;
	}
};
