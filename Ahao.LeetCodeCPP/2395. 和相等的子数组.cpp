#include<vector>
#include <unordered_set>

using namespace std;

/*
2395. ����ȵ�������

����һ���±�� 0 ��ʼ���������� nums ���ж��Ƿ���� ���� ����Ϊ 2 �������������ǵ� �� ��ȡ�ע�⣬��������������ʼλ�õ��±���� ����ͬ ��

�����������������ڣ��뷵�� true�����򷵻� false ��

������ ��һ��������һ�������ǿյ�Ԫ����ɵ����С�
*/

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        for (int i = 0; i < n - 1; ++i) {
            int sum = nums[i] + nums[i + 1];
            if (seen.count(sum)) {
                return true;
            }
            seen.insert(sum);
        }
        return false;
    }
};
