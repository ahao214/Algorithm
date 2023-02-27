#include<vector>


using namespace std;


/*
1144. 递减元素使数组呈锯齿状

给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。

如果符合下列情况之一，则数组 A 就是 锯齿数组：

每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
返回将数组 nums 转换为锯齿数组所需的最小操作次数。
*/

class Solution {
public:
    int help(vector<int>& nums, int pos) {
        int res = 0;
        for (int i = pos; i < nums.size(); i += 2) {
            int a = 0;
            if (i - 1 >= 0) {
                a = max(a, nums[i] - nums[i - 1] + 1);
            }
            if (i + 1 < nums.size()) {
                a = max(a, nums[i] - nums[i + 1] + 1);
            }
            res += a;
        }
        return res;
    }

    int movesToMakeZigzag(vector<int>& nums) {
        return min(help(nums, 0), help(nums, 1));
    }
};
