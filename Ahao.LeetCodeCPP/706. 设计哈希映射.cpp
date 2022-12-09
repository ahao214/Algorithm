#include<vector>

using namespace std;



/*
706. ��ƹ�ϣӳ��
��ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣӳ�䣨HashMap����

ʵ�� MyHashMap �ࣺ

MyHashMap() �ÿ�ӳ���ʼ������
void put(int key, int value) �� HashMap ����һ����ֵ�� (key, value) ����� key �Ѿ�������ӳ���У���������Ӧ��ֵ value ��
int get(int key) �����ض��� key ��ӳ��� value �����ӳ���в����� key ��ӳ�䣬���� -1 ��
void remove(key) ���ӳ���д��� key ��ӳ�䣬���Ƴ� key ��������Ӧ�� value ��
*/
class Solution {
public:
	const static int N = 20011;
	vector<list<pair<int, int>>> hash;
	void MyHashMap() {
		hash = vector<list<pair<int, int>>>(N);
	}

	list<pair<int, int>>::iterator find(int key)
	{
		int t = key % N;
		auto it = hash[t].begin();
		for (; it != hash[t].end(); it++)
		{
			if (it->first == key)
				break;
		}
		return it;
	}

	void put(int key, int value) {
		int t = key % N;
		auto it = find(key);
		if (it == hash[t].end())
			hash[t].push_back(make_pair(key, value));
		else
			it->second = value;
	}

	int get(int key) {
		auto it = find(key);
		if (it == hash[key % N].end())
			return -1;
		return it->second;
	}

	void remove(int key) {
		int t = key % N;
		auto it = find(key);
		if (it != hash[t].end())
			hash[t].erase(it);
	}

public:
	const static int N = 20011;
	int hash_key[N], hash_value[N];

	MyHashMap() {
		memset(hash_key, -1, sizeof hash_key);
	}

	int find(int key, bool is_put)
	{
		int t = key % N;
		while (hash_key[t] != key && hash_key[t] != -1)
		{
			if (is_put && hash_key[t] == -2)
				break;
			if (++t == N) t = 0;
		}
		return t;
	}

	void put(int key, int value) {
		int t = find(key, true);
		hash_key[t] = key;
		hash_value[t] = value;
	}

	int get(int key) {
		int t = find(key, false);
		if (hash_key[t] == -1) return -1;
		return hash_value[t];
	}

	void remove(int key) {
		int t = find(key, false);
		if (hash_key[t] != -1)
			hash_key[t] = -2;
	}
};

