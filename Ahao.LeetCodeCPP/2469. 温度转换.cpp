#include<vector>

using namespace std;

/*
2469. �¶�ת��

����һ���������뵽��λС���ķǸ������� celsius ����ʾ�¶ȣ��� ���϶ȣ�Celsius��Ϊ��λ��

����Ҫ�����϶�ת��Ϊ ���϶ȣ�Kelvin���� ���϶ȣ�Fahrenheit������������ ans = [kelvin, fahrenheit] ����ʽ���ؽ����

�������� ans ����ʵ�ʴ������� 10^-5 �Ļ���Ϊ��ȷ�𰸡�

ע�⣺

���϶� = ���϶� + 273.15
���϶� = ���϶� * 1.80 + 32.00
*/

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return { celsius + 273.15, celsius * 1.80 + 32.00 };
    }
};
