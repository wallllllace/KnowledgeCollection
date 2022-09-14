//
//  MyHashSet.hpp
//  LeetCode
//
//  Created by wangxiaorui19 on 2022/9/3.
//

#ifndef MyHashSet_hpp
#define MyHashSet_hpp

#include <stdio.h>
#include <vector>
#include <list>

/*
 class MyHashSet {
     std::vector<std::vector<int>> datas;
     
 public:
     MyHashSet() {
         datas = std::vector<std::vector<int>>(10, std::vector<int>());
     }
     
     void add(int key) {
         int index = key % 10;
         std::vector<int> &v = datas[index];
         v.push_back(key);
     }
     
     void remove(int key) {
         int index = key % 10;
         std::vector<int> &v = datas[index];
         for (int i = 0; i < v.size(); ++i) {
             if (v[i] == key) {
                 v[i] = 0;
             }
         }
     }
     
     bool contains(int key) {
         int index = key % 10;
         std::vector<int> &v = datas[index];
         for (int i = 0; i < v.size(); ++i) {
             if (v[i] == key) {
                 return true;
             }
         }
         return false;
     }
 };
 */


class MyHashSet {
    std::vector<std::list<int>> datas;
    static const int base = 769;
    
    int hash(int key) {
        return key % base;
    }
    
public:
    MyHashSet(): datas(base) { }
    
    void add(int key) {
        int n = hash(key);
        std::list<int> &l = datas[n];
        for (auto it = l.cbegin(); it != l.cend(); ++it) {
            if (*it == key) {
                return ;
            }
        }
        l.push_back(key);
    }
    
    void remove(int key) {
        int n = hash(key);
        std::list<int> &l = datas[n];
        for (auto it = l.cbegin(); it != l.cend(); ++it) {
            if (*it == key) {
                l.erase(it);
                return ;
            }
        }
    }
    
    bool contains(int key) {
        int n = hash(key);
        std::list<int> &l = datas[n];
        for (auto it = l.cbegin(); it != l.cend(); ++it) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }
};


#endif /* MyHashSet_hpp */
