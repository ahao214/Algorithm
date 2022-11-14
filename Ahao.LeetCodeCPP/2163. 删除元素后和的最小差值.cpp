#include<vector>
#include <queue>

using namespace std;


/*
2163. ɾ��Ԫ�غ�͵���С��ֵ
����һ���±�� 0 ��ʼ���������� nums �������� 3 * n ��Ԫ�ء�

����Դ� nums ��ɾ�� ǡ�� n ��Ԫ�أ�ʣ�µ� 2 * n ��Ԫ�ؽ��ᱻ�ֳ����� ��ͬ��С �Ĳ��֡�

ǰ�� n ��Ԫ�����ڵ�һ���֣����ǵĺͼ�Ϊ sumfirst ��
���� n ��Ԫ�����ڵڶ����֣����ǵĺͼ�Ϊ sumsecond ��
�����ֺ͵� ��ֵ ��Ϊ sumfirst - sumsecond ��

�ȷ�˵��sumfirst = 3 �� sumsecond = 2 �����ǵĲ�ֵΪ 1 ��
�ٱȷ���sumfirst = 2 �� sumsecond = 3 �����ǵĲ�ֵΪ -1 ��
���㷵��ɾ�� n ��Ԫ��֮��ʣ�������ֺ͵� ��ֵ����Сֵ �Ƕ��١�
*/
using LL = long long;
class Solution {
public:
	long long minimumDifference(vector<int>& nums) {
		LL ans = 0;
		int N = nums.size();
		int n = N / 3;
		vector<LL> vSmallSum(N);
		vector<LL> vBigSum(N);
		LL sum = 0;
		priority_queue<LL> pSmall;
		for (int i = 0; i < N; i++) {
			pSmall.push(nums[i]);
			sum += nums[i];
			if (pSmall.size() > n) {
				sum -= pSmall.top();
				pSmall.pop();
			}
			vSmallSum[i] = sum;
		}
		sum = 0;
		priority_queue<LL, vector<LL>, greater<LL>> pBig;

		for (int i = N - 1; i >= 0; i--) {
			pBig.push(nums[i]);
			sum += nums[i];
			if (pBig.size() > n) {
				sum -= pBig.top();
				pBig.pop();
			}
			vBigSum[i] = sum;
		}
		ans = vSmallSum[n - 1] - vBigSum[n];
		for (int i = n - 1; i < n * 2; i++) {
			ans = min(ans, vSmallSum[i] - vBigSum[i + 1]);
		}
		return ans;
	}
};
