class MyCircularDeque {
   
public:
    vector<int> q;
    int front, rear, len=0, capacity;
    
    MyCircularDeque(int k) {
        q = vector<int>(k);    
        front=0;
        rear=-1;
        capacity=k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(--front<0) front+=capacity;
        q[front] = value;
        len++;
        if(len==1) rear=front;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        rear = (rear+1)%capacity;
        q[rear] = value;
        len++;
        if(len==1) front=rear;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front= (front+1)%capacity;
        len--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        if(--rear<0) rear+=capacity;
        len--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return len==0;
    }
    
    bool isFull() {
        return len == capacity;
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