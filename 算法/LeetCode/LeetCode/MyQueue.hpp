//
//  MyQueue.hpp
//  LeetCode
//
//  Created by wangxiaorui19 on 2022/8/30.
//

#ifndef MyQueue_hpp
#define MyQueue_hpp

#include <stdio.h>
#include <vector>

template <typename T>
class MyQueue {
    std::vector<T> data;
    int p_start;
    
public:
    MyQueue(): p_start(0){}
    bool enqueue(T item){
        data.push_back(item);
        return true;
    } ;
    bool dequeue(){
        if (isEmpty()) {
            return false;
        }
        p_start++;
        return true;
    };
    T front(){
        return data[p_start];
    };
    bool isEmpty(){
        return p_start == data.size();
    };
    
};


#endif /* MyQueue_hpp */
