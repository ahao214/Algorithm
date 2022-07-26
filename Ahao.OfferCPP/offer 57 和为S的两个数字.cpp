#include<vector>

using namespace std;


/*
offer 57 ��ΪS����������
*/
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> ans;
		int left = 0, right = array.size() - 1;
		while (left < right)
		{
			if (array[left] + array[right] == sum)
			{
				ans.push_back(array[left]);
				ans.push_back(array[right]);
				break;
			}
			else if (array[left] + array[right] < sum)
			{
				++left;
			}
			else
			{
				--right;
			}
		}
		return ans;
	}
};

