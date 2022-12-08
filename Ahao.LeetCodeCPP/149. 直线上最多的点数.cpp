#include<vector>

using namespace std;


/*
149. ֱ�������ĵ���
����һ������ points ������ points[i] = [xi, yi] ��ʾ X-Y ƽ���ϵ�һ���㡣������ж��ٸ�����ͬһ��ֱ���ϡ�
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        // �����������
        if (len < 3) {
            return len;
        }
        int maxNum = 2;
        // ����ÿ������
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                // ͳ��б����ȸ���
                int count = 2;
                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];
                // ��������Ƚ�
                for (int k = j + 1; k < len; k++) {
                    // ���б�����
                    if (dx * (points[i][1] - points[k][1]) == dy * (points[i][0] - points[k][0])) {
                        count++;
                    }
                }
                maxNum = max(maxNum, count);
                if (maxNum > len / 2) return maxNum;
            }
        }
        return maxNum;
    }
};