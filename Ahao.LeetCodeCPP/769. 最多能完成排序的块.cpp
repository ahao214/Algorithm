#include<vector>

using namespace std;

/*
769. ������������Ŀ�
����һ������Ϊ n ���������� arr ������ʾ�� [0, n - 1] ��Χ�ڵ����������С�

���ǽ� arr �ָ������ �� (������)������ÿ���鵥�����򡣽���������������ʹ�����ӵĽ���Ͱ�����������ԭ������ͬ��

���������ֳܷɵ�����������
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int m = 0, res = 0;
        for (int i = 0; i < arr.size(); i++) {
            m = max(m, arr[i]);
            if (m == i) {
                res++;
            }
        }
        return res;
    }
};
