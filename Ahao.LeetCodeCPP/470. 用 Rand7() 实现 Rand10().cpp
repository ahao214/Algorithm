#include<vector>
#include<algorithm>

using namespace std;


/*
470. �� Rand7() ʵ�� Rand10()
*/
class Solution {
public:
	int rand10() {
		int t = (rand7() - 1) * 7 + rand7();	//1~49

		if (t > 40) return rand10();
		return (t - 1) % 10 + 1;
	}
};
