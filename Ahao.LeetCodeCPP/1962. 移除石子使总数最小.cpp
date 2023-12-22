#include<vector>
#include<queue>

using namespace std;

/*
1962. �Ƴ�ʯ��ʹ������С

����һ���������� piles ������ �±�� 0 ��ʼ ������ piles[i] ��ʾ�� i ��ʯ���е�ʯ�������������һ������ k ������ִ���������� ǡ�� k �Σ�

ѡ����һʯ�Ӷ� piles[i] �������� �Ƴ� floor(piles[i] / 2) ��ʯ�ӡ�
ע�⣺����Զ� ͬһ�� ʯ�Ӷ��ִ�д˲�����

����ִ�� k �β�����ʣ��ʯ�ӵ� ��С ������

floor(x) Ϊ С�� �� ���� x �� ��� �������������� x ����ȡ������
*/



class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        for (int i = 0; i < k; i++) {
            int pile = pq.top();
            pq.pop();
            pile -= pile / 2;
            pq.push(pile);
        }
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
