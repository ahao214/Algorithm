#include<vector>

using namespace std;


/*
2760. ���ż������

����һ���±�� 0 ��ʼ���������� nums ��һ������ threshold ��

����� nums �����������ҳ����±� l ��ͷ���±� r ��β (0 <= l <= r < nums.length) ���������������� ������� ��

nums[l] % 2 == 0
���ڷ�Χ [l, r - 1] �ڵ������±� i ��nums[i] % 2 != nums[i + 1] % 2
���ڷ�Χ [l, r] �ڵ������±� i ��nums[i] <= threshold
��������ʽ����������ĿҪ����������ĳ��ȡ�

ע�⣺������ �������е�һ�������ǿ�Ԫ�����С�
*/
class Solution {
public:
    bool isSatisfied(vector<int>& nums, int l, int r, int threshold) {
        if (nums[l] % 2 != 0) {
            return false;
        }
        for (int i = l; i <= r; i++) {
            if (nums[i] > threshold || (i < r && nums[i] % 2 == nums[i + 1] % 2)) {
                return false;
            }
        }
        return true;
    }

    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0, n = nums.size();
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (isSatisfied(nums, l, r, threshold)) {
                    res = max(res, r - l + 1);
                }
            }
        }
        return res;
    }
};



class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0, dp = 0, n = nums.size();
        for (int l = n - 1; l >= 0; l--) {
            if (nums[l] > threshold) {
                dp = 0;
            }
            else if (l == n - 1 || nums[l] % 2 != nums[l + 1] % 2) {
                dp++;
            }
            else {
                dp = 1;
            }
            if (nums[l] % 2 == 0) {
                res = max(res, dp);
            }
        }
        return res;
    }
};

