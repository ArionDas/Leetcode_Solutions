class MyCircularDeque {
public:

    deque<int> dq;
    int size;
    int max_capacity;
    MyCircularDeque(int k) {
        size = k;
        max_capacity = k;
    }
    
    bool insertFront(int value) {
        if(size <= 0)
            return 0;
        dq.push_front(value);
        size -= 1;
        return 1;
    }
    
    bool insertLast(int value) {
        if(size <= 0)
            return 0;
        dq.push_back(value);
        size -= 1;
        return 1;
    }
    
    bool deleteFront() {
        if(dq.empty())
            return 0;
        dq.pop_front();
        size += 1;
        return 1;
    }
    
    bool deleteLast() {
        if(dq.empty())
            return 0;
        dq.pop_back();
        size += 1;
        return 1;
    }
    
    int getFront() {
        if(dq.empty())
            return -1;
        return dq.front();
    }
    
    int getRear() {
        if(dq.empty())
            return -1;
        return dq.back();
    }
    
    bool isEmpty() {
        return (dq.size() == 0);
    }
    
    bool isFull() {
        return (dq.size() == max_capacity);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */