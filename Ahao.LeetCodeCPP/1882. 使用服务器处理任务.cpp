#include<vector>
#include <queue>

using namespace std;


/*
1882. 使用服务器处理任务
给你两个 下标从 0 开始 的整数数组 servers 和 tasks ，长度分别为 n​​​​​​ 和 m​​​​​​ 。servers[i] 是第 i​​​​​​​​​​ 台服务器的 权重 ，而 tasks[j] 是处理第 j​​​​​​ 项任务 所需要的时间（单位：秒）。

你正在运行一个仿真系统，在处理完所有任务后，该系统将会关闭。每台服务器只能同时处理一项任务。第 0 项任务在第 0 秒可以开始处理，相应地，第 j 项任务在第 j 秒可以开始处理。处理第 j 项任务时，你需要为它分配一台 权重最小 的空闲服务器。如果存在多台相同权重的空闲服务器，请选择 下标最小 的服务器。如果一台空闲服务器在第 t 秒分配到第 j 项任务，那么在 t + tasks[j] 时它将恢复空闲状态。

如果没有空闲服务器，则必须等待，直到出现一台空闲服务器，并 尽可能早 地处理剩余任务。 如果有多项任务等待分配，则按照 下标递增 的顺序完成分配。

如果同一时刻存在多台空闲服务器，可以同时将多项任务分别分配给它们。

构建长度为 m 的答案数组 ans ，其中 ans[j] 是第 j 项任务分配的服务器的下标。

返回答案数组 ans​​​​ 。
*/
class Solution {
public:
	struct Node1 {
		int w, id, tm;
		bool operator< (const Node1& t)const {
			if (tm != t.tm) return tm > t.tm;
			if (w != t.w) return w > t.w;
			return id > t.id;
		}
	};

	struct Node2 {
		int w, id, tm;
		bool operator< (const Node2& t) const {
			if (w != t.w) return w > t.w;
			return id > t.id;
		}
	};

	vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
		priority_queue<Node1> heap1;	//非空闲的
		priority_queue<Node2> heap2;	//空闲的

		for (int i = 0; i < servers.size(); i++)
			heap2.push({ servers[i],i,0 });
		vector<int> res;
		for (int i = 0; i < tasks.size(); i++)
		{
			while (heap1.size() && heap1.top().tm <= i)
			{
				auto t = heap1.top();
				heap2.push({ t.w,t.id,t.tm });
				heap1.pop();
			}
			if (heap2.size())
			{
				auto t = heap2.top();
				heap2.pop();
				res.push_back(t.id);
				heap1.push({ t.w,t.id,i + tasks[i] });
			}
			else
			{
				auto t = heap1.top();
				heap1.pop();
				res.push_back(t.id);
				heap1.push({ t.w,t.id,t.tm + tasks[i] });
			}
		}
		return res;
	}
};

