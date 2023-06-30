#include<vector>
#include<algorithm>

using namespace std;


/*
470. �� Rand7() ʵ�� Rand10()

�������� rand7 ������ [1,7] ��Χ�ڵľ��������������дһ������ rand10 ���� [1,10] ��Χ�ڵľ������������

��ֻ�ܵ��� rand7() �Ҳ��ܵ��������������벻Ҫʹ��ϵͳ�� Math.random() ������

ÿ��������������һ���ڲ����� n������ʵ�ֵĺ��� rand10() �ڲ���ʱ�������õĴ�������ע�⣬�ⲻ�Ǵ��ݸ� rand10() �Ĳ�����
*/
class Solution {
public:
	int rand10() {
		int t = (rand7() - 1) * 7 + rand7();	//1~49

		if (t > 40) return rand10();
		return (t - 1) % 10 + 1;
	}
};
