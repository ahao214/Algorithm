#include<vector>

using namespace std;

/*
1276. ���˷�ԭ�ϵĺ�����������

ʥ���Ԥ�ȿ�ʼ�����������Ƴ���ȫ�µĺ����ײ͡�Ϊ�˱����˷�ԭ�ϣ�����������ƶ����ʵ������ƻ���

������������ tomatoSlices �� cheeseSlices���ֱ��ʾ����Ƭ������Ƭ����Ŀ����ͬ������ԭ�ϴ������£�

���ްԺ�����4 Ƭ���Ѻ� 1 Ƭ����
С�ʱ���2 Ƭ���Ѻ� 1 Ƭ����
������ [total_jumbo, total_small]��[���ްԺ���������С�ʱ�����]���ĸ�ʽ����ǡ��������������ʹ��ʣ�µķ���Ƭ tomatoSlices ������Ƭ cheeseSlices ���������� 0��

����޷�ʹʣ�µķ���Ƭ tomatoSlices ������Ƭ cheeseSlices ������Ϊ 0�����뷵�� []��
*/

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices % 2 != 0 || tomatoSlices < cheeseSlices * 2 || cheeseSlices * 4 < tomatoSlices) {
            return {};
        }
        return { tomatoSlices / 2 - cheeseSlices, cheeseSlices * 2 - tomatoSlices / 2 };
    }
};


