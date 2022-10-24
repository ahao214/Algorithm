#include<vector>

using namespace std;

/*
915. �ָ�����


����һ������ nums �����仮��Ϊ�������������� left �� right�� ʹ�ã�

left �е�ÿ��Ԫ�ض�С�ڻ���� right �е�ÿ��Ԫ�ء�
left �� right ���Ƿǿյġ�
left �ĳ���Ҫ������С��
����������ķ���󷵻� left �� ���� ��

�������Ա�֤���������Ļ��ַ�����
*/

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> minRight(n);
        minRight[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minRight[i] = min(nums[i], minRight[i + 1]);
        }

        int maxLeft = 0;
        for (int i = 0; i < n - 1; i++) {
            maxLeft = max(maxLeft, nums[i]);
            if (maxLeft <= minRight[i + 1]) {
                return i + 1;
            }
        }
        return n - 1;
    }
};


class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int leftMax = nums[0], leftPos = 0, curMax = nums[0];
        for (int i = 1; i < n - 1; i++) {
            curMax = max(curMax, nums[i]);
            if (nums[i] < leftMax) {
                leftMax = curMax;
                leftPos = i;
            }
        }
        return leftPos + 1;
    }
};

