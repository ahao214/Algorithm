#include<vector>
#include<algorithm>

using namespace std;




/*
1798. ���ܹ��������ֵ�������Ŀ

����һ������Ϊ n ���������� coins ����������ӵ�е� n ��Ӳ�ҡ��� i ��Ӳ�ҵ�ֵΪ coins[i] ����������ЩӲ����ѡ��һ����Ӳ�ң����ǵĺ�Ϊ x ����ô�ƣ������ ���� �� x ��

�뷵�ش� 0 ��ʼ������ 0 ����������� ���� �����ٸ�����������

������ж����ֵͬ��Ӳ�ҡ�
*/
class Solution {
public:
	int getMaximumConsecutive(vector<int>& coins) {
		sort(coins.begin(), coins.end());
		int sum = 0;
		for (auto x : coins)
		{
			if (x > sum + 1)
				return sum + 1;
			sum += x;
		}
		return sum + 1;
	}
};



//̰��
class Solution {
public:
	int getMaximumConsecutive(vector<int>& coins) {
		int res = 1;
		sort(coins.begin(), coins.end());
		for (auto& i : coins) {
			if (i > res) {
				break;
			}
			res += i;
		}
		return res;
	}
};
