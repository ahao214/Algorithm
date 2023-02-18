#include<vector>
#include <queue>

using namespace std;



/*
1792. ���ƽ��ͨ����
һ��ѧУ����һЩ�༶��ÿ���༶����һЩѧ��������ÿ���඼�����һ����ĩ���ԡ�����һ����ά���� classes ������ classes[i] = [passi, totali] ����ʾ����ǰ֪���˵� i ���༶�ܹ��� totali ��ѧ��������ֻ�� passi ��ѧ������ͨ�����ԡ�

����һ������ extraStudents ����ʾ������ extraStudents ��������ѧ�������� һ�� ��ͨ���κΰ༶����ĩ��������Ҫ���� extraStudents ��ѧ��ÿ�˶�����һ���༶��ʹ�� ���� �༶�� ƽ�� ͨ���� ��� ��

һ���༶�� ͨ���� ��������༶ͨ�����Ե�ѧ��������������༶����������ƽ��ͨ���� �����а༶��ͨ����֮�ͳ��԰༶��Ŀ��

���㷵���ڰ����� extraStudents ��ѧ��ȥ��Ӧ�༶��� ��� ƽ��ͨ���ʡ����׼����Χ�� 10-5 ���ڵĽ��������Ϊ��ȷ�����
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
