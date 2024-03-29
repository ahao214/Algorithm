#include<vector>
#include <queue>

using namespace std;



/*
1792. 最大平均通过率
一所学校里有一些班级，每个班级里有一些学生，现在每个班都会进行一场期末考试。给你一个二维数组 classes ，其中 classes[i] = [passi, totali] ，表示你提前知道了第 i 个班级总共有 totali 个学生，其中只有 passi 个学生可以通过考试。

给你一个整数 extraStudents ，表示额外有 extraStudents 个聪明的学生，他们 一定 能通过任何班级的期末考。你需要给这 extraStudents 个学生每人都安排一个班级，使得 所有 班级的 平均 通过率 最大 。

一个班级的 通过率 等于这个班级通过考试的学生人数除以这个班级的总人数。平均通过率 是所有班级的通过率之和除以班级数目。

请你返回在安排这 extraStudents 个学生去对应班级后的 最大 平均通过率。与标准答案误差范围在 10-5 以内的结果都会视为正确结果。
*/
class Solution {
public:
	double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
		struct Node {
			double v;
			int a, b;
			bool operator< (const Node& t) const {
				return v < t.v;
			}
		};

		priority_queue<Node> heap;
		double sum = 0;
		for (auto& c : classes)
		{
			int a = c[1], b = c[0];
			sum += (double)b / a;
			heap.push({ (a - b) / (a * (a + 1.0)),a,b });
		}

		while (extraStudents--)
		{
			auto t = heap.top();
			heap.pop();
			sum += t.v;
			int a = t.a + 1, b = t.b + 1;
			heap.push({ (a - b) / (a * (a + 1.0)),a,b });
		}
		return sum / classes.size();
	}
};



class Solution {
public:
	struct Ratio {
		int pass, total;
		bool operator < (const Ratio& oth) const {
			return (long long)(oth.total + 1) * oth.total * (total - pass) < (long long)(total + 1) * total * (oth.total - oth.pass);
		}
	};

	double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
		priority_queue<Ratio> q;
		for (auto& c : classes) {
			q.push({ c[0], c[1] });
		}

		for (int i = 0; i < extraStudents; i++) {
			auto [pass, total] = q.top();
			q.pop();
			q.push({ pass + 1, total + 1 });
		}

		double res = 0;
		for (int i = 0; i < classes.size(); i++) {
			auto [pass, total] = q.top();
			q.pop();
			res += 1.0 * pass / total;
		}
		return res / classes.size();
	}
};
