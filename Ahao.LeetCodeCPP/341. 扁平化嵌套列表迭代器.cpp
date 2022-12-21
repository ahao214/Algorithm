#include<vector>

using namespace std;


/*
341. 扁平化嵌套列表迭代器
给你一个嵌套的整数列表 nestedList 。每个元素要么是一个整数，要么是一个列表；该列表的元素也可能是整数或者是其他列表。请你实现一个迭代器将其扁平化，使之能够遍历这个列表中的所有整数。

实现扁平迭代器类 NestedIterator ：

NestedIterator(List<NestedInteger> nestedList) 用嵌套列表 nestedList 初始化迭代器。
int next() 返回嵌套列表的下一个整数。
boolean hasNext() 如果仍然存在待迭代的整数，返回 true ；否则，返回 false 。
你的代码将会用下述伪代码检测：

initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
如果 res 与预期的扁平化列表匹配，那么你的代码将会被判为正确。
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