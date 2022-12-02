using namespace std;

#include<vector>

/*
66. ��һ
����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��
*/
class Solution {
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; i--) {
			if (digits[i] < 9) {
				digits[i]++;
				break;
			}
			else {
				//����9
				digits[i] = 0;
				if (i == 0) {
					digits.insert(digits.begin(), 1);
				}
			}
		}
		return digits;
	}
};
