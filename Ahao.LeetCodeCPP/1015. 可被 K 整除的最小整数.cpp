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



class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // �� k �ܱ� 2 �� 5 ���������޽⣬���� -1
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        // ��ʼ������Ϊ 1����ʾһ���������λ�� 1
        int resid = 1 % k, len = 1;
        // ��������Ϊ 0����������
        while (resid != 0) {
            // ������һ��������������һ�����ڵ�ǰ�������һ�� 1
            resid = (resid * 10 + 1) % k;
            len++;
        }
        // �������� 1 ����С�ظ�����
        return len;
    }
};
