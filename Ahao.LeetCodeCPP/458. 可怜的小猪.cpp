#include<vector>

using namespace std;


/*
458. ������С��
�� buckets ͰҺ�壬���� ������һͰ ���ж�ҩ������װ�Ķ���ˮ�����Ǵ���ۿ�������һ����Ϊ��Ū�����ֻˮͰ���ж�ҩ�������ιһЩ��ȣ�ͨ���۲����Ƿ���������жϡ����ҵ��ǣ���ֻ�� minutesToTest ����ʱ����ȷ����ͰҺ�����ж��ġ�

ι��Ĺ������£�

ѡ�����ɻ������ι��
��������С��ͬʱ��������������Ͱ�е�ˮ�����Ҹù��̲���Ҫʱ�䡣
С�����ˮ�󣬱����� minutesToDie ���ӵ���ȴʱ�䡣�����ʱ�����ֻ�ܹ۲죬�����������ι��
���� minutesToDie ���Ӻ����кȵ���ҩ��������ȥ���������������������
�ظ���һ���̣�ֱ��ʱ�����ꡣ
����Ͱ����Ŀ buckets ��minutesToDie �� minutesToTest ������ �ڹ涨ʱ�����ж��ĸ�Ͱ�ж������ ��С ���� ��
*/
class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		int b = minutesToTest / minutesToDie + 1;
		int k = 0, n = 1;
		while (n < buckets) k++, n *= b;
		return k;
	}
};
