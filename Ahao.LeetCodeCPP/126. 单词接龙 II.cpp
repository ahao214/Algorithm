#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>


using namespace std;


/*
126. ���ʽ��� II

���ֵ� wordList ��ɴӵ��� beginWord ������ endWord ת����һ����ʾ�˹��̵� ת������ ����ʽ���� beginWord -> s1 -> s2 -> ... -> sk �����ĵ������У������㣺

ÿ�����ڵĵ���֮����е�����ĸ��ͬ��
ת�������е�ÿ������ si��1 <= i <= k���������ֵ� wordList �еĵ��ʡ�ע�⣬beginWord �������ֵ� wordList �еĵ��ʡ�
sk == endWord
������������ beginWord �� endWord ���Լ�һ���ֵ� wordList �������ҳ����������д� beginWord �� endWord �� ���ת������ �����������������ת�����У�����һ�����б�ÿ�����ж�Ӧ���Ե����б� [beginWord, s1, s2, ..., sk] ����ʽ���ء�
*/
class Solution {
	unordered_map<string, vector<string>> children;
	vector<vector<string>> ans;
	vector<string> path;
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		if (!dict.count(endWord)) return ans;

		unordered_set<string> s1{ beginWord }, s2{ endWord };

		bool found = false, beginToEnd = true;

		while (!s1.empty() && !s2.empty() && !found)
		{
			if (s1.size() > s2.size())
			{
				swap(s1, s2);
				beginToEnd = !beginToEnd;
			}

			for (string w : s1) dict.erase(w);
			for (string w : s2) dict.erase(w);

			unordered_set<string> s;
			for (string word : s1)
			{
				string cur = word;
				for (int i = 0; i < word.size(); i++)
				{
					char ch = word[i];
					for (char j = 'a'; j <= 'z'; j++)
					{
						word[i] = j;
						string parent = cur, child = word;
						if (!beginToEnd)
							swap(parent, child);
						if (s2.count(word))
						{
							found = true;
							children[parent].push_back(child);
						}
						else if (dict.count(word) && !found)
						{
							s.insert(word);
							children[parent].push_back(child);
						}
					}
					word[i] = ch;
				}
			}
			s1 = s;
		}
		if (found)
		{
			path.push_back(beginWord);
			dfs(beginWord, endWord);
		}
		return ans;
	}

	void dfs(string word, string endWord)
	{
		if (word == endWord)
		{
			ans.push_back(path);
			return;
		}
		for (string child : children[word])
		{
			path.push_back(child);
			dfs(child, endWord);
			path.pop_back();
		}
	}
};

