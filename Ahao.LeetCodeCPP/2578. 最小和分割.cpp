#include<vector>
#include <string>
#include<algorithm>


using namespace std;

/*
2578. ��С�ͷָ�

����һ�������� num �����㽫���ָ�������Ǹ����� num1 �� num2 �����㣺

num1 �� num2 ֱ�����������õ� num ����λ��һ�����С�
���仰˵��num1 �� num2 ���������ֳ��ֵĴ���֮�͵��� num ���������ֳ��ֵĴ�����
num1 �� num2 ���԰���ǰ�� 0 ��
���㷵�� num1 �� num2 ���Եõ��ĺ͵� ��С ֵ��
*/


class Solution {
public:
	int splitNum(int num) {
		string stnum = to_string(num);
		sort(stnum.begin(), stnum.end());
		int num1 = 0, num2 = 0;
		for (int i = 0; i < stnum.size(); ++i) {
			if (i % 2 == 0) {
				num1 = num1 * 10 + (stnum[i] - '0');
			}
			else {
				num2 = num2 * 10 + (stnum[i] - '0');
			}
		}
		return num1 + num2;
	}
};
