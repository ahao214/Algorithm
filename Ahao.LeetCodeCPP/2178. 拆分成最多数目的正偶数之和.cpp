#include<vector>


using namespace std;

/*
2178. ��ֳ������Ŀ����ż��֮��

����һ������ finalSum �����㽫����ֳ����ɸ� ������ͬ ����ż��֮�ͣ��Ҳ�ֳ�������ż����Ŀ ��� ��

�ȷ�˵������ finalSum = 12 ����ô��Щ����� ����Ҫ�� �ģ�������ͬ����ż���Һ�Ϊ finalSum����(2 + 10) ��(2 + 4 + 6) �� (4 + 8) �������У�(2 + 4 + 6) ���������Ŀ��������ע�� finalSum ���ܲ�ֳ� (2 + 2 + 4 + 4) ����Ϊ��ֳ������������뻥����ͬ��
���㷵��һ���������飬��ʾ��������ֳ� ��� ��Ŀ����ż�����顣���û�а취�� finalSum ���в�֣����㷵��һ�� �� ���顣����԰� ���� ˳�򷵻���Щ������
*/

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if (finalSum % 2 > 0) {
            return res;
        }
        for (int i = 2; i <= finalSum; i += 2) {
            res.push_back(i);
            finalSum -= i;
        }
        res.back() += finalSum;
        return res;
    }
};
