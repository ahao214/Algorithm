#include<vector>
#include <string>

using namespace std;


/// <summary>
/// ��һ������
/// </summary>
class Solution {
public:
    int nextGreaterElement(int n) {
        auto nums = to_string(n);
        int i = (int)nums.length() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i < 0) {
            return -1;
        }

        int j = nums.size() - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            j--;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        long ans = stol(nums);
        return ans > INT_MAX ? -1 : ans;
    }
};


/// <summary>
/// ��ѧ
/// </summary>
class Solution {
public:
    int nextGreaterElement(int n) {
        int x = n, cnt = 1;
        for (; x >= 10 && x / 10 % 10 >= x % 10; x /= 10) {
            ++cnt;
        }
        x /= 10;
        if (x == 0) {
            return -1;
        }

        int targetDigit = x % 10;
        int x2 = n, cnt2 = 0;
        for (; x2 % 10 <= targetDigit; x2 /= 10) {
            ++cnt2;
        }
        x += x2 % 10 - targetDigit; // �� x2 % 10 ���� targetDigit ��

        for (int i = 0; i < cnt; ++i, n /= 10) { // ��ת n ĩβ�� cnt ������ƴ�� x ��
            int d = i != cnt2 ? n % 10 : targetDigit;
            if (x > INT_MAX / 10 || x == INT_MAX / 10 && d > 7) {
                return -1;
            }
            x = x * 10 + d;
        }
        return x;
    }
};
