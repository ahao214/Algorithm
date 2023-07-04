#include<vector>
#include<algorithm>

using namespace std;

/*
2679. �����еĺ�

����һ���±�� 0 ��ʼ�Ķ�ά�������� nums ��һ��ʼ��ķ���Ϊ 0 ������Ҫִ�����²���ֱ�������Ϊ�գ�

������ÿһ��ѡȡ����һ��������ɾ���������һ�����ж����������ѡ������һ����ɾ����
�ڲ��� 1 ɾ���������������ҵ�����һ�����֣�������ӵ���� ���� �С�
���㷵������ ���� ��
*/



class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int res = 0;
        int m = nums.size();
        int n = nums[0].size();
        for (int i = 0; i < m; i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        for (int j = 0; j < n; j++) {
            int maxVal = 0;
            for (int i = 0; i < m; i++) {
                maxVal = max(maxVal, nums[i][j]);
            }
            res += maxVal;
        }
        return res;
    }
};



class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int res = 0;
        int m = nums.size();
        int n = nums[0].size();
        vector<priority_queue<int>> pq(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq[i].emplace(nums[i][j]);
            }
        }
        for (int j = 0; j < n; j++) {
            int maxVal = 0;
            for (int i = 0; i < m; i++) {
                maxVal = max(maxVal, pq[i].top());
                pq[i].pop();
            }
            res += maxVal;
        }
        return res;
    }
};
