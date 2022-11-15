#include<vector>
#include <algorithm>


using namespace std;


/*
2160. �����λ����λ���ֵ���С��
����һ����λ �� ���� num ������ʹ�� num �е� ��λ ���� num ��������µ����� new1 �� new2 ��new1 �� new2 �п����� ǰ�� 0 ���� num �� ���� ��λ������ʹ�á�

�ȷ�˵������ num = 2932 ����ӵ�е���λ���������� 2 ��һ�� 9 ��һ�� 3 ��һЩ���ܵ� [new1, new2] ����Ϊ [22, 93]��[23, 92]��[223, 9] �� [2, 329] ��
���㷵�ؿ��Եõ��� new1 �� new2 �� ��С �͡�
*/
class Solution {
public:
	int minimumSum(int num) {
		vector<int> vNum;
		for (int i = 0; i < 4; i++) {
			vNum.push_back(num % 10);
			num /= 10;
		}
		sort(vNum.begin(), vNum.end());
		int n1 = vNum[0] * 10 + vNum[2];
		int n2 = vNum[1] * 10 + vNum[3];
		return n1 + n2;
	}
};
