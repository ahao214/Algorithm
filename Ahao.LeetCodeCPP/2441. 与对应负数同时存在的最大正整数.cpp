#include<vector>
#include <unordered_set>

using namespace std;

/*
2441. ���Ӧ����ͬʱ���ڵ����������

����һ�� ������ �κ������������ nums ���ҳ��������Ӧ�ĸ������������д��ڵ���������� k ��

���������� k ��������������������������� -1 ��
*/


class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int k = -1;
        for (auto x : nums) {
            auto p = find(nums.begin(), nums.end(), -x);
            if (p != nums.end()) {
                k = max(k, x);
            }
        }
        return k;
    }
};



class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int k = -1;
        unordered_set<int> s(nums.begin(), nums.end());
        for (auto x : nums) {
            if (s.count(-x)) {
                k = max(k, x);
            }
        }
        return k;
    }
};


