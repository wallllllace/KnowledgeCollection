//
//  MyCircularQueue.hpp
//  LeetCode
//
//  Created by wangxiaorui19 on 2022/8/30.
//

#ifndef MyCircularQueue_hpp
#define MyCircularQueue_hpp

#include <stdio.h>
#include <vector>

/*
 // 基于数组
 template <typename T>
 class MyCircularQueue {
     std::vector<T> datas;
     int capacity; // 容量（内部容器的长度）
     int head; // 指向最早插入的元素位置
     int tail; // 指向下一个可添加的位置
     
 public:
     
     /// k 实际能存储的容量，使用线性数组会有一个空间浪费，所以vector长度 = k + 1
     MyCircularQueue(int k) {
         capacity = k + 1;
         datas = std::vector<T>(capacity);
         head = 0;
         tail = 0;
     }
     
     bool enQueue(T value) {
         if (isFull()) {
             return false;
         }
         datas[tail] = value;
         tail = (tail+1)%capacity;
         return true;
     }
     
     bool deQueue() {
         if (isEmpty()) {
             return false;
         }
         head = (head+1)%capacity;
         return true;
     }
     
     T Front() {
         if (isEmpty()) {
             return -1;
         }
         return datas[head];
     }
     
     T Rear() {
         if (isEmpty()) {
             return -1;
         }
         int last = (tail-1+capacity)%capacity;
         return datas[last];
     }
     
     bool isEmpty() {
         return head == tail;
     }
     
     bool isFull() {
         return head == (tail+1)%capacity;
     }
     
 };
 */

// 基于链表实现

template <typename T>
class ListNode {
public:
    T value;
    ListNode<T> *next;
    
    ListNode(T& value) {
        this->value = value;
        this->next = nullptr;
    }
};

template <typename T>
class MyCircularQueue {
    ListNode<T> *head;
    ListNode<T> *tail;
    int capacity;
    int size;
    
public:
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        head = tail = nullptr;
    }
    
    bool enqueue(T t) {
        if (isFull()) {
            return false;
        }
        ListNode<T> *node = new ListNode<T>(t);
        if (isEmpty()) {
            head = node;
            tail = head;
        } else {
            tail->next = node;
            tail = tail->next;
        }
        ++size;
        return true;
    }
    
    bool dequeue() {
        if (isEmpty()) {
            return false;
        }
        ListNode<T> *headNode = head;
        head = head->next;
        delete headNode;
        --size;
        return true;
    }
    
    T front(){
        return head->value;
    }
    
    T rear(){
        return tail->value;
    }
    
    bool isEmpty(){
        return size == 0;
    }
    
    bool isFull(){
        return size == capacity;
    }
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


#endif /* MyCircularQueue_hpp */
