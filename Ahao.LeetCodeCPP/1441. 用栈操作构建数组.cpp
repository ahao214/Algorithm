#include<vector>
#include<string>

/*
1441. ��ջ������������

����һ������ target ��һ������ n��ÿ�ε�������Ҫ��  list = { 1 , 2 , 3 ..., n } �����ζ�ȡһ�����֡�

��ʹ����������������Ŀ������ target ��

"Push"���� list �ж�ȡһ����Ԫ�أ� ���������������С�
"Pop"��ɾ�������е����һ��Ԫ�ء�
���Ŀ�����鹹����ɣ���ֹͣ��ȡ����Ԫ�ء�
��Ŀ���ݱ�֤Ŀ�������ϸ����������ֻ���� 1 �� n ֮������֡�

�뷵�ع���Ŀ���������õĲ������С�������ڶ�����з�����������һ���ɡ�

*/

using namespace std;

class Solution {
public:
	vector<string> buildArray(vector<int>& target, int n) {
		vector<string> res;
		int prev = 0;
		for (int number : target) {
			for (int i = 0; i < number - prev - 1; i++) {
				res.emplace_back("Push");
				res.emplace_back("Pop");
			}
			res.emplace_back("Push");
			prev = number;
		}
		return res;
	}
};
