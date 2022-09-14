//
//  MyDoubleLinkedList.hpp
//  LeetCode
//
//  Created by wangxiaorui19 on 2022/9/3.
//

#ifndef MyDoubleLinkedList_hpp
#define MyDoubleLinkedList_hpp

#include <stdio.h>
#include <iostream>

namespace MyDoubleLinkedList {
class ListNode {
public:
    int val;
    ListNode *next, *prev;
    
    ListNode(int val){
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
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
        ListNode *p = head;
        for (int i = 0; i < index; ++i) {
            p = p->next;
            if (!p) {
                return -1;
            }
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        ListNode *tmp = new ListNode(val);
        if (!head) {
            head = tail = tmp;
            return;
        }
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }
    
    void addAtTail(int val) {
        ListNode *tmp = new ListNode(val);
        if (!head) {
            head = tail = tmp;
            return;
        }
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        ListNode *p = head;
        for (int i = 0; i < index; ++i) {
            p = p->next;
            if (!p && i+1 == index) {
                addAtTail(val);
                return;
            }
        }
        ListNode *tmp = new ListNode(val);
        tmp->next = p;
        tmp->prev = p->prev;
        p->prev->next = tmp;
        p->prev = tmp;
    }
    
    void deleteAtIndex(int index) {
        ListNode *p = head;
        if (index == 0) {
            head = head->next;
            head->prev = nullptr;
            delete p;
            return;
        }
        for (int i = 0; i < index; ++i) {
            p = p->next;
        }
        if (!p->next) {
            tail = tail->prev;
            tail->next = nullptr;
            delete p;
            return;
        }
        p->next->prev = p->prev;
        p->prev->next = p->next;
        delete p;
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

#endif /* MyDoubleLinkedList_hpp */
