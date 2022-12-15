using namespace std;
#include<vector>


/*
42. ����ˮ
���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ��
���㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
*/
class Solution {
public:
	int trap(vector<int>& height) {
		int l = 0, r = height.size() - 1;
		int lmax = 0, rmax = 0, ans = 0;
		while (l < r) {
			lmax = max(lmax, height[l]);
			rmax = max(rmax, height[r]);
			if (lmax < rmax) {
				ans += lmax - height[l];
				l++;
			}
			else {
				ans += rmax - height[r];
				r--;
			}
		}
		return ans;
	}
};


/*
42. ����ˮ
���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
*/
class Solution {
public:
	int trap(vector<int>& height) {
		int l = 0, r = height.size() - 1;
		int lmax = 0, rmax = 0, ans = 0;
		while (l < r) {
			lmax = max(lmax, height[l]);
			rmax = max(rmax, height[r]);
			if (lmax < rmax) {
				ans += lmax - height[l];
				l++;
			}
			else {
				ans += rmax - height[r];
				r--;
			}
		}
		return ans;
	}
};