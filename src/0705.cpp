/**
 * Design HashSet
 * 
 * Implement MyHashSet class:
 * - void add(key) Inserts the value key into the HashSet.
 * - bool contains(key) Returns whether the value key exists in the HashSet or not.
 * - void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 */

#include "iostream"
#include "set"
using namespace std;

class MyHashSet {
private:
    set<int> s;
public:
    MyHashSet() {
    }
    
    void add(int key) {
        s.insert(key);
    }
    
    void remove(int key) {
        s.erase(key);
    }
    
    bool contains(int key) {
        return s.find(key) != s.end();
    }
};