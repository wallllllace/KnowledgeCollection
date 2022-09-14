//
//  MyLinkedList.hpp
//  LeetCode
//
//  Created by wangxiaorui19 on 2022/9/1.
//

#ifndef MyLinkedList_hpp
#define MyLinkedList_hpp

#include <stdio.h>
#include <iostream>

namespace MyLinkedList {
class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }
};

class MyLinkedList {
    ListNode *head;
    ListNode *tail;
    
public:
    MyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    int get(int index) {
        if (head == nullptr) {
            return -1;
        }
        ListNode *p = head;
        int i = 0;
        while (i < index) {
            p = p->next;
            ++i;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        ListNode *node = new ListNode(val);
        if (head == nullptr) {
            head = tail = node;
            return;
        }
        node->next = head;
        head = node;
    }
    
    void addAtTail(int val) {
        ListNode *node = new ListNode(val);
        if (head == nullptr) {
            head = tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        ListNode *pre = head;
        int i = 0;
        while (pre != nullptr && i < index - 1) {
            pre = pre->next;
            ++i;
        }
        ListNode *node = new ListNode(val);
        node->next = pre->next;
        pre->next = node;
    }
    
    void deleteAtIndex(int index) {
        if (index == 0) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        ListNode *pre = head;
        int i = 0;
        while (pre->next != nullptr && i < index - 1) {
            pre = pre->next;
            ++i;
        }
        ListNode *tmp = pre->next;
        pre->next = pre->next->next;
        delete tmp;
    }
    
    void traverse(){
        ListNode *p = head;
        while (p != nullptr) {
            std::cout << p->val << ", ";
            p = p->next;
        }
        std::cout << std::endl;
    }
};
};

/*
 ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
 [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
 */



/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

#endif /* MyLinkedList_hpp */
