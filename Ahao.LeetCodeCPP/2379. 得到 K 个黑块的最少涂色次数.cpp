#include<string>

using namespace std;

/*
2379. �õ� K ���ڿ������Ϳɫ����

����һ������Ϊ n �±�� 0 ��ʼ���ַ��� blocks ��blocks[i] Ҫô�� 'W' Ҫô�� 'B' ����ʾ�� i �����ɫ���ַ� 'W' �� 'B' �ֱ��ʾ��ɫ�ͺ�ɫ��

����һ������ k ����ʾ��Ҫ ���� ��ɫ�����Ŀ��

ÿһ�β����У������ѡ��һ����ɫ�齫�� Ϳ�� ��ɫ�顣

���㷵�����ٳ��� һ�� ���� k ����ɫ��� ���� ����������
*/


class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = 0, cnt = 0;
        while (r < k) {
            cnt += blocks[r] == 'W' ? 1 : 0;
            r++;
        }
        int res = cnt;
        while (r < blocks.size()) {
            cnt += blocks[r] == 'W' ? 1 : 0;
            cnt -= blocks[l] == 'W' ? 1 : 0;
            res = min(res, cnt);
            l++;
            r++;
        }
        return res;
    }
};
