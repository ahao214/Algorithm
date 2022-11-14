#include <string>

using namespace std;


/*
2166. 设计位集
位集 Bitset 是一种能以紧凑形式存储位的数据结构。

请你实现 Bitset 类。

Bitset(int size) 用 size 个位初始化 Bitset ，所有位都是 0 。
void fix(int idx) 将下标为 idx 的位上的值更新为 1 。如果值已经是 1 ，则不会发生任何改变。
void unfix(int idx) 将下标为 idx 的位上的值更新为 0 。如果值已经是 0 ，则不会发生任何改变。
void flip() 翻转 Bitset 中每一位上的值。换句话说，所有值为 0 的位将会变成 1 ，反之亦然。
boolean all() 检查 Bitset 中 每一位 的值是否都是 1 。如果满足此条件，返回 true ；否则，返回 false 。
boolean one() 检查 Bitset 中 是否 至少一位 的值是 1 。如果满足此条件，返回 true ；否则，返回 false 。
int count() 返回 Bitset 中值为 1 的位的 总数 。
String toString() 返回 Bitset 的当前组成情况。注意，在结果字符串中，第 i 个下标处的字符应该与 Bitset 中的第 i 位一致。
*/
class Bitset {
public:
    bool a[100005];
    int b[2];
    int nowsiz;
    int now;
    Bitset(int size) {
        nowsiz = size; now = 0;
        for (int i = 1; i <= size; i++) a[i] = 0;
        b[0] = size;
        b[1] = 0;
    }

    void fix(int idx) {
        idx++;
        b[a[idx] ^ now]--;
        a[idx] = 1 ^ now;
        b[a[idx] ^ now]++;
    }

    void unfix(int idx) {
        idx++;
        b[a[idx] ^ now]--;
        a[idx] = 0 ^ now;
        b[a[idx] ^ now]++;
    }

    void flip() {
        now ^= 1;
        swap(b[0], b[1]);
    }

    bool all() {
        return (b[1] == nowsiz);
    }

    bool one() {
        return (b[1] > 0);

    }

    int count() {
        return b[1];
    }

    string toString() {
        string st = "";
        for (int i = 1; i <= nowsiz; i++)
            if ((a[i] ^ now) == 1) st += '1';
            else st += '0';
        return st;
    }
};