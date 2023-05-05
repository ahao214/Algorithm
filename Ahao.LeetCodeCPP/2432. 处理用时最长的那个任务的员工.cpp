#include<vector>

using namespace std;

/*
2432. ������ʱ����Ǹ������Ա��

���� n λԱ����ÿλԱ������һ���� 0 �� n - 1 ��Ψһ id ��

����һ����ά�������� logs ������ logs[i] = [idi, leaveTimei] ��

idi �Ǵ���� i �������Ա���� id ����
leaveTimei ��Ա����ɵ� i �������ʱ�̡����� leaveTimei ��ֵ���� Ψһ �ġ�
ע�⣬�� i �������ڵ� (i - 1) �����������������ʼ���ҵ� 0 �������ʱ�� 0 ��ʼ��

���ش�����ʱ����Ǹ������Ա���� id �����������������Ա��ͬʱ���㣬�򷵻ؼ����� ��С �� id ��
*/



class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = logs[0][0], maxcost = logs[0][1];
        for (int i = 1; i < logs.size(); ++i) {
            int idx = logs[i][0];
            int cost = logs[i][1] - logs[i - 1][1];
            if (cost > maxcost || (cost == maxcost && idx < ans)) {
                ans = idx;
                maxcost = cost;
            }
        }
        return ans;
    }
};
