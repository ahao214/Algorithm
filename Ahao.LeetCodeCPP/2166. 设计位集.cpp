#include <string>

using namespace std;


/*
2166. ���λ��
λ�� Bitset ��һ�����Խ�����ʽ�洢λ�����ݽṹ��

����ʵ�� Bitset �ࡣ

Bitset(int size) �� size ��λ��ʼ�� Bitset ������λ���� 0 ��
void fix(int idx) ���±�Ϊ idx ��λ�ϵ�ֵ����Ϊ 1 �����ֵ�Ѿ��� 1 ���򲻻ᷢ���κθı䡣
void unfix(int idx) ���±�Ϊ idx ��λ�ϵ�ֵ����Ϊ 0 �����ֵ�Ѿ��� 0 ���򲻻ᷢ���κθı䡣
void flip() ��ת Bitset ��ÿһλ�ϵ�ֵ�����仰˵������ֵΪ 0 ��λ������ 1 ����֮��Ȼ��
boolean all() ��� Bitset �� ÿһλ ��ֵ�Ƿ��� 1 �������������������� true �����򣬷��� false ��
boolean one() ��� Bitset �� �Ƿ� ����һλ ��ֵ�� 1 �������������������� true �����򣬷��� false ��
int count() ���� Bitset ��ֵΪ 1 ��λ�� ���� ��
String toString() ���� Bitset �ĵ�ǰ��������ע�⣬�ڽ���ַ����У��� i ���±괦���ַ�Ӧ���� Bitset �еĵ� i λһ�¡�
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