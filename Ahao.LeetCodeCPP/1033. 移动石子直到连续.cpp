#include<vector>

using namespace std;

/*
1033. �ƶ�ʯ��ֱ������

��öʯ�ӷ����������ϣ�λ�÷ֱ�Ϊ a��b��c��

ÿһ�غϣ�����Դ�����֮һ����һöʯ�ӣ�λ��������С�����������������֮�����һ����λ�á���ʽ�ϣ���������öʯ�ӵ�ǰ�ֱ�λ��λ�� x, y, z �� x < y < z����ô�Ϳ��Դ�λ�� x ������λ�� z ����һöʯ�ӣ�������ʯ���ƶ���ĳһ����λ�� k �������� x < k < z �� k != y��

�����޷������κ��ƶ�ʱ��������Щʯ�ӵ�λ������ʱ����Ϸ������

Ҫʹ��Ϸ�����������ִ�е���С������ƶ������ֱ��Ƕ��٣� �Գ���Ϊ 2 ��������ʽ���ش𰸣�answer = [minimum_moves, maximum_moves]
*/

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min({ a, b, c });
        int z = max({ a, b, c });
        int y = a + b + c - x - z;

        vector<int> res(2);
        res[0] = 2;
        if ((z - y) == 1 && (y - x) == 1) {
            res[0] = 0;
        }
        else if ((z - y) <= 2 || (y - x) <= 2) {
            res[0] = 1;
        }
        res[1] = (z - x - 2);
        return res;
    }
};
