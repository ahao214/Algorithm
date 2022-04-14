using namespace std;
#include<vector>
#include <numeric>


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = INT_MIN;
        for (auto& account : accounts) {
            maxWealth = max(maxWealth, accumulate(account.begin(), account.end(), 0));
        }
        return maxWealth;
    }
};
