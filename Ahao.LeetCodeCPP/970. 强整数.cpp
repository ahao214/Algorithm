#include<vector>
#include <unordered_set>


using namespace std;

/*
970. ǿ����

������������ x �� y �� bound ������ ֵС�ڻ���� bound ������ ǿ���� ��ɵ��б� ��

���ĳһ�������Ա�ʾΪ xi + yj ���������� i >= 0 �� j >= 0����ô������Ϊ��������һ�� ǿ���� ��

����԰� �κ�˳�� ���ش𰸡�����Ļش��У�ÿ��ֵ ��� ����һ�Ρ�

*/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> cnt;
        int value1 = 1;
        for (int i = 0; i < 21; i++) {
            int value2 = 1;
            for (int j = 0; j < 21; j++) {
                int value = value1 + value2;
                if (value <= bound) {
                    cnt.emplace(value);
                }
                else {
                    break;
                }
                value2 *= y;
            }
            if (value1 > bound) {
                break;
            }
            value1 *= x;
        }
        return vector<int>(cnt.begin(), cnt.end());
    }
};
