#include<vector>
#include <unordered_map>

using namespace std;


/*
1742. ������С����������
����һ������С�����߳��������� n ��С�򣬱�Ŵ� lowLimit ��ʼ���� highLimit ���������� lowLimit �� highLimit ���� n == highLimit - lowLimit + 1�����������������ĺ��ӣ���Ŵ� 1 �� infinity ��

��Ĺ����ǽ�ÿ��С���������У����к��ӵı��Ӧ������С������ÿλ���ֵĺ͡����磬��� 321 ��С��Ӧ�������� 3 + 2 + 1 = 6 �ĺ��ӣ������ 10 ��С��Ӧ�������� 1 + 0 = 1 �ĺ��ӡ�

������������ lowLimit �� highLimit �����ط������С��ĺ����е�С������������ж�����Ӷ�����������С��ֻ�践��������һ���ӵ�С��������
*/
class Solution {
public:
	//��ÿ�����ֵĸ���λ����֮��
	int countBalls(int lowLimit, int highLimit) {
		vector<int> sum(50);
		int res = 0;
		for (int i = lowLimit; i <= highLimit; i++)
		{
			int x = i, s = 0;
			while (x) s += x % 10, x /= 10;
			sum[s]++;
			res = max(res, sum[s]);
		}
		return res;
	}
};

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> count;
        int res = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int box = 0, x = i;
            while (x) {
                box += x % 10;
                x /= 10;
            }
            count[box]++;
            res = max(res, count[box]);
        }
        return res;
    }
};
