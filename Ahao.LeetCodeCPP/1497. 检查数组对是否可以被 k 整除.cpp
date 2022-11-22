#include<vector>
#include <unordered_map>

using namespace std;


/*
1497. ���������Ƿ���Ա� k ����
����һ���������� arr ��һ������ k ���������鳤����ż����ֵΪ n ��

������Ҫ������ǡ�÷ֳ� n / 2 �ԣ���ʹÿ�����ֵĺͶ��ܹ��� k ������

������������ķַ����뷵�� True �����򣬷��� False ��
*/
class Solution {
public:
	/*
	������0 1 2 3 4 5 6...k-3 k-2 k-1
	������������0������ֻ�ܺ�������0���������
	������������1������ֻ�ܺ�������k-1���������
	������������2������ֻ�ܺ�������k-2���������
	������������3������ֻ�ܺ�������k-3���������
	*/
	bool canArrange(vector<int>& arr, int k) {
		unordered_map<int, int> cnt;	//��¼ÿ���������ֵĸ���
		for (auto x : arr)
			cnt[(x % k + k) % k]++;
		if (cnt[0] % 2) return false;
		for (int i = 1; i < k; i++)
		{
			while (cnt[i])
			{
				cnt[i]--;
				if (cnt[k - i] <= 0)
					return false;
				cnt[k - i]--;
			}
		}
		return true;
	}
};
