#include<vector>
#include<string>

using namespace std;



/*
1769. �ƶ�������ÿ�������������С������
�� n �����ӡ�����һ������Ϊ n �Ķ������ַ��� boxes ������ boxes[i] ��ֵΪ '0' ��ʾ�� i �������� �� �ģ��� boxes[i] ��ֵΪ '1' ��ʾ�������� һ�� С��

��һ�������У�����Խ� һ�� С���ĳ�������ƶ���һ����֮���ڵĺ����С��� i �����Ӻ͵� j ���������������� abs(i - j) == 1 ��ע�⣬����ִ�к�ĳЩ�����п��ܻ���ڲ�ֹһ��С��

����һ������Ϊ n ������ answer ������ answer[i] �ǽ�����С���ƶ����� i ����������� ��С ��������

ÿ�� answer[i] ����Ҫ���ݺ��ӵ� ��ʼ״̬ ���м��㡣
*/
class Solution {
public:
	vector<int> minOperations(string boxes) {
		int n = boxes.size();
		vector<int> ans(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (boxes[j] == '1')
					ans[i] += abs(i - j);
		return ans;
	}
};

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int sm = 0;
            for (int j = 0; j < n; j++) {
                if (boxes[j] == '1') {
                    sm += abs(j - i);
                }
            }
            res[i] = sm;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> minOperations(string boxes) {
        int left = boxes[0] - '0', right = 0, operations = 0;
        int n = boxes.size();
        for (int i = 1; i < n; i++) {
            if (boxes[i] == '1') {
                right++;
                operations += i;
            }
        }
        vector<int> res(n);
        res[0] = operations;
        for (int i = 1; i < n; i++) {
            operations += left - right;
            if (boxes[i] == '1') {
                left++;
                right--;
            }
            res[i] = operations;
        }
        return res;
    }
};
