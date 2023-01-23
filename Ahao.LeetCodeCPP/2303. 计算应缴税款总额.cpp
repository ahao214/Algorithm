#include<vector>

using namespace std;

/*
2303. ����Ӧ��˰���ܶ�

����һ���±�� 0 ��ʼ�Ķ�ά�������� brackets ������ brackets[i] = [upperi, percenti] ����ʾ�� i ��˰���������� upperi �����յ�˰��Ϊ percenti ��˰�������� �ӵ͵������������� 0 < i < brackets.length ��ǰ���£�upperi-1 < upperi����

˰����㷽ʽ���£�

������ upper0 �����밴˰�� percent0 ����
���� upper1 - upper0 �Ĳ��ְ�˰�� percent1 ����
Ȼ�� upper2 - upper1 �Ĳ��ְ�˰�� percent2 ����
�Դ�����
����һ������ income ��ʾ��������롣��������Ҫ���ɵ�˰���ܶ���׼������ 10-5 �Ľ������������ȷ�𰸡�
*/

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double totalTax = 0;
        int lower = 0;
        for (auto& bracket : brackets) {
            int upper = bracket[0], percent = bracket[1];
            int tax = (min(income, upper) - lower) * percent;
            totalTax += tax;
            if (income <= upper) {
                break;
            }
            lower = upper;
        }
        return (double)totalTax / 100.0;
    }
};
