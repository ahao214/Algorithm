#include<vector>
#include<string>

using namespace std;

/*
2481. �ָ�Բ�������и����

Բ��һ�� ��Ч�и� ���������¶���֮һ��

���и��������˵���Բ�ϵ��߶Σ��Ҹ��߶ξ���Բ�ġ�
���и���һ����Բ����һ����Բ�ϵ��߶Ρ�
һЩ��Ч����Ч���и�����ͼ��ʾ��



����һ������ n �����㷵�ؽ�Բ�и����ȵ� n �ȷֵ� ���� �и������
*/

class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return n / 2;
        }
        return n;
    }
};
