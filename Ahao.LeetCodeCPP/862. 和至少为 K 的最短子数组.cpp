#include<vector>
#include <deque>

using namespace std;

/*
862. ������Ϊ K �����������

����һ���������� nums ��һ������ k ���ҳ� nums �к�����Ϊ k �� ��̷ǿ������� �������ظ�������ĳ��ȡ���������������� ������ ������ -1 ��

������ �������� ���� ��һ���֡�
*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> preSumArr(n + 1);
        for (int i = 0; i < n; i++) {
            preSumArr[i + 1] = preSumArr[i] + nums[i];
        }
        int res = n + 1;
        deque<int> qu;
        for (int i = 0; i <= n; i++) {
            long curSum = preSumArr[i];
            while (!qu.empty() && curSum - preSumArr[qu.front()] >= k) {
                res = min(res, i - qu.front());
                qu.pop_front();
            }
            while (!qu.empty() && preSumArr[qu.back()] >= curSum) {
                qu.pop_back();
            }
            qu.push_back(i);
        }
        return res < n + 1 ? res : -1;
    }
};
