#include<vector>
#include<string>
#include <unordered_set>

using namespace std;


class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> seen;
        for (char ch : s) {
            if (seen.count(ch)) {
                return ch;
            }
            seen.insert(ch);
        }
        // impossible
        return ' ';
    }
};
