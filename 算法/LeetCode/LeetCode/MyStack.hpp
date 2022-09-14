//
//  MyStack.hpp
//  LeetCode
//
//  Created by wangxiaorui19 on 2022/8/31.
//

#ifndef MyStack_hpp
#define MyStack_hpp

#include <stdio.h>
#include <vector>
#include <stack>
#include <utility>

/*
 template <typename T>
 class MyStack {
     std::vector<T> datas;
     
 public:
     
     void push(T t) {
         datas.push_back(t);
     }
     
     bool pop() {
         if (isEmpty()) {
             return false;
         }
         datas.pop_back();
         return true;
     }
     
     T top() {
         return datas.back();
     }
     
     bool isEmpty(){
         return datas.empty();
     }
 };
 */

/*
 最小栈
 
 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

 实现 MinStack 类:

 MinStack() 初始化堆栈对象。
 void push(int val) 将元素val推入堆栈。
 void pop() 删除堆栈顶部的元素。
 int top() 获取堆栈顶部的元素。
 int getMin() 获取堆栈中的最小元素。

 */

/*
class MinStack {
    std::vector<int> datas;
    int p_min;
    
    int findMin(int toIndex) {
        int value = INT_MAX;
        int index = 0;
        for (int i = 0; i <= toIndex; ++i) {
            if (datas[i] < value) {
                index = i;
            }
        }
        return index;
    }
    
public:
    MinStack() {
        p_min = 0;
    }
    
    void push(int val) {
        datas.push_back(val);
        if (val < top()) {
            p_min = static_cast<int>(datas.size())-1;
        }
    }
    
    void pop() {
        if (p_min == datas.size()-1) {
            p_min = findMin(static_cast<int>(datas.size())-2);
        }
        datas.pop_back();
    }
    
    int top() {
        return datas.back();
    }
    
    int getMin() {
        return datas[p_min];
    }
};
*/


// 使用辅助栈
/*
 class MinStack {
     std::stack<int> datas;
     std::stack<int> help;
     
 public:
     MinStack() {
     }
     
     void push(int val) {
         datas.push(val);
         if (help.empty()) {
             help.push(val);
             return;
         }
         int min = help.top();
         if (val < min) {
             help.push(val);
         } else {
             help.push(min);
         }
     }
     
     void pop() {
         datas.pop();
         help.pop();
     }
     
     int top() {
         return datas.top();
     }
     
     int getMin() {
         return help.top();
     }
 };
 */
// 使用元组
class MinStack {
    std::stack<std::pair<int, int>> datas;
    
public:
    MinStack() {
    }
    
    void push(int val) {
        if (datas.empty()) {
            datas.push({val, val});
            return;
        }
        auto top = datas.top();
        if (top.second < val) {
            datas.push({val, top.second});
        } else {
            datas.push({val, val});
        }
    }
    
    void pop() {
        datas.pop();
    }
    
    int top() {
        return datas.top().first;
    }
    
    int getMin() {
        return datas.top().second;
    }
};

#endif /* MyStack_hpp */
