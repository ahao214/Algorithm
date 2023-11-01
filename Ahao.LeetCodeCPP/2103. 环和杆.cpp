#include<vector>
#include <string>

using namespace std;

/*
2103. ���͸�

�ܼ��� n ������������ɫ�����Ǻ졢�̡����е�һ�֡���Щ���ֱ��� 10 �����Ϊ 0 �� 9 �ĸ��ϡ�

����һ������Ϊ 2n ���ַ��� rings ����ʾ�� n �����ڸ��ϵķֲ���rings ��ÿ�����ַ��γ�һ�� ��ɫλ�ö� ����������ÿ������

�� i ���е� ��һ�� �ַ���ʾ�� i ������ ��ɫ��'R'��'G'��'B'����
�� i ���е� �ڶ��� �ַ���ʾ�� i ������ λ�ã�Ҳ����λ���ĸ����ϣ�'0' �� '9'����
���磬"R3G2B1" ��ʾ������ n == 3 ��������ɫ�Ļ��ڱ��Ϊ 3 �ĸ��ϣ���ɫ�Ļ��ڱ��Ϊ 2 �ĸ��ϣ���ɫ�Ļ��ڱ��Ϊ 1 �ĸ��ϡ�

�ҳ����м��� ȫ��������ɫ ���ĸˣ����������ָ˵�������
*/



class Solution {
public:
    static constexpr int POLE_NUM = 10;
    static constexpr int COLOR_NUM = 3;
    int getColorId(char color) {
        if (color == 'R') {
            return 0;
        }
        else if (color == 'G') {
            return 1;
        }
        return 2;
    }
    int countPoints(string rings) {
        vector<vector<int>> state(POLE_NUM, vector<int>(COLOR_NUM, 0));
        int n = rings.size();
        for (int i = 0; i < n; i += 2) {
            char color = rings[i];
            int pole_index = rings[i + 1] - '0';
            state[pole_index][getColorId(color)] = 1;
        }
        int res = 0;
        for (int i = 0; i < POLE_NUM; i++) {
            bool flag = true;
            for (int j = 0; j < COLOR_NUM; j++) {
                if (state[i][j] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res++;
            }
        }
        return res;
    }
};


class Solution {
public:
    static constexpr int POLE_NUM = 10;
    int countPoints(string rings) {
        vector<int> state(POLE_NUM);
        int n = rings.size();
        for (int i = 0; i < n; i += 2) {
            char color = rings[i];
            int pole_index = rings[i + 1] - '0';
            if (color == 'R') {
                state[pole_index] |= 1;
            }
            else if (color == 'G') {
                state[pole_index] |= 2;
            }
            else {
                state[pole_index] |= 4;
            }
        }
        int res = 0;
        for (int i = 0; i < POLE_NUM; i++) {
            res += state[i] == 7;
        }
        return res;
    }
};
