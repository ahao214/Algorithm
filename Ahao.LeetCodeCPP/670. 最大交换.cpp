#include<vector>
#include <string>

using namespace std;


//方法一：直接遍历
class Solution {
public:
	int maximumSwap(int num) {
		string charArray = to_string(num);
		int n = charArray.size();
		int maxNum = num;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				swap(charArray[i], charArray[j]);
				maxNum = max(maxNum, stoi(charArray));
				swap(charArray[i], charArray[j]);
			}
		}
		return maxNum;
	}
};

//方法二：贪心
class Solution {
public:
	int maximumSwap(int num) {
		string charArray = to_string(num);
		int n = charArray.size();
		int maxIdx = n - 1;
		int idx1 = -1, idx2 = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (charArray[i] > charArray[maxIdx]) {
				maxIdx = i;
			}
			else if (charArray[i] < charArray[maxIdx]) {
				idx1 = i;
				idx2 = maxIdx;
			}
		}
		if (idx1 >= 0) {
			swap(charArray[idx1], charArray[idx2]);
			return stoi(charArray);
		}
		else {
			return num;
		}
	}
};
