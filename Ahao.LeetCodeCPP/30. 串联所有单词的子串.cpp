using namespace std;
#include<vector>
#include<string>
#include<unordered_map>


/*
30. �������е��ʵ��Ӵ�
����һ���ַ��� s ��һЩ ������ͬ �ĵ��� words ��
�ҳ� s ��ǡ�ÿ����� words �����е��ʴ����γɵ��Ӵ�����ʼλ�á�

ע���Ӵ�Ҫ�� words �еĵ�����ȫƥ�䣬�м䲻���������ַ� ��
������Ҫ���� words �е��ʴ�����˳��
*/
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		if (words.empty()) return ans;

		int n = s.length(), m = words.size(), w = words[0].length();

		unordered_map<string, int> total;
		for (int i = 0; i < words.size(); i++) {
			total[words[i]]++;
		}

		for (int i = 0; i < w; i++) {
			unordered_map<string, int> window;
			int cnt = 0;
			for (int j = i; j + w <= n; j += w) {
				if (j - i >= m * w) {
					string word = s.substr(j - m * w, w);
					window[word]--;
					if (window[word] < total[word])
						cnt--;
				}
				string word = s.substr(j, w);
				window[word]++;
				if (window[word] <= total[word])
					cnt++;
				if (cnt == m)
					ans.push_back(j - (m - 1) * w);
			}
		}
		return ans;
	}
};





/*
30. �������е��ʵ��Ӵ�
����һ���ַ��� s ��һЩ ������ͬ �ĵ��� words ���ҳ� s ��ǡ�ÿ����� words �����е��ʴ����γɵ��Ӵ�����ʼλ�á�

ע���Ӵ�Ҫ�� words �еĵ�����ȫƥ�䣬�м䲻���������ַ� ��������Ҫ���� words �е��ʴ�����˳��
*/
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		int n = s.size(), m = words.size(), w = words[0].size();
		unordered_map<string, int> hashmap;
		for (int i = 0; i < m; i++) hashmap[words[i]]++;
		for (int i = 0; i < w; i++)
		{
			unordered_map<string, int> tdict;
			int sum = 0;
			int l = i;
			for (int j = l; j + w <= n; j += w)
			{
				string word;
				if (j - m * w >= l)
				{
					word = s.substr(j - m * w, w);
					if (tdict[word] == hashmap[word]) sum -= hashmap[word];
					tdict[word]--;
					if (tdict[word] == hashmap[word]) sum += hashmap[word];
				}
				word = s.substr(j, w);
				if (hashmap.count(word) == 0)
				{
					sum = 0;
					tdict.clear();
					l = j + w;
				}
				else
				{
					if (tdict[word] == hashmap[word]) sum -= hashmap[word];
					tdict[word]++;
					if (tdict[word] == hashmap[word]) sum += hashmap[word];
				}
				if (sum == m) res.push_back(j - (m - 1) * w);
			}
		}
		return res;
	}
};