#include<vector>
#include <numeric>
#include <algorithm>

using namespace std;


/*
1262. �ɱ�������������

����һ���������� nums�������ҳ��������ܱ���������Ԫ�����͡�
*/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // ʹ�� v[0], v[1], v[2] �ֱ��ʾ a, b, c
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
