#include<vector>
#include<algorithm>
#include<set>

using namespace std;


/*
offer 3 数组中重复的数字
*/
class Solution {
public:
	int duplicate(vector<int>& numbers) {
		sort(numbers.begin(), numbers.end());
		for (int i = 1; i < numbers.size(); i++)
		{
			if (numbers[i - 1] == numbers[i])
			{
				return numbers[i];
			}
		}
		return -1;
	}

	int duplicate(vector<int>& numbers) {
		set<int> s;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (s.find(numbers[i]) == s.end())
				s.insert(numbers[i]);
			else
				return numbers[i];
		}
		return -1;
	}

	int duplicate(vector<int>& numbers) {
		for (int i = 0; i < numbers.size(); i++)
		{
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
					return numbers[i];
				else
					swap(numbers[i], numbers[numbers[i]]);
			}
		}
		return -1;
	}
};


