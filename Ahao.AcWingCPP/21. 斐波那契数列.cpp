using namespace std;

#pragma region 21. 쳲���������

/*
����һ������ n ����쳲��������еĵ� n �

�ٶ��� 0 ��ʼ���� 0 ��Ϊ 0��
*/

#pragma endregion

class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        int one = 0, two = 1, res = 0;
        for (int i = 2; i <= n; i++)
        {
            res = one + two;
            one = two;
            two = res;
        }
        return res;
    }
};