#include<string>

using namespace std;



/*
1754. 构造字典序最大的合并字符串
给你两个字符串 word1 和 word2 。你需要按下述方式构造一个新字符串 merge ：如果 word1 或 word2 非空，选择 下面选项之一 继续操作：

如果 word1 非空，将 word1 中的第一个字符附加到 merge 的末尾，并将其从 word1 中移除。
例如，word1 = "abc" 且 merge = "dv" ，在执行此选项操作之后，word1 = "bc" ，同时 merge = "dva" 。
如果 word2 非空，将 word2 中的第一个字符附加到 merge 的末尾，并将其从 word2 中移除。
例如，word2 = "abc" 且 merge = "" ，在执行此选项操作之后，word2 = "bc" ，同时 merge = "a" 。
返回你可以构造的字典序 最大 的合并字符串 merge 。

长度相同的两个字符串 a 和 b 比较字典序大小，如果在 a 和 b 出现不同的第一个位置，a 中字符在字母表中的出现顺序位于 b 中相应字符之后，就认为字符串 a 按字典序比字符串 b 更大。例如，"abcd" 按字典序比 "abcc" 更大，因为两个字符串出现不同的第一个位置是第四个字符，而 d 在字母表中的出现顺序位于 c 之后。
*/
class Solution {
public:
	string largestMerge(string word1, string word2) {
		string res;
		int i = 0, j = 0;
		while (i < word1.size() || j < word2.size())
		{
			if (word1.substr(i) > word2.substr(j))
				res += word1[i++];
			else
				res += word2[j++];
		}
		return res;
	}
};



vector<int> sortCharacters(const string& text) {
    int n = text.size();
    vector<int> count(128), order(n);
    for (auto c : text) {
        count[c]++;
    }
    for (int i = 1; i < 128; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        count[text[i]]--;
        order[count[text[i]]] = i;
    }
    return order;
}

vector<int> computeCharClasses(const string& text, vector<int>& order) {
    int n = text.size();
    vector<int> res(n, 0);
    res[order[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (text[order[i]] != text[order[i - 1]]) {
            res[order[i]] = res[order[i - 1]] + 1;
        }
        else {
            res[order[i]] = res[order[i - 1]];
        }
    }
    return res;
}

vector<int> sortDoubled(const string& text, int len, vector<int>& order, vector<int>& classfiy) {
    int n = text.size();
    vector<int> count(n), newOrder(n);
    for (int i = 0; i < n; i++) {
        count[classfiy[i]]++;
    }
    for (int i = 1; i < n; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int start = (order[i] - len + n) % n;
        int cl = classfiy[start];
        count[cl]--;
        newOrder[count[cl]] = start;
    }
    return newOrder;
}

vector<int> updateClasses(vector<int>& newOrder, vector<int>& classfiy, int len) {
    int n = newOrder.size();
    vector<int> newClassfiy(n, 0);
    newClassfiy[newOrder[0]] = 0;
    for (int i = 1; i < n; i++) {
        int curr = newOrder[i];
        int prev = newOrder[i - 1];
        int mid = curr + len;
        int midPrev = (prev + len) % n;
        if (classfiy[curr] != classfiy[prev] || classfiy[mid] != classfiy[midPrev]) {
            newClassfiy[curr] = newClassfiy[prev] + 1;
        }
        else {
            newClassfiy[curr] = newClassfiy[prev];
        }
    }
    return newClassfiy;
}

vector<int> buildSuffixArray(const string& text) {
    vector<int> order = sortCharacters(text);
    vector<int> classfiy = computeCharClasses(text, order);
    int len = 1;
    int n = text.size();
    for (int i = 1; i < n; i <<= 1) {
        order = sortDoubled(text, i, order, classfiy);
        classfiy = updateClasses(order, classfiy, i);
    }
    return order;
}

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        string str = word1 + "@" + word2 + "*";
        vector<int> suffixArray = buildSuffixArray(str);
        vector<int> rank(m + n + 2);
        for (int i = 0; i < m + n + 2; i++) {
            rank[suffixArray[i]] = i;
        }

        string merge;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i < m && rank[i] > rank[m + 1 + j]) {
                merge.push_back(word1[i++]);
            }
            else {
                merge.push_back(word2[j++]);
            }
        }
        return merge;
    }
};
