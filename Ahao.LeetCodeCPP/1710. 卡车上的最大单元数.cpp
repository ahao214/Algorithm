#include<vector>
#include <algorithm>

using namespace std;


/*
1710. 卡车上的最大单元数
请你将一些箱子装在 一辆卡车 上。给你一个二维数组 boxTypes ，其中 boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi] ：

numberOfBoxesi 是类型 i 的箱子的数量。
numberOfUnitsPerBoxi 是类型 i 每个箱子可以装载的单元数量。
整数 truckSize 表示卡车上可以装载 箱子 的 最大数量 。只要箱子数量不超过 truckSize ，你就可以选择任意箱子装到卡车上。

返回卡车可以装载 单元 的 最大 总数。
*/
class Solution {
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
		sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b) {
			return a[1] > b[1];
			});

		int res = 0;
		for (int i = 0; i < boxTypes.size() && truckSize > 0; i++)
		{
			int cur = min(boxTypes[i][0], truckSize);
			res += cur * boxTypes[i][1];
			truckSize -= cur;
		}
		return res;
	}
};


class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
            });
        int res = 0;
        for (auto& boxType : boxTypes) {
            int numberOfBoxes = boxType[0];
            int numberOfUnitsPerBox = boxType[1];
            if (numberOfBoxes < truckSize) {
                res += numberOfBoxes * numberOfUnitsPerBox;
                truckSize -= numberOfBoxes;
            }
            else {
                res += truckSize * numberOfUnitsPerBox;
                break;
            }
        }
        return res;
    }
};
