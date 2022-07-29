#include<vector>
#include<stack>

using namespace std;


/*
offer 31 栈的压入弹出序列
*/
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty() || popV.empty() || pushV.size() != popV.size()) {
			return false;
		}
		stack<int> s;
		int j = 0;
		for (int i = 0; i < pushV.size(); ++i) {
			s.push(pushV[i]);
			while (!s.empty() && s.top() == popV[j]) {
				s.pop();
				++j;
			}
		}
		return s.empty();
	}
};