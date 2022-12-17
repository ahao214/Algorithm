#include<vector>

using namespace std;



/*
1764. ͨ��������һ�������������õ�һ������
����һ������Ϊ n �Ķ�ά�������� groups ��ͬʱ����һ���������� nums ��

���Ƿ���Դ� nums ��ѡ�� n �� ���ཻ �������飬ʹ�õ� i ���������� groups[i] ���±�� 0 ��ʼ����ȫ��ͬ������� i > 0 ����ô�� (i-1) ���������� nums �г��ֵ�λ���ڵ� i ��������ǰ�档��Ҳ����˵����Щ�������� nums �г��ֵ�˳����Ҫ�� groups ˳����ͬ��

���������ҳ������� n �������飬���㷵�� true �����򷵻� false ��

����������±�Ϊ k ��Ԫ�� nums[k] ���ڲ�ֹһ�������飬�ͳ���Щ�������� ���ཻ �ġ�������ָ����ԭ����������Ԫ����ɵ�һ�����С�
*/
class Solution {
public:
	bool check(vector<int>& gs, vector<int>& nums, int i)
	{
		int k = 0;
		for (int j = i; k < gs.size() && j < nums.size(); k++, j++)
		{
			if (gs[k] != nums[j])
				return false;
		}
		if (k != gs.size()) return false;
		return true;
	}

	bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
		for (int i = 0, k = 0; i < nums.size(); i++)
		{
			if (check(groups[k], nums, i))
			{
				i += groups[k].size() - 1;
				k++;
				if (k == groups.size()) return true;
			}
		}
		return false;
	}
};


//KMP ƥ���㷨
class Solution {
public:
    int find(vector<int>& nums, int k, vector<int>& g) {
        int m = g.size(), n = nums.size();
        if (k + g.size() > nums.size()) {
            return -1;
        }
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && g[i] != g[j]) {
                j = pi[j - 1];
            }
            if (g[i] == g[j]) {
                j++;
            }
            pi[i] = j;
        }
        for (int i = k, j = 0; i < n; i++) {
            while (j > 0 && nums[i] != g[j]) {
                j = pi[j - 1];
            }
            if (nums[i] == g[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < groups.size(); i++) {
            k = find(nums, k, groups[i]);
            if (k == -1) {
                return false;
            }
            k += groups[i].size();
        }
        return true;
    }
};
