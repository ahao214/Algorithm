#include<vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;



/*
127. ���ʽ���
�ֵ� wordList �дӵ��� beginWord �� endWord �� ת������ ��һ������������γɵ����� beginWord -> s1 -> s2 -> ... -> sk��

ÿһ�����ڵĵ���ֻ��һ����ĸ��
 ���� 1 <= i <= k ʱ��ÿ�� si ���� wordList �С�ע�⣬ beginWord ����Ҫ�� wordList �С�
sk == endWord
������������ beginWord �� endWord ��һ���ֵ� wordList ������ �� beginWord �� endWord �� ���ת������ �е� ������Ŀ �����������������ת�����У����� 0 ��
*/
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		queue<string> q;
		unordered_set<string> wordSet(wordList.begin(), wordList.end());
		if (!wordSet.count(endWord))
		{
			return 0;
		}
		q.push(beginWord);
		int level = 1;
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				string cur = q.front();
				q.pop();
				if (cur == endWord)
					return level;
				wordSet.erase(cur);
				for (int j = 0; j < cur.size(); j++)
				{
					char tmp = cur[j];
					for (int k = 0; k < 26; k++)
					{
						cur[j] = 'a' + k;
						if (wordSet.count(cur))
						{
							q.push(cur);
						}
					}
					cur[j] = tmp;
				}
			}
			level++;
		}
		return 0;
	}
};