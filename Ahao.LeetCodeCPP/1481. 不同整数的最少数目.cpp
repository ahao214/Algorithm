#include<vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/*
1481. ��ͬ������������Ŀ
����һ���������� arr ��һ������ k ������Ҫ��������ǡ���Ƴ� k ��Ԫ�أ����ҳ��Ƴ��������в�ͬ������������Ŀ��
*/
class Solution {
public:
	//ͳ��ÿ�������ֵĴ���,���Ƴ����ִ������ٵ�����
	//����+̰��
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
		//��ϣ��
		unordered_map<int, int> hash;
		for (auto x : arr) hash[x]++;

		vector<int> cnt;
		for (auto x : hash) cnt.push_back(x.second);
		sort(cnt.begin(), cnt.end());

		int res = cnt.size();
		for (auto c : cnt)
		{
			if (k >= c)
			{
				k -= c;
				res--;
			}
			else {
				break;
			}
		}
		return res;
	}
};