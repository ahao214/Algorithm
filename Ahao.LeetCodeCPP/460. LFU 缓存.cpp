#include<vector>
#include<unordered_map>

using namespace std;


/*
460. LFU ����

����Ϊ �����ʹ�ã�LFU�������㷨��Ʋ�ʵ�����ݽṹ��

ʵ�� LFUCache �ࣺ

LFUCache(int capacity) - �����ݽṹ������ capacity ��ʼ������
int get(int key) - ����� key �����ڻ����У����ȡ����ֵ�����򷵻� -1 ��
void put(int key, int value) - ����� key �Ѵ��ڣ�������ֵ������������ڣ�������ֵ�ԡ�������ﵽ������ capacity ʱ����Ӧ���ڲ�������֮ǰ���Ƴ������ʹ�õ���ڴ������У�������ƽ�֣���������������������ͬʹ��Ƶ�ʣ�ʱ��Ӧ��ȥ�� ������δʹ�� �ļ���
Ϊ��ȷ�����ʹ�õļ�������Ϊ�����е�ÿ����ά��һ�� ʹ�ü����� ��ʹ�ü�����С�ļ������δʹ�õļ���

��һ�����״β��뵽������ʱ������ʹ�ü�����������Ϊ 1 (���� put ����)���Ի����еļ�ִ�� get �� put ������ʹ�ü�������ֵ���������

���� get �� put ������ O(1) ��ƽ��ʱ�临�Ӷ����С�
*/

struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value) :cnt(_cnt), time(_time), key(_key), value(_value) {}

    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};
class LFUCache {
    // ����������ʱ���
    int capacity, time;
    unordered_map<int, Node> key_table;
    set<Node> S;
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        // �����ϣ����û�м� key������ -1
        if (it == key_table.end()) return -1;
        // �ӹ�ϣ���еõ��ɵĻ���
        Node cache = it->second;
        // ��ƽ���������ɾ���ɵĻ���
        S.erase(cache);
        // ���ɻ������
        cache.cnt += 1;
        cache.time = ++time;
        // ���»������·����ϣ���ƽ���������
        S.insert(cache);
        it->second = cache;
        return cache.value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // ������ﻺ����������
            if (key_table.size() == capacity) {
                // �ӹ�ϣ���ƽ���������ɾ���������ʹ�õĻ���
                key_table.erase(S.begin()->key);
                S.erase(S.begin());
            }
            // �����µĻ���
            Node cache = Node(1, ++time, key, value);
            // ���»�������ϣ���ƽ���������
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        }
        else {
            // ����� get() ��������
            Node cache = it->second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it->second = cache;
        }
    }
};
