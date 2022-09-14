//
//  MyHashMap.hpp
//  LeetCode
//
//  Created by wangxiaorui19 on 2022/9/4.
//

#ifndef MyHashMap_hpp
#define MyHashMap_hpp

#include <stdio.h>
#include <vector>
#include <list>

class MyHashMap {
    std::vector<std::list<std::pair<int, int>>> datas;
    static const int base = 769;
    
    int hash(int key) {
        return key % base;
    }
    
public:
    MyHashMap(): datas(base) { }
    
    void put(int key, int value) {
        int n = hash(key);
        std::list<std::pair<int, int>> &l = datas[n];
        for (auto it = l.cbegin(); it != l.cend(); ++it) {
            if ((*it).first == key) {
                return ;
            }
        }
        l.push_back({key, value});
    }
    
    int get(int key) {
        int n = hash(key);
        std::list<std::pair<int, int>> &l = datas[n];
        for (auto it = l.cbegin(); it != l.cend(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int n = hash(key);
        std::list<std::pair<int, int>> &l = datas[n];
        for (auto it = l.cbegin(); it != l.cend(); ++it) {
            if ((*it).first == key) {
                l.erase(it);
                return ;
            }
        }
    }
    
    bool contains(int key) {
        int n = hash(key);
        std::list<std::pair<int, int>> &l = datas[n];
        for (auto it = l.cbegin(); it != l.cend(); ++it) {
            if ((*it).first == key) {
                return true;
            }
        }
        return false;
    }
};
#endif /* MyHashMap_hpp */
