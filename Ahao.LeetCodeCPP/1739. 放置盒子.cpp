#include<vector>

using namespace std;


/*
1739. ���ú���
��һ�������巿�䣬�䳤�ȡ���Ⱥ͸߶ȶ����� n ����λ�������ڷ�������� n �����ӣ�ÿ�����Ӷ���һ����λ�߳��������塣���ù������£�

����԰Ѻ��ӷ��ڵذ��ϵ��κεط���
������� x ��Ҫ�����ں��� y �Ķ�������ô���� y ��ֱ���ĸ����涼 ���� ����һ�����ӻ�ǽ���ڡ�
����һ������ n �����ؽӴ�����ĺ��ӵ� ���� ����������
*/
class Solution {
public:
	int minimumBoxes(int n) {
		int sum = 0, k = 1;
		while (sum + k * (k + 1) / 2 <= n)
		{
			sum += k * (k + 1) / 2;
			k++;
		}

		int res = k * (k - 1) / 2;
		k = 1;
		while (sum < n)
		{
			sum += k;
			k++;
			res++;
		}
		return res;
	}
};


class Solution {
public:
	int minimumBoxes(int n) {
		int cur = 1, i = 1, j = 1;
		while (n > cur) {
			n -= cur;
			i++;
			cur += i;
		}
		cur = 1;
		while (n > cur) {
			n -= cur;
			j++;
			cur++;
		}
		return (i - 1) * i / 2 + j;
	}
};


//���ֲ���
class Solution {
public:
	int minimumBoxes(int n) {
		int i = 0, j = 0;
		int low = 1, high = min(n, 100000);
		while (low < high) {
			int mid = (low + high) >> 1;
			long long sum = (long long)mid * (mid + 1) * (mid + 2) / 6;
			if (sum >= n) {
				high = mid;
			}
			else {
				low = mid + 1;
			}
		}
		i = low;
		n -= (long long)(i - 1) * i * (i + 1) / 6;
		low = 1, high = i;
		while (low < high) {
			int mid = (low + high) >> 1;
			long long sum = (long long)mid * (mid + 1) / 2;
			if (sum >= n) {
				high = mid;
			}
			else {
				low = mid + 1;
			}
		}
		j = low;
		return (i - 1) * i / 2 + j;
	}
};
