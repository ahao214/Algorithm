#include<vector>

using namespace std;


/*
2591. ��Ǯ�ָ����Ķ�ͯ

����һ������ money ����ʾ���ܹ��е�Ǯ������λΪ��Ԫ������һ������ children ����ʾ��Ҫ��Ǯ��������ٸ���ͯ��

����Ҫ�������¹�����䣺

���е�Ǯ�����뱻���䡣
ÿ����ͯ���ٻ�� 1 ��Ԫ��
û���˻�� 4 ��Ԫ��
���㰴��������������Ǯ�������� ��� �ж��ٸ���ͯ��� ǡ�� 8 ��Ԫ�����û���κη��䷽�������� -1 ��
*/

class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        money -= children;
        int cnt = min(money / 7, children);
        money -= cnt * 7;
        children -= cnt;
        if ((children == 0 && money > 0) || (children == 1 && money == 3)) {
            cnt--;
        }
        return cnt;
    }
};
