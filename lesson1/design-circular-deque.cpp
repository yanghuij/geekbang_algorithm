#include <iostream>

using namespace std;

class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        array = new int[k];
        capacity = k;
        size = 0;
        head = 0;
        tail = k - 1;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        if (head == 0) {
            head = capacity - 1;
        } else {
            head -= 1;
        }
        array[head] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        if (tail == capacity - 1) {
            tail = 0;
        } else {
            tail += 1;
        }
        array[tail] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        if (head == capacity - 1) {
            head = 0;
        } else {
            head += 1;
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        if (tail == 0) {
            tail = capacity - 1;
        } else {
            tail -= 1;
        }
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return array[head];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return array[tail];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size >= capacity;
    }

private:
    int head, tail;
    int size, capacity;
    int* array;
};

void test1() {
	int k = 3;
	bool ret;
	int v;
	
	MyCircularDeque* obj = new MyCircularDeque(k);
	ret = obj->insertLast(1);
	cout << boolalpha << ret << endl;
	ret = obj->insertLast(2);
	cout << boolalpha << ret << endl;
	ret = obj->insertFront(3);
	cout << boolalpha << ret << endl;
	ret = obj->insertFront(4);
	cout << boolalpha << ret << endl;
	v = obj->getRear();
	cout << v << endl;
	ret = obj->isFull();
	cout << boolalpha << ret << endl;
	ret = obj->deleteLast();
	cout << boolalpha << ret << endl;
	ret = obj->insertFront(4);
	cout << boolalpha << ret << endl;
	v = obj->getFront();
	cout << v << endl;
}

int main(void) {
	test1();
	
	return 0;
}