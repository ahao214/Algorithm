#include<vector>
#include<unordered_map>

using namespace std;


/*
133. ¿ËÂ¡Í¼
*/


class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};


class Solution {
	unordered_map<Node*, Node*> visited;
public:
	Node* cloneGraph(Node* node) {
		if (!node)
		{
			return nullptr;
		}
		if (visited.count(node))
		{
			return visited[node];
		}
		Node* clone = new Node(node->val);
		visited[node] = clone;
		for (Node* neighbor : node->neighbors)
		{
			clone->neighbors.push_back(cloneGraph(neighbor));
		}
		return clone;
	}
};




class Solution {
	unordered_map<Node*, Node*> h;
public:
	Node* cloneGraph(Node* node) {
		if (!node) return nullptr;
		dfs(node);
		for (auto [from, to] : h)
		{
			for (auto next : from->neighbors)
				to->neighbors.push_back(h[next]);
		}
		return h[node];
	}

	void dfs(Node* node)
	{
		h[node] = new Node(node->val);
		for (auto next : node->neighbors)
		{
			if (!h[next])
				dfs(next);
		}
	}
};

