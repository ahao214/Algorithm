﻿/*
1622. 奇妙序列

难度：困难

请你实现三个 API append，addAll 和 multAll 来实现奇妙序列。

请实现 Fancy 类 ：

Fancy() 初始化一个空序列对象。
void append(val) 将整数 val 添加在序列末尾。
void addAll(inc) 将所有序列中的现有数值都增加 inc 。
void multAll(m) 将序列中的所有现有数值都乘以整数 m 。
int getIndex(idx) 得到下标为 idx 处的数值（下标从 0 开始），并将结果对 109 + 7 取余。如果下标大于等于序列的长度，请返回 -1 。
*/