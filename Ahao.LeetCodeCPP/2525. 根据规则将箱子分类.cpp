#include<vector>
#include<string>

using namespace std;


/*
2525. ���ݹ������ӷ���

�����ĸ����� length ��width ��height �� mass ���ֱ��ʾһ�����ӵ�����ά�Ⱥ����������㷵��һ����ʾ���� ��� ���ַ�����

�������������������ô������ "Bulky" �ģ�
���� ������һ�� ά�ȴ��ڵ��� 104 ��
�������ӵ� ��� ���ڵ��� 109 ��
������ӵ��������ڵ��� 100 ����ô������ "Heavy" �ġ�
�������ͬʱ�� "Bulky" �� "Heavy" ����ô�������Ϊ "Both" ��
������ӼȲ��� "Bulky" ��Ҳ���� "Heavy" ����ô�������Ϊ "Neither" ��
��������� "Bulky" ������ "Heavy" ����ô�������Ϊ "Bulky" ��
��������� "Heavy" ������ "Bulky" ����ô�������Ϊ "Heavy" ��
ע�⣬���ӵ�����������ӵĳ��ȡ���Ⱥ͸߶ȵĳ˻���
*/



class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long maxd = max(length, max(width, height)), vol = 1L * length * width * height;
        bool isBulky = maxd >= 10000 || vol >= 1000000000, isHeavy = mass >= 100;
        if (isBulky && isHeavy) {
            return "Both";
        }
        else if (isBulky) {
            return "Bulky";
        }
        else if (isHeavy) {
            return "Heavy";
        }
        else {
            return "Neither";
        }
    }
};
