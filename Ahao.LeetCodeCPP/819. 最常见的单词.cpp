using namespace std;
#include<string>
#include<vector>
#include <unordered_set>
#include <unordered_map>


class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		unordered_set<string>banWords(banned.begin(), banned.end());
		for (char& c : paragraph) {
			c = tolower(c);
		}
		unordered_map<string, int>s2cnt;
		int i = 0;
		int ansCnt = INT_MIN;
		string ans;
		while (i < paragraph.size()) {
			if (isalpha(paragraph[i])) {
				int j = i;
				i++;
				while (i < paragraph.size() && isalpha(paragraph[i]))i++;
				string tmp = paragraph.substr(j, i - j);
				if (banWords.count(tmp) == 0) {
					s2cnt[tmp]++;
					if (ansCnt < s2cnt[tmp]) {
						ansCnt = s2cnt[tmp];
						ans = tmp;
					}
				}
			}
			i++;
		}
		return ans;
	}
};
