#include<vector>
#include <algorithm>

using namespace std;


/*
1561. ����Ի�õ����Ӳ����Ŀ
�� 3n ����Ŀ��һ��Ӳ�ң������������Ǵ��㰴���·�ʽ��Ӳ�ң�

ÿһ���У��㽫��ѡ�� ���� 3 ��Ӳ�ң���һ����������
Alice ����ȡ��Ӳ������������һ�ѡ�
�㽫��ȡ��Ӳ�������ڶ������һ�ѡ�
Bob ����ȡ�����һ�ѡ�
�ظ�������̣�ֱ��û�и���Ӳ�ҡ�
����һ���������� piles ������ piles[i] �ǵ� i ����Ӳ�ҵ���Ŀ��

��������Ի�õ����Ӳ����Ŀ��
*/
class Solution {
public:
	int maxCoins(vector<int>& piles) {
		int res = 0;
		sort(piles.begin(), piles.end());
		for (int i = 0, j = piles.size() - 1; i < j; i++, j -= 2)
			res += piles[j - 1];
		return res;
	}
};

