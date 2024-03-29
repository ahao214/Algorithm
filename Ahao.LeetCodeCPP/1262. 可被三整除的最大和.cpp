#include<vector>
#include <numeric>
#include <algorithm>

using namespace std;


/*
1262. 可被三整除的最大和

给你一个整数数组 nums，请你找出并返回能被三整除的元素最大和。
*/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // 使用 v[0], v[1], v[2] 分别表示 a, b, c
        vector<int> v[3];
        for (int num : nums) {
            v[num % 3].push_back(num);
        }
        sort(v[1].begin(), v[1].end(), greater<int>());
        sort(v[2].begin(), v[2].end(), greater<int>());

        int ans = 0;
        int lb = v[1].size(), lc = v[2].size();
        for (int cntb = lb - 2; cntb <= lb; ++cntb) {
            if (cntb >= 0) {
                for (int cntc = lc - 2; cntc <= lc; ++cntc) {
                    if (cntc >= 0 && (cntb - cntc) % 3 == 0) {
                        ans = max(ans, accumulate(v[1].begin(), v[1].begin() + cntb, 0) + accumulate(v[2].begin(), v[2].begin() + cntc, 0));
                    }
                }
            }
        }
        return ans + accumulate(v[0].begin(), v[0].end(), 0);
    }
};


class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // 使用 v[0], v[1], v[2] 分别表示 a, b, c
        vector<int> v[3];
        for (int num : nums) {
            v[num % 3].push_back(num);
        }
        sort(v[1].begin(), v[1].end(), greater<int>());
        sort(v[2].begin(), v[2].end(), greater<int>());
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int remove = INT_MAX;

        if (tot % 3 == 0) {
            remove = 0;
        }
        else if (tot % 3 == 1) {
            if (v[1].size() >= 1) {
                remove = min(remove, v[1].end()[-1]);
            }
            if (v[2].size() >= 2) {
                remove = min(remove, v[2].end()[-2] + v[2].end()[-1]);
            }
        }
        else {
            if (v[1].size() >= 2) {
                remove = min(remove, v[1].end()[-2] + v[1].end()[-1]);
            }
            if (v[2].size() >= 1) {
                remove = min(remove, v[2].end()[-1]);
            }
        }

        return tot - remove;
    }
};


class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> f = { 0, INT_MIN, INT_MIN };
        for (int num : nums) {
            vector<int> g = f;
            for (int i = 0; i < 3; ++i) {
                g[(i + num % 3) % 3] = max(g[(i + num % 3) % 3], f[i] + num);
            }
            f = move(g);
        }
        return f[0];
    }
};
