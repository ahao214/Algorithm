#include<vector>

using namespace std;



/*
706. 设计哈希映射
不使用任何内建的哈希表库设计一个哈希映射（HashMap）。

实现 MyHashMap 类：

MyHashMap() 用空映射初始化对象
void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。
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

