#include<string>

using namespace std;



/*
1754. �����ֵ������ĺϲ��ַ���
���������ַ��� word1 �� word2 ������Ҫ��������ʽ����һ�����ַ��� merge ����� word1 �� word2 �ǿգ�ѡ�� ����ѡ��֮һ ����������

��� word1 �ǿգ��� word1 �еĵ�һ���ַ����ӵ� merge ��ĩβ��������� word1 ���Ƴ���
���磬word1 = "abc" �� merge = "dv" ����ִ�д�ѡ�����֮��word1 = "bc" ��ͬʱ merge = "dva" ��
��� word2 �ǿգ��� word2 �еĵ�һ���ַ����ӵ� merge ��ĩβ��������� word2 ���Ƴ���
���磬word2 = "abc" �� merge = "" ����ִ�д�ѡ�����֮��word2 = "bc" ��ͬʱ merge = "a" ��
��������Թ�����ֵ��� ��� �ĺϲ��ַ��� merge ��

������ͬ�������ַ��� a �� b �Ƚ��ֵ����С������� a �� b ���ֲ�ͬ�ĵ�һ��λ�ã�a ���ַ�����ĸ���еĳ���˳��λ�� b ����Ӧ�ַ�֮�󣬾���Ϊ�ַ��� a ���ֵ�����ַ��� b �������磬"abcd" ���ֵ���� "abcc" ������Ϊ�����ַ������ֲ�ͬ�ĵ�һ��λ���ǵ��ĸ��ַ����� d ����ĸ���еĳ���˳��λ�� c ֮��
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
