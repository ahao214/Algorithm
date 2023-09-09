#include<unordered_map>

using namespace std;


/*
170. 两数之和(3)-数据结构设计
*/

class TwoSum {
	unordered_map<int, int> record;
public:
	TwoSum()
	{

	}

	void add(int number)
	{
		record[number]++;
	}

	bool find(int value)
	{
		if (value < -2e5 || value > 2e5)
			return false;
		for (auto& [k, v] : record) {
			int target = value - k;
			if (target == k && v > 1)
				return true;
			if (target != k && record.count(target))
				return true;
		}
		return false;
	}
};
