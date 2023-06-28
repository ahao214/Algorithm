#include<vector>

using namespace std;


/*
1253. �ع� 2 �ж����ƾ���

����һ�� 2 �� n �еĶ��������飺

������һ�������ƾ�������ζ�ž����е�ÿ��Ԫ�ز��� 0 ���� 1��
�� 0 �е�Ԫ��֮��Ϊ upper��
�� 1 �е�Ԫ��֮��Ϊ lower��
�� i �У��� 0 ��ʼ��ţ���Ԫ��֮��Ϊ colsum[i]��colsum ��һ������Ϊ n ���������顣
����Ҫ���� upper��lower �� colsum ���ع�������󣬲��Զ�ά�����������ʽ��������

����ж����ͬ�Ĵ𰸣���ô����һ��������ͨ�����⡣

��������ڷ���Ҫ��Ĵ𰸣����뷵��һ���յĶ�ά���顣
*/

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        int sum = 0, two = 0;
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                ++two;
            }
            sum += colsum[i];
        }
        if (sum != upper + lower || min(upper, lower) < two) {
            return {};
        }
        upper -= two;
        lower -= two;
        vector<vector<int>> res(2, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                res[0][i] = res[1][i] = 1;
            }
            else if (colsum[i] == 1) {
                if (upper > 0) {
                    res[0][i] = 1;
                    --upper;
                }
                else {
                    res[1][i] = 1;
                }
            }
        }
        return res;
    }
};
