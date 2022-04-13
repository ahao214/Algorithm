using namespace std;
#include<vector>;

class Solution {
	/*
	11. ʢ���ˮ������
	���� n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ���� (i, ai) ���������ڻ� n ����ֱ�ߣ���ֱ�� i �������˵�ֱ�Ϊ (i, ai) �� (i, 0) ���ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��

	˵�����㲻����б������
	*/
public:
	int maxArea(vector<int>& height) {
		//����ָ��,˭С�ƶ�˭
		int res = 0;
		int l = 0, r = height.size() - 1;
		while (l < r) {
			res = max(res, min(height[l], height[r]) * (r - l));
			if (height[l] < height[r]) {
				l++;
			}
			else {
				r--;
			}
		}
		return res;
	}
};