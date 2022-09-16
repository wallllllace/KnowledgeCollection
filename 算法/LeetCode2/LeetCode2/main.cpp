//
//  main.cpp
//  LeetCode2
//
//  Created by 王晓睿 on 2022/9/13.
//

#include <iostream>
#include <vector>
#include "MaxHeap.hpp"
#include <algorithm>
#include <unordered_map>

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

/// 最小的k个数
class Solution_7 {
public:
    std::vector<int> getLeastNumbers(std::vector<int>& arr, int k) {
        /*
         MaxHeap *max_heep = new MaxHeap(arr);
         std::vector<int> vec;
         for (int i = 0; i < k; ++i) {
             vec.push_back(max_heep->peek());
             max_heep->remove();
         }
         return vec;
         */
        
        // 系统提供
        std::make_heap(arr.begin(), arr.end(), std::greater<int>()); // 小顶堆
//        std::make_heap(arr.begin(), arr.end(), std::less<int>()) // 大顶堆
        std::vector<int> vec;
        for (int i = 0; i < k; ++i) {
            std::pop_heap(arr.begin(), arr.end(), std::greater<int>());
            vec.push_back(arr.back());
            arr.pop_back();
        }
        return vec;
    }
};


/// 访问频率前k高的元素
class Solution_8 {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        if (k >= nums.size()) {
            return nums;
        }
        std::unordered_map<int, int> count_map;
        for (int i = 0; i < nums.size(); ++i) {
            int value = nums[i];
            auto it = count_map.find(value);
            if (it == count_map.cend()) {
                count_map.insert({value, 1});
            } else {
                ++(it->second);
            }
        }
        std::vector<std::pair<int, int>> vec;
        for (auto i : count_map) {
            vec.push_back(i);
        }
        auto cmp = [](std::pair<int, int> item1, std::pair<int, int> item2) {
            return item1.second < item2.second;
        };
        std::make_heap(vec.begin(), vec.end(), cmp);
        std::vector<int> res;
        for (int i = 0; i < k; ++i) {
            std::pop_heap(vec.begin(), vec.end(), cmp);
            auto back = vec.back();
            res.push_back(back.first);
            vec.pop_back();
        }
        return res;
    }
};


/// 最长自增子序列
class Solution_9 {
public:
    /*
     
    // 时间复杂度：O(n ^ 2)
    // 空间复杂度：O(n)
    // 动态规划，利用状态转移方程f(n) = max(f(i) + 1) (i < n && nums[i] < nums[n])
      
     public int lengthOfLIS(std::vector<int>& nums) {
         int n = nums.size();
        std::vector<int> dp(n, 1);
         int result = 1;
         for (int i = 1; i < n; i++) {
             for (int j = 0; j < i; j++) {
                 if (nums[j] < nums[i]) {
                     dp[i] = std::max(dp[j] + 1, dp[i]);
                 }
             }
             result = std::max(dp[i], result);
         }
         return result;
     }
     */
    int lengthOfLIS(std::vector<int>& nums) {
        int len = static_cast<int>(nums.size());
        int max_len = 1;
        std::vector<int> dp(len, 1);
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[j] + 1, dp[i]);
                }
            }
            max_len = std::max(dp[i], max_len);
        }
        return max_len;
        
        /*
         int len = static_cast<int>(nums.size());
         // std::pair<int, int> fist: 最大子序列长度， second：子序列中最大值
         int max_len = 0;
         std::vector<std::vector<std::pair<int, int>>> dp(len, std::vector<std::pair<int, int>>(len, {0, INTMAX_MIN}));
         for (int i = 0; i < len; ++i) {
             dp[i][i] = {1, nums[i]};
             max_len = 1;
         }
         for (int i = 0; i < len; ++i) {
             for (int j = i + 1; j < len; ++j) {
                 auto last = dp[i][j-1];
                 if (nums[j] > last.second) {
                     dp[i][j] = {++last.first, nums[j]};
                 } else {
                     dp[i][j] = last;
                 }
                 max_len = std::max(max_len, dp[i][j].first);
             }
         }
         return max_len;
         */
        
        /*
         int max_len = 0;
         int left = 0, right = 0;
         while (right < nums.size()-1) {
             int index = right;
             ++right;
             if (nums[index+1] <= nums[index]) {
                 left = right;
             }
             max_len = std::max(max_len, right - left + 1);
         }
         return max_len;
         */
        
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
    
    /*
     Solution_6 *s_6 = new Solution_6();
     std::vector<int> vec = {6,7, 5, 4, 3, 2, 1};
     s_6->quick_sort(vec);
     delete s_6;
     */
    
    
    /*
     MaxHeap *max_h = new MaxHeap();
     max_h->add(5);
     max_h->add(9);
     max_h->add(4);
     max_h->add(2);
     max_h->add(3);
     max_h->add(7);
     max_h->add(6);
     
     std::vector<int> vec = max_h->elements();
     
     
     for (auto i : vec) {
         std::cout << i << ", ";
     }
     std::cout << std::endl;
     
     max_h->remove();
     max_h->remove();
     max_h->remove();
     max_h->remove();
     max_h->remove();
     max_h->remove();
     max_h->remove();
     vec = max_h->elements();
     */
//
//    std::vector<int> vec = {11, 17, 15, 16, 14, 12, 13};
//    MaxHeap *max_h = new MaxHeap(vec);
//
//    for (auto i : vec) {
//        std::cout << i << ", ";
//    }
//    std::cout << std::endl;
    
    /*
     max_h->add(10);
     vec = max_h->elements();
     for (auto i : vec) {
         std::cout << i << ", ";
     }
     std::cout << std::endl;
     
     max_h->add(8);
     vec = max_h->elements();
     for (auto i : vec) {
         std::cout << i << ", ";
     }
     std::cout << std::endl;
     */
    
//    max_h->remove();
//    max_h->remove();
//    max_h->remove();
//    int ans = max_h->peek();
//
//    std::cout << "目标元素是：" << ans << std::endl;
//
//    delete max_h;
    
    
    
    /*
     std::vector<int> vec = {11, 17, 15, 16, 14, 12, 13};
     Solution_7 *s_7 = new Solution_7();
     std::vector<int> res = s_7->getLeastNumbers(vec, 3);
     for (auto i : res) {
         std::cout << i << ", ";
     }
     std::cout << std::endl;
     delete s_7;
     */
    
    /*
     std::vector<int> vec = {1, 1, 2, 3, 3, 1, 4, 2};
     Solution_8 *s_8 = new Solution_8();
     std::vector<int> res = s_8->topKFrequent(vec, 3);
     for (auto i : res) {
         std::cout << i << ", ";
     }
     std::cout << std::endl;
     */
    
    Solution_9 *s_9 = new Solution_9();
//    std::vector<int> vec = {11, 2, 3, 4, 6, 7, 10};
//    std::vector<int> vec = {10,9,2,5,3,7,101,18};
    std::vector<int> vec = {0, 1, 0, 3, 2, 3};
    int res = s_9->lengthOfLIS(vec);
    std::cout << "最长递增序列: " << res << std::endl;
    delete s_9;
    
    return 0;
}
