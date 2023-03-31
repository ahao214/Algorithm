#include<vector>
#include <unordered_set>

using namespace std;

/*
2367. ������Ԫ�����Ŀ

����һ���±�� 0 ��ʼ���ϸ���� ���������� nums ��һ�������� diff �������������ȫ������������Ԫ�� (i, j, k) ����һ�� ������Ԫ�� ��

i < j < k ��
nums[j] - nums[i] == diff ��
nums[k] - nums[j] == diff
���ز�ͬ ������Ԫ�� ����Ŀ��
*/

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> hashSet;
        for (int x : nums) {
            hashSet.emplace(x);
        }
        int ans = 0;
        for (int x : nums) {
            if (hashSet.count(x + diff) && hashSet.count(x + 2 * diff)) {
                ans++;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0, j = 1, k = 2; i < n - 2 && j < n - 1 && k < n; i++) {
            j = max(j, i + 1);
            while (j < n - 1 && nums[j] - nums[i] < diff) {
                j++;
            }
            if (j >= n - 1 || nums[j] - nums[i] > diff) {
                continue;
            }
            k = max(k, j + 1);
            while (k < n && nums[k] - nums[j] < diff) {
                k++;
            }
            if (k < n && nums[k] - nums[j] == diff) {
                ans++;
            }
        }
        return ans;
    }
};
