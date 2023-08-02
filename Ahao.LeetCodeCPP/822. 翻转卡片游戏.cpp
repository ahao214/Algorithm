#include<vector>
#include <unordered_set>

using namespace std;


/*
822. ��ת��Ƭ��Ϸ

���������� n �ſ�Ƭ��ÿ�ſ�Ƭ������ͱ��涼д��һ�������������뱳���ϵ����п��ܲ�һ������

���ǿ����ȷ�ת�����ſ�Ƭ��Ȼ��ѡ������һ�ſ�Ƭ��

���ѡ�е����ſ�Ƭ��������� x ������һ�ſ�Ƭ����������ֶ���ͬ����ô���������������Ҫ�����֡�

�ĸ�������Щ��Ҫ����������С�������ҵ���Щ���е���Сֵ���أ����û��һ�����ַ���Ҫ��ģ���� 0 ��

����, fronts[i] �� backs[i] �ֱ����� i �ſ�Ƭ������ͱ�������֡�

�������ͨ����ת��Ƭ�����������뱳���ϵ�������ô��������������ͱ�ɱ����������������ͱ�����������

*/

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int res = 3000, n = fronts.size();
        unordered_set<int> same;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                same.insert(fronts[i]);
            }
        }
        for (int& x : fronts) {
            if (x < res && same.count(x) == 0) {
                res = x;
            }
        }
        for (int& x : backs) {
            if (x < res && same.count(x) == 0) {
                res = x;
            }
        }
        return res % 3000;
    }
};
