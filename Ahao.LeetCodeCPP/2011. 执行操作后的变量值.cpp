#include<vector>
#include <string>

using namespace std;

/*
2011. ִ�в�����ı���ֵ
��
26
�����ҵ
����һ�ֽ�֧�� 4 �ֲ����� 1 ������ X �ı�����ԣ�

++X �� X++ ʹ���� X ��ֵ �� 1
--X �� X-- ʹ���� X ��ֵ �� 1
�����X ��ֵ�� 0

����һ���ַ������� operations �������ɲ�����ɵ�һ���б�����ִ�����в����� X �� ����ֵ ��
*/

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto& op : operations) {
            if (op == "X++" || op == "++X") {
                x++;
            }
            else {
                x--;
            }
        }
        return x;
    }
};
