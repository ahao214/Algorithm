#include<vector>

using namespace std;


/*
1186. ɾ��һ�εõ�����������

����һ���������飬��������ĳ�� �ǿ� �����飨����Ԫ�أ���ִ��һ�ο�ѡ��ɾ�����������ܵõ������Ԫ���ܺ͡����仰˵������Դ�ԭ������ѡ��һ�������飬�����Ծ���Ҫ��Ҫ����ɾ��һ��Ԫ�أ�ֻ��ɾһ��Ŷ������ɾ����������������Ӧ����һ��Ԫ�أ�Ȼ��������飨ʣ�£���Ԫ���ܺ�������������֮�����ġ�

ע�⣬ɾ��һ��Ԫ�غ������� ����Ϊ�ա�
*/


class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int dp0 = arr[0], dp1 = 0, res = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            dp1 = max(dp0, dp1 + arr[i]);
            dp0 = max(dp0, 0) + arr[i];
            res = max(res, max(dp0, dp1));
        }
        return res;
    }
};
