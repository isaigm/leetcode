// https://leetcode.com/problems/design-hashmap

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        big_array = new int [1000000 + 1];
        for(int i = 0; i < 1000000 + 1; i++)
        {
            big_array[i] = -1;
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        big_array[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return big_array[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        big_array[key] = -1;
    }
    private:
    int *big_array = nullptr;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */