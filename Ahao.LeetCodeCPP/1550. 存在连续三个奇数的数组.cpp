#include<vector>

using namespace std;


/*
1550. ����������������������
����һ���������� arr�������ж��������Ƿ������������Ԫ�ض��������������������ڣ��뷵�� true �����򣬷��� false ��
*/
class Solution {
public:
	bool threeConsecutiveOdds(vector<int>& arr) {
		for (int i = 0; i + 2 < arr.size(); i++)
			if (arr[i] % 2 && arr[i + 1] % 2 && arr[i + 2] % 2)
				return true;
		return false;
	}
};
