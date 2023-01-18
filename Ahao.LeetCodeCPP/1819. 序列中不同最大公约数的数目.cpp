#include<vector>
#include <algorithm>

using namespace std;

/*
1819. 序列中不同最大公约数的数目

给你一个由正整数组成的数组 nums 。

数字序列的 最大公约数 定义为序列中所有整数的共有约数中的最大整数。

例如，序列 [4,6,16] 的最大公约数是 2 。
数组的一个 子序列 本质是一个序列，可以通过删除数组中的某些元素（或者不删除）得到。

例如，[2,5,10] 是 [1,2,1,2,4,1,5,10] 的一个子序列。
计算并返回 nums 的所有 非空 子序列中 不同 最大公约数的 数目 。
*/

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> occured(maxVal + 1, false);
        for (int num : nums) {
            occured[num] = true;
        }
        int ans = 0;
        for (int i = 1; i <= maxVal; i++) {
            int subGcd = 0;
            for (int j = i; j <= maxVal; j += i) {
                if (occured[j]) {
                    if (subGcd == 0) {
                        subGcd = j;
                    }
                    else {
                        subGcd = __gcd(subGcd, j);
                    }
                    if (subGcd == i) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};




class Solution {
    int g[200001];
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        for (auto num : nums)
        {
            for (int i = 1; i <= sqrt(num); i++)
            {
                if (num % i == 0)
                {
                    if (g[i] == 0)
                        g[i] = num;
                    else
                        g[i] = gcd(g[i], num);
                    if (num / i != i)
                    {
                        if (g[num / i] == 0)
                            g[num / i] = num;
                        else
                            g[num / i] = gcd(g[num / i], num);
                    }
                }
            }
        }

        int count = 0;
        for (int f = 1; f <= 200000; f++)
            if (f == g[f])
                count++;
        return count;
    }
};