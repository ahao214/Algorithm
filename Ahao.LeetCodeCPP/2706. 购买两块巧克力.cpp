#include<vector>

using namespace std;

/*
2706. ���������ɿ���

����һ���������� prices ������ʾһ���̵��������ɿ����ļ۸�ͬʱ����һ������ money ����ʾ��һ��ʼӵ�е�Ǯ����

����빺�� ǡ�� �����ɿ���������ʣ���Ǯ�������� �Ǹ��� ��ͬʱ������С�����������ɿ������ܻ��ѡ�

���㷵���ڹ��������ɿ����������ʣ�¶���Ǯ������������������ɿ�������������ӵ�е�Ǯ�����㷵�� money ��ע��ʣ��Ǯ�������ǷǸ�����
*/


class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int fi = INT_MAX, se = INT_MAX;
        for (auto p : prices) {
            if (p < fi) {
                se = fi;
                fi = p;
            }
            else if (p < se) {
                se = p;
            }
        }
        return money < fi + se ? money : money - fi - se;
    }
};
