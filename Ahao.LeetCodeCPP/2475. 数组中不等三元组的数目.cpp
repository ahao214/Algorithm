#include<vector>
#include <algorithm>


using namespace std;

/*
2475. �����в�����Ԫ�����Ŀ

����һ���±�� 0 ��ʼ������������ nums �������ҳ���ͳ������������������Ԫ�� (i, j, k) ����Ŀ��

0 <= i < j < k < nums.length
nums[i]��nums[j] �� nums[k] ������ͬ ��
���仰˵��nums[i] != nums[j]��nums[i] != nums[k] �� nums[j] != nums[k] ��
������������������Ԫ�����Ŀ��
*/

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && nums[j] == nums[i]) {
                j++;
            }
            res += i * (j - i) * (n - j);
        }
        return res;
    }
};


