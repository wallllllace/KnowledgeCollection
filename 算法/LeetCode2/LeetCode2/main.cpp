//
//  main.cpp
//  LeetCode2
//
//  Created by 王晓睿 on 2022/9/13.
//

#include <iostream>
#include <vector>

// 冒泡排序 （时间复杂度：O(n2)，空间复杂度：O(1), 稳定性：稳定）
class Solution_1 {
public:
    void bubbleSort(std::vector<int>& vec){
        int size = static_cast<int>(vec.size());
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (vec[j] <= vec[j+1]) {
                    continue;
                }
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
};

// 选择排序 （时间复杂度：O(n2), 空间复杂度：不占用, 稳定性：不稳定）
class Solution_2 {
public:
    void selectionSort(std::vector<int>& vec){
        int size = static_cast<int>(vec.size());
        for (int i = 0; i < size; ++i) {
            for (int j = i+1; j < size; ++j) {
                if (vec[i] <= vec[j]) {
                    continue;
                }
                std::swap(vec[i], vec[j]);
            }
        }
    }
};

// 插入排序 (时间复杂度：O(n2), 空间复杂度O(1), 稳定性：稳定)
class Solution_3 {
public:
    void insertionSort(std::vector<int>& vec){
        int size = static_cast<int>(vec.size());
        for (int i = 1; i < size; ++i) {
            int targetIndex = i, curr = vec[i];
            while (targetIndex-1 >= 0 && vec[targetIndex] < vec[targetIndex-1]) {
                vec[targetIndex] = vec[targetIndex-1];
                vec[targetIndex-1] = curr;
                --targetIndex;
            }
            vec[targetIndex] = curr;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    /*
     Solution_1 *s_1 = new Solution_1();
     std::vector<int> vec = {7, 5, 4, 3, 2, 1};
     s_1->bubbleSort(vec);
     delete s_1;
     */
    
    /*
     Solution_2 *s_2 = new Solution_2();
     std::vector<int> vec = {7, 5, 4, 3, 2, 1};
     s_2->selectionSort(vec);
     delete s_2;
     */
    
    Solution_3 *s_3 = new Solution_3();
    std::vector<int> vec = {6,7, 5, 4, 3, 2, 1};
    s_3->insertionSort(vec);
    delete s_3;
    
    
    
    for (auto i : vec) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    
    
    
    
    return 0;
}
