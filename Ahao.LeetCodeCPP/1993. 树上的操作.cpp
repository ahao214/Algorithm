#include<vector>

using namespace std;


/*
1993. ���ϵĲ���

����һ�� n ���ڵ��������Ŵ� 0 �� n - 1 ���Ը��ڵ����� parent ����ʽ���������� parent[i] �ǵ� i ���ڵ�ĸ��ڵ㡣���ĸ��ڵ�Ϊ 0 �Žڵ㣬���� parent[0] = -1 ����Ϊ��û�и��ڵ㡣����Ҫ���һ�����ݽṹʵ��������Խڵ�ļ���������������������

���ݽṹ��Ҫ֧�����º�����

Lock��ָ���û���ָ���ڵ� ���� �������������û����޷���ͬһ�ڵ�������ֻ�е��ڵ㴦��δ������״̬�£����ܽ�������������
Unlock��ָ���û���ָ���ڵ� ���� ��ֻ�е�ָ���ڵ㵱ǰ����ָ���û���סʱ������ִ�иý���������
Upgrade��ָ���û���ָ���ڵ� ���� �����ҽ��ýڵ����������ڵ� ���� ��ֻ������ 3 ������ ȫ�� ����ʱ����ִ������������
ָ���ڵ㵱ǰ״̬Ϊδ������
ָ���ڵ�������һ������״̬������ڵ㣨������ ���� �û������ģ���
ָ���ڵ�û���κ����������Ƚڵ㡣
����ʵ�� LockingTree �ࣺ

LockingTree(int[] parent) �ø��ڵ������ʼ�����ݽṹ��
lock(int num, int user) ��� id Ϊ user ���û����Ը��ڵ� num ��������ô���� true �����򷵻� false ���������ִ�д˲������ڵ� num �ᱻ id Ϊ user ���û� ���� ��
unlock(int num, int user) ��� id Ϊ user ���û����Ը��ڵ� num ��������ô���� true �����򷵻� false ���������ִ�д˲������ڵ� num ��Ϊ δ���� ״̬��
upgrade(int num, int user) ��� id Ϊ user ���û����Ը��ڵ� num ��������ô���� true �����򷵻� false ���������ִ�д˲������ڵ� num �ᱻ ���� ��
*/

class LockingTree {
public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->parent = parent;
        this->lockNodeUser = vector<int>(n, -1);
        this->children = vector<vector<int>>(n);
        for (int i = 0; i < n; i++) {
            int p = parent[i];
            if (p != -1) {
                children[p].emplace_back(i);
            }
        }
    }

    bool lock(int num, int user) {
        if (lockNodeUser[num] == -1) {
            lockNodeUser[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (lockNodeUser[num] == user) {
            lockNodeUser[num] = -1;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        bool res = lockNodeUser[num] == -1 \
            && !hasLockedAncestor(num) \
            && checkAndUnlockDescendant(num);
        if (res) {
            lockNodeUser[num] = user;
        }
        return res;
    }

    bool hasLockedAncestor(int num) {
        num = parent[num];
        while (num != -1) {
            if (lockNodeUser[num] != -1) {
                return true;
            }
            num = parent[num];
        }
        return false;
    }

    bool checkAndUnlockDescendant(int num) {
        bool res = lockNodeUser[num] != -1;
        lockNodeUser[num] = -1;
        for (int child : children[num]) {
            res |= checkAndUnlockDescendant(child);
        }
        return res;
    }

private:
    vector<int> parent;
    vector<int> lockNodeUser;
    vector<vector<int>> children;
};
