#include<vector>
#include<string>

using namespace std;


/*
2678. ���˵���Ŀ

����һ���±�� 0 ��ʼ���ַ��� details ��details ��ÿ��Ԫ�ض���һλ�˿͵���Ϣ����Ϣ�ó���Ϊ 15 ���ַ�����ʾ����ʾ��ʽ���£�

ǰʮ���ַ��ǳ˿͵��ֻ����롣
��������һ���ַ��ǳ˿͵��Ա�
�����������ַ��ǳ˿͵����䡣
��������ַ��ǳ˿͵���λ�š�
���㷵�س˿������� �ϸ���� 60 �� ��������
*/


class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (string& info : details) {
            if (stoi(info.substr(11, 2)) > 60) {
                count++;
            }
        }
        return count;
    }
};
