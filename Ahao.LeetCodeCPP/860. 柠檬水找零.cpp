#include<vector>
#include <map>

using namespace std;


/*
860. ����ˮ����
������ˮ̯�ϣ�ÿһ������ˮ���ۼ�Ϊ 5 ��Ԫ���˿��Ŷӹ�����Ĳ�Ʒ�������˵� bills ֧����˳��һ�ι���һ����

ÿλ�˿�ֻ��һ������ˮ��Ȼ�����㸶 5 ��Ԫ��10 ��Ԫ�� 20 ��Ԫ��������ÿ���˿���ȷ���㣬Ҳ����˵��������ÿλ�˿�����֧�� 5 ��Ԫ��

ע�⣬һ��ʼ����ͷû���κ���Ǯ��

����һ���������� bills ������ bills[i] �ǵ� i λ�˿͸����ˡ�������ܸ�ÿλ�˿���ȷ���㣬���� true �����򷵻� false ��
*/
class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int fives = 0, tens = 0;
		for (auto b : bills) {
			if (b == 5)
			{
				fives++;
			}
			else if (b == 10)
			{
				if (fives) fives--;
				else return false;
				tens++;
			}
			else
			{
				int t = 15;
				if (tens)
				{
					t -= 10;
					tens--;
				}
				while (t && fives)
				{
					t -= 5;
					fives--;
				}
				if (t) return false;
			}
		}
		return true;
	}

	bool lemonadeChange(vector<int>& bills) {
		map<int, int> cash;
		for (auto b : bills)
		{
			if (b == 5)
			{
				cash[b]++;
			}
			else if (b == 10)
			{
				if (cash[5] > 0)
				{
					cash[5]--;
					cash[10]++;
				}
				else
				{
					return false;
				}
			}
			else if (b == 20)
			{
				if (cash[10] > 0 && cash[5] > 0)
				{
					cash[10]--;
					cash[5]--;
				}
				else if (cash[10] == 0 && cash[5] > 2)
				{
					cash[5] -= 3;
				}
				else
				{
					return false;
				}
			}
		}
		return true;
	}
};