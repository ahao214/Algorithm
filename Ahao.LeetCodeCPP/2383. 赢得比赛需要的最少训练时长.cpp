#include<vector>

using namespace std;

/*
2383. Ӯ�ñ�����Ҫ������ѵ��ʱ��

�����ڲμ�һ���������������� �� ���� initialEnergy �� initialExperience �ֱ��ʾ��ĳ�ʼ�����ͳ�ʼ���顣

����������±�� 0 ��ʼ���������� energy �� experience�����Ⱦ�Ϊ n ��

�㽫�� ���� ���� n �����֡��� i �����ֵľ����;���ֱ��� energy[i] �� experience[i] ��ʾ��������϶���ʱ����Ҫ�ھ���;����϶� �ϸ� �������ֲ��ܻ������ǣ�Ȼ���ڿ��ܵ�����¼���������һ�����֡�

���ܵ� i �����ֻ�ʹ��ľ��� ���� experience[i]�����Ὣ��ľ��� ����  energy[i] ��

�ڿ�ʼ����ǰ�������ѵ������Сʱ��ÿѵ��һ��Сʱ�������ѡ�����Ӿ������� 1 ���� ���������� 1 ��

���ػ���ȫ�� n ��������Ҫѵ���� ���� Сʱ��Ŀ��
*/

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sum = 0;
        for (int e : energy) {
            sum += e;
        }
        int trainingHours = initialEnergy > sum ? 0 : sum + 1 - initialEnergy;
        for (int e : experience) {
            if (initialExperience <= e) {
                trainingHours += 1 + (e - initialExperience);
                initialExperience = 2 * e + 1;
            }
            else {
                initialExperience += e;
            }
        }
        return trainingHours;
    }
};
