#include<vector>
#include <algorithm>

using namespace std;


/*
2560. ��ҽ��� IV

�ؽ���һ�������ķ��ݡ�ÿ�䷿���ڶ�����һ�����ֽ�������һλС͵�ƻ�����Щ��������ȡ�ֽ�

�������ڵķ���װ���໥��ͨ�ķ���ϵͳ������С͵ ������ȡ���ڵķ��� ��

С͵�� ��ȡ���� ����Ϊ������ȡ�������ܴӵ��䷿������ȡ�� ����� ��

����һ���������� nums ��ʾÿ�䷿�ݴ�ŵ��ֽ����ʽ�ϣ�������� i �䷿���з��� nums[i] ��Ԫ��

�����һ������ k ����ʾ����������ȡ�� ���� ��������С͵������ȡ���� k �䷿�ݡ�

����С͵�� ��С ��ȡ������
*/


class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int lower = *min_element(nums.begin(), nums.end());
        int upper = *max_element(nums.begin(), nums.end());
        while (lower <= upper) {
            int middle = (lower + upper) / 2;
            int count = 0;
            bool visited = false;
            for (int x : nums) {
                if (x <= middle && !visited) {
                    count++;
                    visited = true;
                }
                else {
                    visited = false;
                }
            }
            if (count >= k) {
                upper = middle - 1;
            }
            else {
                lower = middle + 1;
            }
        }
        return lower;
    }
};
