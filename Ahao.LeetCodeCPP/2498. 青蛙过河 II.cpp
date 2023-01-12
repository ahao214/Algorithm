#include<vector>

using namespace std;



/*
2498. ���ܹ��� II
����һ���±�� 0 ��ʼ���������� stones �������е�Ԫ�� �ϸ���� ����ʾһ������ʯͷ��λ�á�

һֻ����һ��ʼ�ڵ�һ��ʯͷ�ϣ����뵽�����һ��ʯͷ��Ȼ��ص���һ��ʯͷ��ͬʱÿ��ʯͷ ���� ���� һ�Ρ�

һ����Ծ�� ���� ��������Ծǰ����Ծ����������ʯͷ֮��ľ��롣

����ʽ�ģ�������ܴ� stones[i] ���� stones[j] ����Ծ�ĳ���Ϊ |stones[i] - stones[j]| ��
һ��·���� ���� ������·����� �����Ծ���� ��

���㷵����ֻ���ܵ� ��С���� ��
*/
class Solution {
public:
	int maxJump(vector<int>& stones) {
		int n = stones.size();
		int res = stones[1] - stones[0];
		for (int i = 2; i < n; i++) {
			res = max(res, stones[i] - stones[i - 2]);
		}
		return res;
	}
};
