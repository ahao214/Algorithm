#include<vector>
#include <string>
#include <unordered_map>
#include <queue>



using namespace std;




/*
692. 前K个高频单词
给定一个单词列表 words 和一个整数 k ，返回前 k 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率， 按字典顺序 排序。
*/
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> hash;
		typedef pair<int, string> PIS;
		priority_queue<PIS> heap;

		for (auto word : words) hash[word]++;

		for (auto item : hash)
		{
			PIS t(-item.second, item.first);
			heap.push(t);
			if (heap.size() > k) heap.pop();
		}

		vector<string> res(k);
		for (int i = k - 1; i >= 0; i--)
		{
			res[i] = heap.top().second;
			heap.pop();
		}
		return res;
	}
};
