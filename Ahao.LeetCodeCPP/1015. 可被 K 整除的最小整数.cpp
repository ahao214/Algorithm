#include <unordered_set>
#include<vector>

using namespace std;

/*
1015. �ɱ� K ��������С����

���������� k ������Ҫ�ҳ����Ա� k �����ġ����������� 1 ���� С ������ n �ĳ��ȡ�

���� n �ĳ��ȡ���������������� n ���ͷ���-1��

ע�⣺ n ������ 64 λ������������
*/


class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int resid = 1 % k, len = 1; // residΪ������lenΪ���ֳ��ȣ���ʼֵΪ1
        unordered_set<int> st; // ����һ�����򼯺ϣ����ڴ洢����
        st.insert(resid); // ��������1
        while (resid != 0) { // ������Ϊ0ʱ�˳�ѭ��
            resid = (resid * 10 + 1) % k; // ������һ������
            len++; // ���ֳ���+1
            if (st.find(resid) != st.end()) { // ��������ظ����֣����޽�
                return -1;
            }
            st.insert(resid); // ���������뼯��
        }
        return len; // �������ֳ���
    }
};
