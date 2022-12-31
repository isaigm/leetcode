// https://leetcode.com/problems/design-hashset

#include <set>
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        myset.insert(key);
    }
    
    void remove(int key) {
        myset.erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return myset.find(key) != myset.end();
    }
private:
    std::set<int> myset;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */