#include<vector>

using namespace std;


/*
341. ��ƽ��Ƕ���б������
����һ��Ƕ�׵������б� nestedList ��ÿ��Ԫ��Ҫô��һ��������Ҫô��һ���б����б��Ԫ��Ҳ���������������������б�����ʵ��һ�������������ƽ����ʹ֮�ܹ���������б��е�����������

ʵ�ֱ�ƽ�������� NestedIterator ��

NestedIterator(List<NestedInteger> nestedList) ��Ƕ���б� nestedList ��ʼ����������
int next() ����Ƕ���б����һ��������
boolean hasNext() �����Ȼ���ڴ����������������� true �����򣬷��� false ��
��Ĵ��뽫��������α�����⣺

initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
��� res ��Ԥ�ڵı�ƽ���б�ƥ�䣬��ô��Ĵ��뽫�ᱻ��Ϊ��ȷ��
*/
class Solution {
public:
    vector<int> seq;
    int cnt = 0;
    NestedIterator(vector<NestedInteger>& nestedList) {
        dfs(nestedList);
    }

    void dfs(vector<NestedInteger>& nestedList)
    {
        for (auto& l : nestedList)
        {
            if (l.isInteger()) seq.push_back(l.getInteger());
            else dfs(l.getList());
        }
    }

    int next() {
        return seq[cnt++];
    }

    bool hasNext() {
        return cnt < seq.size();
    }
};