#include<vector>
#include <string>

using namespace std;

/*
2185. ͳ�ư�������ǰ׺���ַ���
��
24
�����ҵ
����һ���ַ������� words ��һ���ַ��� pref ��

���� words ���� pref ��Ϊ ǰ׺ ���ַ�������Ŀ��

�ַ��� s �� ǰ׺ ����  s ����һǰ�������ַ�����
*/
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (string& word : words) {
            if (word.compare(0, pref.size(), pref) == 0) {
                res++;
            }
        }
        return res;
    }
};
