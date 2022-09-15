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

// 希尔排序 (时间复杂度：O(nlog2n), 空间复杂度O(1), 稳定性：非稳定)
class Solution_4 {
public:
    void shell_sort(std::vector<int>& vec) {
        int length = static_cast<int>(vec.size());
        int h = 1;
        while (h < length / 3) {
            h = 3 * h + 1;
        }
        while (h >= 1) {
            for (int i = h; i < length; i++) {
                for (int j = i; j >= h && vec[j] < vec[j - h]; j -= h) {
                    std::swap(vec[j], vec[j - h]);
                }
            }
            h = h / 3;
        }
    }
};

// 归并排序 (时间复杂度：O(nlogn), 空间复杂度O(1), 稳定性：非稳定)
class Solution_5 {
public:
    void mergeSort(std::vector<int>& vec) {
//        int len = static_cast<int>(vec.size());
        std::vector<int> res;
        precess_mergeSort(vec, res, 0, vec.size()-1);
    }
    
    void precess_mergeSort(std::vector<int>& vec, std::vector<int>& res, int start, int end) {
        if (start >= end) {
            return;
        }
        int len = end - start, mid = start + (len >> 1);
        int start1 = start, end1 = mid;
        int start2 = mid + 1, end2 = end;
        precess_mergeSort(vec, res, start1, end1);
        precess_mergeSort(vec, res, start2, end2);
        int k = start;
        while (start1 <= end1 && start2 <= end2) {
            res[k++] = vec[start1] < vec[start2] ? vec[start1++] : vec[start2++];
        }
        while (start1 <= end1) {
            res[k++] = vec[start1++];
        }
        while (start2 <= end2) {
            res[k++] = vec[start2++];
        }
        for (k = start; k <= end; k++) {
            vec[k] = res[k];
        }
        /*
         auto mid = begin + (end-begin) / 2;
         std::vector<int> lastVec = precess_mergeSort(vec, begin, mid);
         std::vector<int> nextVec = precess_mergeSort(vec, mid+1, end);
         std::vector<int> res;
         int i = 0, j = 0;
         while (i < lastVec.size() && j < nextVec.size()) {
             if (lastVec[i] < nextVec[j]) {
                 res.push_back(lastVec[i]);
                 ++i;
             } else {
                 res.push_back(nextVec[j]);
                 ++j;
             }
         }
         while (i < lastVec.size()) {
             res.push_back(lastVec[i]);
             ++i;
         }
         while (j < nextVec.size()) {
             res.push_back(nextVec[j]);
             ++j;
         }
         return res;
         */
    }
};

// 快速排序（时间复杂度：O(nlogn), 空间复杂度：O(logn), 稳定性：非稳定）
class Solution_6 {
public:
    void quick_sort(std::vector<int> &vec){
        precess_quick_sort(vec, 0, static_cast<int>(vec.size())-1);
    }
    
    void precess_quick_sort(std::vector<int> &vec, int low, int high){
        if (low >= high) {
            return;
        }
        int pos = precess_sort(vec, low, high);
        precess_quick_sort(vec, low, pos);
        precess_quick_sort(vec, pos+1, high);
    }
    
    int precess_sort(std::vector<int> &vec, int low, int high){
        int l = low, h = high;
        int pos = vec[l];
        while (l < h) {
            while (l < h && pos <= vec[h]) {
                --h;
            }
            vec[l] = vec[h];
            while (l < h && pos >= vec[l]) {
                ++l;
            }
            vec[h] = vec[l];
        }
        vec[l] = pos;
        return l;
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
    
    /*
     Solution_3 *s_3 = new Solution_3();
     std::vector<int> vec = {6,7, 5, 4, 3, 2, 1};
     s_3->insertionSort(vec);
     delete s_3;
     */
    
    /*
     Solution_5 *s_5 = new Solution_5();
     std::vector<int> vec = {6,7, 5, 4, 3, 2, 1};
     s_5->mergeSort(vec);
     delete s_5;
     */
    
    Solution_6 *s_6 = new Solution_6();
    std::vector<int> vec = {6,7, 5, 4, 3, 2, 1};
    s_6->quick_sort(vec);
    delete s_6;
    
    
    
    for (auto i : vec) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    
    
    
    
    return 0;
}
