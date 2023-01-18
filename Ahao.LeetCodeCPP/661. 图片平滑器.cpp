using namespace std;
#include<vector>

/*
661. ͼƬƽ����
ͼ��ƽ���� �Ǵ�СΪ 3 x 3 �Ĺ����������ڶ�ͼ���ÿ����Ԫ��ƽ������ƽ�������Ԫ���ֵΪ�õ�Ԫ���ƽ���Ҷȡ�

ÿ����Ԫ���  ƽ���Ҷ� ����Ϊ���õ�Ԫ����������Χ�� 8 ����Ԫ���ƽ��ֵ�����������ȡ������������Ҫ������ɫƽ������ 9 ����Ԫ���ƽ��ֵ����

���һ����Ԫ����Χ���ڵ�Ԫ��ȱʧ������������ƽ���Ҷ�ʱ������ȱʧ�ĵ�Ԫ�񣨼�����Ҫ�����ɫƽ������ 4 ����Ԫ���ƽ��ֵ����
*/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int num = 0, sum = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            num++;
                            sum += img[x][y];
                        }
                    }
                }
                ret[i][j] = sum / num;
            }
        }
        return ret;
    }
};
