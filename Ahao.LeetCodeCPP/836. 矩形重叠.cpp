#include<vector>

using namespace std;


/*
836. �����ص�

�������б� [x1, y1, x2, y2] ����ʽ��ʾ������ (x1, y1) Ϊ���½ǵ����꣬(x2, y2) �����Ͻǵ����ꡣ���ε����±�ƽ���� x �ᣬ���ұ�ƽ���� y �ᡣ

����ཻ�����Ϊ �� ������������ص�����Ҫ��ȷ���ǣ�ֻ�ڽǻ�߽Ӵ����������β������ص���

������������ rec1 �� rec2 ����������ص������� true�����򣬷��� false ��



ʾ�� 1��

���룺rec1 = [0,0,2,2], rec2 = [1,1,3,3]
�����true
ʾ�� 2��

���룺rec1 = [0,0,1,1], rec2 = [1,0,2,1]
�����false
ʾ�� 3��

���룺rec1 = [0,0,1,1], rec2 = [2,2,3,3]
�����false


��ʾ��

rect1.length == 4
rect2.length == 4
-109 <= rec1[i], rec2[i] <= 109
rec1 �� rec2 ��ʾһ�������Ϊ�����Ч����
*/
class Solution {
public:
	bool check(int a, int b, int c, int d)
	{
		return a < b&& c < d&& b > c&& d > a;
	}

	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		return check(rec1[0], rec1[2], rec2[0], rec2[2])
			&& check(rec1[1], rec1[3], rec2[1], rec2[3]);
	}
};
