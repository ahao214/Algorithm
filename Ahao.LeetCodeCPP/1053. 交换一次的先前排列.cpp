#include<vector>

using namespace std;

/*
1053. ����һ�ε���ǰ����

����һ������������ arr�����ܴ����ظ���Ԫ�أ������㷵�ؿ��� һ�ν��������������� arr[i] �� arr[j] ��λ�ã���õ��ġ����ֵ�������С�� arr ��������С�

����޷���ô���������뷵��ԭ���顣
*/


class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                int j = n - 1;
                while (arr[j] >= arr[i] || arr[j] == arr[j - 1]) {
                    j--;
                }
                swap(arr[i], arr[j]);
                break;
            }
        }
        return arr;
    }
};
