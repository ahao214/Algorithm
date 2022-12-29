using namespace std;
#include<vector>

/*
2028. �ҳ�ȱʧ�Ĺ۲�����

����һ�� n + m ��Ͷ������ ���� ���ӵĹ۲����ݣ����ӵ�ÿ����� 1 �� 6 ��š��۲�������ȱʧ�� n �ݣ�������ֻ�õ�ʣ�� m ��Ͷ�������ݡ��Һ�����֮ǰ��������� n + m ��Ͷ�����ݵ� ƽ��ֵ ��

����һ������Ϊ m ���������� rolls ������ rolls[i] �ǵ� i �ι۲��ֵ��ͬʱ������������ mean �� n ��

����һ������Ϊ n �����飬��������ȱʧ�Ĺ۲����ݣ��������� n + m ��Ͷ���� ƽ��ֵ �� mean ��������ڶ������Ҫ��Ĵ𰸣�ֻ��Ҫ������������һ�鼴�ɡ���������ڴ𰸣�����һ�������顣

k �����ֵ� ƽ��ֵ Ϊ��Щ������ͺ��ٳ��� k ��

ע�� mean ��һ������������ n + m ��Ͷ�����ܺ���Ҫ�� n + m ������
*/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (n + m);
        int missingSum = sum;
        for (int& roll : rolls) {
            missingSum -= roll;
        }
        if (missingSum < n || missingSum > 6 * n) {
            return {};
        }
        int quotient = missingSum / n, remainder = missingSum % n;
        vector<int> missing(n);
        for (int i = 0; i < n; i++) {
            missing[i] = quotient + (i < remainder ? 1 : 0);
        }
        return missing;
    }
};
