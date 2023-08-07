// 146. LRU 缓存

#include "def.h"

// 哈希+双向链表

// moveToHead 移动到头部
// addToHead 添加头结点
// removeDetail 移除尾结点
// removeNode 移除结点

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    map<int, DLinkedNode*> m;
    DLinkedNode *head, *tail;
    int cap, len = 0;

    LRUCache(int capacity) {
        cap = capacity;

        head = new DLinkedNode();
        tail = new DLinkedNode();

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m[key] == nullptr) {
            return -1;
        }

        DLinkedNode *p = m[key];
        
        moveToHead(p);

        return p->value;
    }

    void put(int key, int value) {
        DLinkedNode *p = m[key];
        if (p != nullptr) {
            p->value = value;
            moveToHead(p);
        } else {
            p = new DLinkedNode(key, value);
            m[key] = p;
            addToHead(p);
            len++;

            if (len > cap) {
                DLinkedNode *removed = removeTail();
                m.erase(removed->key);
                delete removed;
                len--;
            }
        }
    }

    void moveToHead(DLinkedNode *p) {
        if (p == head->next) {
            return;
        }

        removeNode(p);
        addToHead(p);
    }

    void addToHead(DLinkedNode *p) {
        // p
        p->prev = head;
        p->next = head->next;

        // head
        head->next->prev = p;
        head->next = p;
    }
    void removeNode(DLinkedNode *p) {
        // p prev next
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    DLinkedNode* removeTail() {
        DLinkedNode *p = tail->prev;
        removeNode(p);
        return p;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */