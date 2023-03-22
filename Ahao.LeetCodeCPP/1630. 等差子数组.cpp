#include<vector>
#include <algorithm>

using namespace std;

/*
1630. �Ȳ�������

���һ����������������Ԫ����ɣ���ÿ��������Ԫ��֮��Ĳ�ֵ����ͬ����ô������о��� �Ȳ����� ������ʽ�أ����� s �ǵȲ����У�ֻ��Ҫ���㣺����ÿ����Ч�� i �� s[i+1] - s[i] == s[1] - s[0] ��������

���磬������Щ���� �Ȳ����� ��

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
��������� ���ǵȲ����� ��

1, 1, 2, 5, 7
����һ���� n ��������ɵ����� nums���������� m ��������ɵ����� l �� r�������������ʾ m �鷶Χ��ѯ�����е� i ����ѯ��Ӧ��Χ [l[i], r[i]] ������������±궼�� �� 0 ��ʼ �ġ�

���� boolean Ԫ�ع��ɵĴ��б� answer ����������� nums[l[i]], nums[l[i]+1], ... , nums[r[i]] ���� �������� �γ� �Ȳ����� ��answer[i] ��ֵ���� true������answer[i] ��ֵ���� false ��
*/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans;
        for (int i = 0; i < n; ++i) {
            int left = l[i], right = r[i];
            int minv = *min_element(nums.begin() + left, nums.begin() + right + 1);
            int maxv = *max_element(nums.begin() + left, nums.begin() + right + 1);

            if (minv == maxv) {
                ans.push_back(true);
                continue;
            }
            if ((maxv - minv) % (right - left) != 0) {
                ans.push_back(false);
                continue;
            }

            int d = (maxv - minv) / (right - left);
            bool flag = true;
            vector<int> seen(right - left + 1);
            for (int j = left; j <= right; ++j) {
                if ((nums[j] - minv) % d != 0) {
                    flag = false;
                    break;
                }
                int t = (nums[j] - minv) / d;
                if (seen[t]) {
                    flag = false;
                    break;
                }
                seen[t] = true;
            }
            ans.push_back(flag);
        }
        return ans;
    }
};
