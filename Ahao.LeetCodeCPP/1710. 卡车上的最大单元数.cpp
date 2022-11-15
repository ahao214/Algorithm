#include<vector>
#include <algorithm>

using namespace std;


/*
1710. �����ϵ����Ԫ��
���㽫һЩ����װ�� һ������ �ϡ�����һ����ά���� boxTypes ������ boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi] ��

numberOfBoxesi ������ i �����ӵ�������
numberOfUnitsPerBoxi ������ i ÿ�����ӿ���װ�صĵ�Ԫ������
���� truckSize ��ʾ�����Ͽ���װ�� ���� �� ������� ��ֻҪ�������������� truckSize ����Ϳ���ѡ����������װ�������ϡ�

���ؿ�������װ�� ��Ԫ �� ��� ������
*/
class Solution {
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
		sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b) {
			return a[1] > b[1];
			});

		int res = 0;
		for (int i = 0; i < boxTypes.size() && truckSize > 0; i++)
		{
			int cur = min(boxTypes[i][0], truckSize);
			res += cur * boxTypes[i][1];
			truckSize -= cur;
		}
		return res;
	}
};


class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
            });
        int res = 0;
        for (auto& boxType : boxTypes) {
            int numberOfBoxes = boxType[0];
            int numberOfUnitsPerBox = boxType[1];
            if (numberOfBoxes < truckSize) {
                res += numberOfBoxes * numberOfUnitsPerBox;
                truckSize -= numberOfBoxes;
            }
            else {
                res += truckSize * numberOfUnitsPerBox;
                break;
            }
        }
        return res;
    }
};
