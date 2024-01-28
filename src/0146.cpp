/**
 * LRU Cache
 * 
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 * 
 * Implement the LRUCache class:
 * 
 * LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
 * The functions get and put must each run in O(1) average time complexity.
 */

#include "iostream"
#include "map"
using namespace std;

class Node {
public:
    Node *prev;
    Node *next;
    int value;
    int key;

    Node() {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        curCnt = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp[key]) {
            put(key, mp[key]->value);
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp[key] != nullptr) {
            Node *prev = mp[key]->prev;
            Node *next = mp[key]->next;
            prev->next = next;
            next->prev = prev;
        } else {
            curCnt++;
            Node *node = new Node();
            node->key = key;
            mp[key] = node;
        }

        mp[key]->value = value;
        
        mp[key]->prev = tail->prev;
        tail->prev->next = mp[key];
        mp[key]->next = tail;
        tail->prev = mp[key];

        if (curCnt > capacity) {
            curCnt--;
            mp[head->key] = nullptr;
            head->next->next->prev = head;
            head->next = head->next->next;
        }
    }
private:
    int capacity;
    int curCnt;
    map<int, Node *> mp;
    Node *head;
    Node *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */