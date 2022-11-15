#include<vector>

using namespace std;


/*
1462. 课程表 IV
你总共需要上 n 门课，课程编号依次为 0 到 n-1 。

有的课会有直接的先修课程，比如如果想上课程 0 ，你必须先上课程 1 ，那么会以 [1,0] 数对的形式给出先修课程数对。

给你课程总数 n 和一个直接先修课程数对列表 prerequisite 和一个查询对列表 queries 。

对于每个查询对 queries[i] ，请判断 queries[i][0] 是否是 queries[i][1] 的先修课程。

请返回一个布尔值列表，列表中每个元素依次分别对应 queries 每个查询对的判断结果。

注意：如果课程 a 是课程 b 的先修课程且课程 b 是课程 c 的先修课程，那么课程 a 也是课程 c 的先修课程。
*/
class Solution {
public:
	vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

		vector<vector<bool>> d(numCourses, vector<bool>(numCourses));

		for (auto e : prerequisites) d[e[0]][e[1]] = true;
		for (int k = 0; k < numCourses; k++)
		{
			for (int i = 0; i < numCourses; i++)
				for (int j = 0; j < numCourses; j++)
					if (d[i][k] && d[k][j])
						d[i][j] = true;
		}

		vector<bool> res;
		for (auto q : queries)
			res.push_back(d[q[0]][q[1]]);
		return res;
	}
};
