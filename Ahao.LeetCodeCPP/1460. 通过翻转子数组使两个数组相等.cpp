#include<vector>
#include <algorithm>

using namespace std;



/*
1460. ͨ����ת������ʹ�����������
��������������ͬ���������� target �� arr ��ÿһ���У������ѡ�� arr ������ �ǿ������� ��������ת�������ִ�д˹�������Ρ�

��������� arr ����� target ��ͬ������ True�����򣬷��� False ��
*/
class Solution {
public:
	//ֻ��Ҫ�ж����������е�ֵ�Ƿ����
	bool canBeEqual(vector<int>& target, vector<int>& arr) {
		sort(target.begin(), target.end());
		sort(arr.begin(), arr.end());
		return target == arr;
	}
};