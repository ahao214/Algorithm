#include<vector>

using namespace std;



/*
1518. ��������
С�����������ڴ������� numExchange ���վ�ƿ���Զһ�һƿ�¾ơ��㹺���� numBottles ƿ�ơ�

����ȵ��˾�ƿ�еľƣ���ô��ƿ�ͻ��ɿյġ�

������� ��� �ܺȵ�����ƿ�ơ�
*/
class Solution {
public:
	int numWaterBottles(int numBottles, int numExchange) {
		int res = numBottles;
		while (numBottles >= numExchange)
		{
			res += numBottles / numExchange;
			numBottles = numBottles / numExchange + numBottles % numExchange;
		}
		return res;
	}

};