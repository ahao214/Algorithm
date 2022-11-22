#include<vector>
#include <algorithm>

using namespace std;


/*
1502. �ж��ܷ��γɵȲ�����
����һ���������� arr ��

���һ�������У�������������Ĳ��ܵ���ͬһ����������ô������оͳ�Ϊ �Ȳ����� ��

��������������������γɵȲ����У��뷵�� true �����򣬷��� false ��
*/
class Solution {
public:
	bool canMakeArithmeticProgression(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		for (int i = 2; i < arr.size(); i++)
			if (arr[i] - arr[i - 1] != arr[1] - arr[0])
				return false;
		return true;
	}
};
