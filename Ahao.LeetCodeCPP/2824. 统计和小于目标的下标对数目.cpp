#include<vector>
#include <algorithm>

using namespace std;

/*
2824. ͳ�ƺ�С��Ŀ����±����Ŀ

����һ���±�� 0 ��ʼ����Ϊ n ���������� nums ��һ������ target �����㷵������ 0 <= i < j < n �� nums[i] + nums[j] < target ���±�� (i, j) ����Ŀ��
*/

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] < target) {
                    res++;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            int k = lower_bound(nums.begin(), nums.begin() + i, target - nums[i]) - nums.begin();
            res += k;
        }
        return res;
    }
};




class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0, j = nums.size() - 1; i < j; i++) {
            while (i < j && nums[i] + nums[j] >= target) {
                j--;
            }
            res += j - i;
        }
        return res;
    }
};
