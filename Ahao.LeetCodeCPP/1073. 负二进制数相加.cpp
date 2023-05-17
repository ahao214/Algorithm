#include<vector>

using namespace std;


/*
1073. �������������

��������Ϊ -2 �������� arr1 �� arr2������������ӵĽ����

������ ������ʽ ���������������� 0 �� 1 ��ɣ��������Чλ�������Чλ��˳�����С����磬arr = [1,1,0,1] ��ʾ���� (-2)^3 + (-2)^2 + (-2)^0 = -3��������ʽ �е����� arr Ҳͬ������ǰ���㣺�� arr == [0] �� arr[0] == 1��

������ͬ��ʾ��ʽ�� arr1 �� arr2 ��ӵĽ���������ı�ʾ��ʽΪ������ǰ���㡢������ 0 �� 1 ��ɵ����顣
*/

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1, j = arr2.size() - 1;
        int carry = 0;
        vector<int> ans;
        while (i >= 0 || j >= 0 || carry) {
            int x = carry;
            if (i >= 0) {
                x += arr1[i];
            }
            if (j >= 0) {
                x += arr2[j];
            }

            if (x >= 2) {
                ans.push_back(x - 2);
                carry = -1;
            }
            else if (x >= 0) {
                ans.push_back(x);
                carry = 0;
            }
            else {
                ans.push_back(1);
                carry = 1;
            }
            --i;
            --j;
        }
        while (ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
