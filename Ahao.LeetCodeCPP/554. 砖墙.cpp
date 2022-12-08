#include<vector>
#include <unordered_map>

using namespace std;


/*
554. שǽ
�����ǰ��һ�¾��εġ��� n ��ש����ɵ�שǽ����Щש��߶���ͬ��Ҳ����һ����λ�ߣ����ǿ�Ȳ�ͬ��ÿһ��ש��Ŀ��֮����ȡ�

������Ҫ��һ�� �Զ����� �ġ����� ���� ש��Ĵ��ߡ�����㻭����ֻ�Ǵ�ש��ı�Ե�������Ͳ��㴩�����ש���㲻������ǽ��������ֱ��Ե֮һ���ߣ�������Ȼ��û�д���һ��ש�ġ�

����һ����ά���� wall ��������������ǽ�������Ϣ�����У�wall[i] ��һ�������������ÿ��ש�Ŀ�ȵ����顣����Ҫ�ҳ�����������ʹ������ ������ש���������٣����ҷ��ش�����ש������ ��
*/
class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		unordered_map<int, int> hash;
		int res = 0;
		for (auto blocks : wall)
		{
			int s = 0;
			for (int i = 0; i + 1 < blocks.size(); i++)
			{
				s += blocks[i];
				res = max(res, ++hash[s]);
			}
		}
		return wall.size() - res;
	}
};