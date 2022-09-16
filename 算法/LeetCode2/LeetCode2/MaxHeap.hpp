//
//  MaxHeap.hpp
//  LeetCode2
//
//  Created by wangxiaorui19 on 2022/9/15.
//

#ifndef MaxHeap_hpp
#define MaxHeap_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

class MaxHeap {
    std::vector<int> vec;
    
public:
    MaxHeap(){
        vec.push_back(0);
//        std::make_heap(vec.begin(), vec.end());
    }
    
    // 堆化
    MaxHeap(std::vector<int>& vec){
        vec.insert(vec.cbegin(), 0);
        int pos = static_cast<int>(vec.size()) - 1;
        while (pos > 0) {
            int index = pos;
            int parent = index / 2;
            while (parent > 0 && vec[parent] > vec[index]) {
                std::swap(vec[parent], vec[index]);
//                std::cout << "交换" << std::endl;
                index = parent;
                parent = index / 2;
            }
            int left = index * 2, right = left + 1;
            int sub_min_index = left;
            if (right < vec.size() && vec[right] < vec[left]) {
                sub_min_index = right;
            }
            while (sub_min_index < vec.size() && vec[sub_min_index] < vec[index]) {
                std::swap(vec[sub_min_index], vec[index]);
//                std::cout << "交换" << std::endl;
                index = sub_min_index;
                left = 2 * index; right = left + 1;
                sub_min_index = left;
                if (right < vec.size() && vec[right] < vec[left]) {
                    sub_min_index = right;
                }
            }
            --pos;
        }
        this->vec = vec;
    }
    
    void add(int element) {
        vec.push_back(element);
        int index = static_cast<int>(vec.size()-1);
        if (index == 1) {
            return;
        }
        int parent = index / 2;
        while (parent >= 1 && vec[parent] > element) {
            std::swap(vec[parent], vec[index]);
            index = parent;
            parent = parent / 2;
        }
    }
    
    void remove() {
        int last = static_cast<int>(vec.size()-1);
        vec[1] = vec[last];
        vec.pop_back();
        int len = static_cast<int>(vec.size());;
        int index = 1, left = 2 * index, right = left + 1;
        int sub_min_index = left;
        if (right < len && vec[right] < vec[left]) {
            sub_min_index = right;
        }
        while (sub_min_index < len && vec[sub_min_index] < vec[index]) {
            std::swap(vec[sub_min_index], vec[index]);
            index = sub_min_index;
            left = 2 * index; right = left + 1;
            sub_min_index = left;
            if (right < len && vec[right] < vec[left]) {
                sub_min_index = right;
            }
        }
        
    }
    
    int peek() {
        if (vec.size() <= 1) {
            return 0;
        }
        return vec[1];
    }
    
    int size() {
        return static_cast<int>(vec.size()-1);
    }
    
    std::vector<int> elements() {
        return this->vec;
    }
};

#endif /* MaxHeap_hpp */
