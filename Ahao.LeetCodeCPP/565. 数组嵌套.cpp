#include<vector>

using namespace std;

//����һ��ͼ
class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int ans = 0, n = nums.size();
		vector<int> vis(n);
		for (int i = 0; i < n; ++i) {
			int cnt = 0;
			while (!vis[i]) {
				vis[i] = true;
				i = nums[i];
				++cnt;
			}
			ans = max(ans, cnt);
		}
		return ans;
	}
};


//��������ԭ�ر��
class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int ans = 0, n = nums.size();
		for (int i = 0; i < n; ++i) {
			int cnt = 0;
			while (nums[i] < n) {
				int num = nums[i];
				nums[i] = n;
				i = num;
				++cnt;
			}
			ans = max(ans, cnt);
		}
		return ans;
	}
};
