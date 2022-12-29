#include<vector>
#include <unordered_map>

using namespace std;

/*
2032. ���������������г��ֵ�ֵ
���������������� nums1��nums2 �� nums3 �����㹹�첢����һ�� Ԫ�ظ�����ͬ�� ���飬���� ���� �� ���� �����г��ֵ�����ֵ��ɡ������е�Ԫ�ؿ��԰� ���� ˳�����С�
*/

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mp;
        for (auto& i : nums1) {
            mp[i] = 1;
        }
        for (auto& i : nums2) {
            mp[i] |= 2;
        }
        for (auto& i : nums3) {
            mp[i] |= 4;
        }
        vector<int> res;
        for (auto& [k, v] : mp) {
            if (v & (v - 1)) {
                res.push_back(k);
            }
        }
        return res;
    }
};
