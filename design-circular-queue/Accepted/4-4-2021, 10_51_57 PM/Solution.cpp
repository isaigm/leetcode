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
