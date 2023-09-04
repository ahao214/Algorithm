#include<vector>
#include <string>

using namespace std;



/*
151. ��ת�ַ�����ĵ���

����һ���ַ��� s �������ת�ַ����е����� ���� ��

���� ���ɷǿո��ַ���ɵ��ַ�����s ��ʹ������һ���ո��ַ����е� ���� �ָ�����

���㷵��һ����ת s �е���˳���õ����ո��������ַ�����

˵����

�����ַ��� s ������ǰ�桢������ߵ��ʼ��������Ŀո�
��ת�󵥴ʼ�Ӧ������һ���ո�ָ���
��ת����ַ����в�Ӧ��������Ŀո�
*/
class Solution {
public:
    string reverseWords(string s) {
        // ��ת�����ַ���
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // ��һ���հ��ַ�Ȼ��idx�ƶ�����һ�����ʵĿ�ͷλ��
                if (idx != 0) s[idx++] = ' ';

                // ѭ�����������ʵ�ĩβ
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];

                // ��ת��������
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // ����start��ȥ����һ������
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};



class Solution {
public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')continue;
            int j = i, t = k;
            while (j < s.size() && s[j] != ' ')
                s[t++] = s[j++];
            reverse(s.begin() + k, s.begin() + t);
            s[t++] = ' ';
            k = t, i = j;
        }
        if (k)k--;
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};