#include<vector>
#include <set>

using namespace std;


/*
1642. 可以到达的最远建筑
*/
class Solution {
public:
	int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
		multiset<int> st;
		int count = 0;

		for (int i = 1; i < heights.size(); i++)
		{
			if (heights[i] <= heights[i - 1])
				continue;

			if (count < ladders)
			{
				count++;
				st.insert(heights[i] - heights[i - 1]);
			}
			else
			{
				st.insert(heights[i] - heights[i - 1]);
				if (bricks < *st.begin())
					return i - 1;
				bricks -= *st.begin();
				st.erase(st.begin());
			}
		}
		return heights.size() - 1;
	}
};