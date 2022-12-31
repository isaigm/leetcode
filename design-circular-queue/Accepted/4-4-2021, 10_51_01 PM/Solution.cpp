// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        max_size = k;
    }
    
    bool enQueue(int value) {
        if(!isFull())
        {
            data.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty())
        {
            data.erase(data.begin());
            return true;
        }
        return false;
    }
    
    int Front() {
        if(!isEmpty())
        {
            return data.front();
        }
        return -1;
    }
    
    int Rear() {
        if(!isEmpty())
        {
            return data.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        return data.empty();
    }
    
    bool isFull() {
        return data.size() == max_size;
    }
    private:
        std::vector<int> data;
        int max_size = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */