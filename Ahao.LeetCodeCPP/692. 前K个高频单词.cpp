#include<vector>
#include <string>
#include <unordered_map>
#include <queue>



using namespace std;




/*
692. ǰK����Ƶ����
����һ�������б� words ��һ������ k ������ǰ k �����ִ������ĵ��ʡ�

���صĴ�Ӧ�ð����ʳ���Ƶ���ɸߵ������������ͬ�ĵ�������ͬ����Ƶ�ʣ� ���ֵ�˳�� ����
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
