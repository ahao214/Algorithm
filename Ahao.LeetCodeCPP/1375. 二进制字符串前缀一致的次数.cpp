#include<vector>


using namespace std;

/*
1375. �������ַ���ǰ׺һ�µĴ���

����һ������Ϊ n ���±�� 1 ��ʼ�Ķ������ַ���������λ�ʼ���� 0 �����ǻᰴ����ת�ö������ַ���������λ�������� 0 ��Ϊ 1����

����һ���±�� 1 ��ʼ���������� flips ������ flips[i] ��ʾ��Ӧ�±� i ��λ�����ڵ� i ����ת��

�������ַ��� ǰ׺һ�� �����㣺�ڵ� i ��֮���� �� ���� [1, i] �ڵ�����λ���� 1 ��������λ���� 0 ��

���ض������ַ����ڷ�ת������ ǰ׺һ�� �Ĵ�����
*/

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();
        int ans = 0, right = 0;
        for (int i = 0; i < n; ++i) {
            right = max(right, flips[i]);
            if (right == i + 1) {
                ++ans;
            }
        }
        return ans;
    }
};
