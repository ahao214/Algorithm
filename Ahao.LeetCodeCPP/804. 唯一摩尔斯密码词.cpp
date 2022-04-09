using namespace std;
#include<vector>
#include<string>
#include <unordered_set>
#include <set>


const static string MORSE[] = {
		".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
		"....", "..", ".---", "-.-", ".-..", "--", "-.",
		"---", ".--.", "--.-", ".-.", "...", "-", "..-",
		"...-", ".--", "-..-", "-.--", "--.."
};

class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		unordered_set<string> sh;
		for (auto& word : words)
		{
			string code;
			for (auto& w : word)
			{
				code.append(MORSE[w - 'a']);
			}
			sh.emplace(code);
		}
		return sh.size();
	}
};


class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		set<string> st;
		string keys[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
		for (int i = 0; i < words.size(); i++) {
			string str;
			for (int j = 0; j < words[i].size(); j++) {
				str += keys[words[i][j] - 'a'];
			}
			st.insert(str);
		}
		return st.size();
	}
};
