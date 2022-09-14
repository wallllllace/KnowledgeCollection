//
//  main.cpp
//  LeetCode
//
//  Created by wangxiaorui19 on 2022/8/27.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include "MyQueue.hpp"
//#include "MyCircularQueue.hpp"
//#include "MyLinkedList.hpp"
#include "MyDoubleLinkedList.hpp"

/*
 给你一个整数数组 nums ，请计算数组的 中心下标 。

 数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。

 如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。

 如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。
 
 [2, 0, 0, 0, 2]
 */
class Solution_1 {
public:
    // std::vector<int> v4 = {1,2,1};
//    std::vector<int> v9 = {2, 0, -5, 1, 2};
//    std::vector<int> v10 = {2, 0, -5, 1, 2,-5};
//    std::vector<int> v7 = {2, 0, 0, 0, 2};{2,2,2,2,4}
    int pivotIndex(std::vector<int>& nums) {
        // 1. 不存在（a.元素个数为0或1 b.元素个数为2且相加不等于0）
        // 2. 中心下标位于最左侧（所有元素相加为0）
        // 3. 多个中心点（递减r）
        /*
         // 这种方式只能在有序的情况下才能用，不然有可能会出现数字突变的情况
         int size = (int)nums.size();
         if (size == 0 || size == 1) {
             return -1;
         }
         if (size == 2) {
             return nums[0] + nums[1] == 0 ? 0 : -1;
         }
         int l = 0, r = size-1;
         int sum_l = nums[l], sum_r = nums[r];
         while (l+1 < r-1) {
             if (sum_l < sum_r) {
                 sum_l += nums[++l];
             } else {
                 sum_r += nums[--r];
             }
         }
         int mid = l+1;
         if (sum_l == sum_r) {
             return mid;
         } else if(sum_r + sum_l + nums[mid] == 0) {
             return 0;
         } else {
             return -1;
         }
         */
        /*
         // 前缀和，两次遍历
         int size = (int)nums.size();
         if (size == 0) {
             return -1;
         }
         if (size == 1) {
             return 0;
         }
         std::vector<int> sum(size, nums[0]);
         for (int i = 1; i < size; ++i) {
             sum[i] = sum[i-1] + nums[i];
         }
         for (int i = 0; i < size; ++i) {
             if (sum[i] - nums[i] == sum[size-1] - sum[i]) {
                 return i;
             }
         }
         return -1;
         */
        
        // 前缀和，一次遍历
        int size = (int)nums.size();
        if (size == 0) {
            return -1;
        }
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        // sum[i-1] = total - sum[i-1] - num[i] => 2sum[i-1] = total - num[i]
        for (int i = 0 ; i < size; ++i) {
            if (2 * sum == total - nums[i]) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};

/*
 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

 请必须使用时间复杂度为 O(log n) 的算法。
 [1, 2, 3, 4] target = 3, index = 2
 [1, 2, 4, 5] target = 3, index = 2
 [1, 2, 3] target = 0, index = 0
 [1, 2, 3] target = 5, index = 3
 */
class Solution_2 {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        // 二分法
        // 1. 结束条件(与target比，大于/小于/大于等于/小于等于)
        // 2. 边界取值（l = mid/l = mid+1; r = mid/r = mid-1。判断标准是mid是否有可能是结果值，如果可能就需要包含，不可能就不包含）
        // 3. 中间值写法避免溢出（l + (r - l) / 2）/ (l + ((r - l) >> 1))
        // 本题转换为找第一个大于等于target的值
        /*
         int size = (int)nums.size();
         if (size == 0) {
             return 0;
         }
         if (nums[0] >= target) {
             return 0;
         }
         int l = 0, r = size - 1;
         while (l < r) {
             int mid = l + (r - l) / 2;
             if (nums[mid] >= target) {
                 r = mid;
             } else {
                 l = mid + 1;
             }
         }
         return nums[r] >= target ? r : size;
         */
        // 第二种写法，省去判断边界条件
        int size = (int)nums.size();
        int l = 0, r = size-1, ans = size;
        while (l <= r) {
            int mid = l + ((r-l) >> 1);
            if (nums[mid] >= target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

/*
 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 */
class Solution_3 {
public:
    // 思路：先排序，再遍历
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),[](std::vector<int>& a, std::vector<int>& b){
            return a[0] < b[0];
        });
//        for (int i = 0; i < intervals.size(); ++i) {
//            std::cout << "元素" << i << ": start - " << intervals[i][0] << ", end - " << intervals[i][1] << std::endl;
//        }
        std::vector<std::vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            auto& cur = intervals[i];
            auto& p = result.back();
            if (p[1] >= cur[1]) {
                continue;
            }
            if (p[1] < cur[0]) {
                result.push_back(cur);
            } else {
                p[1] = cur[1];
            }
        }
        return result;
    }
};


/*
 最长公共前缀
 编写一个函数来查找字符串数组中的最长公共前缀。

 如果不存在公共前缀，返回空字符串 ""。
 
 输入：strs = ["flower","flow","flight"]
 输出："fl"
 
 输入：strs = ["dog","racecar","car"]
 输出：""
 */
class Solution_4 {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        /*
         std::string common = strs[0];
         for (int i = 1; i < (int)strs.size(); ++i) {
             std::string& str = strs[i];
             int commonLen = 0;
             auto p = str.cbegin();
             auto q = common.cbegin();
             while (p != str.cend() && q != common.cend()) {
                 if (*p != *q) {
                     break;
                 }
                 ++p;
                 ++q;
                 ++commonLen;
             }
             if (commonLen < common.length()) {
                 common = common.substr(0, commonLen);
             }
         }
         return common;
         */
        
        /*
         // 此种方法写法简洁一点，每次循环取最小字符个数的字符串
         std::string common = strs[0];
         for (int i = 1; i < (int)strs.size(); ++i) {
             std::string& str = strs[i];
             int commonLen = 0;
             for (int j = 0; j < std::min(common.length(), str.length()); ++j) {
                 if (common[j] != str[j]) {
                     break;
                 }
                 ++commonLen;
             }
             common = common.substr(0, std::min((int)common.length(), commonLen));
             
         }
         return common;
         */
//        std::vector<std::string> v1 = {"flower","flow","flight"}
        // 使用二分法
        std::sort(strs.begin(), strs.end(), [](std::string& s1, std::string& s2){
            return s1.size() < s2.size();
        });
    
        std::string& min_ele_str = strs[0];
        int l = 1, r = (int)min_ele_str.size();
        int max_len = 0;
        while (l <= r) {
            int mid = l + ((r-l) >> 1);
            if (isCommonPrefix(strs, min_ele_str, mid)) {
                max_len = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return min_ele_str.substr(0, max_len);
        
    }
    
    bool isCommonPrefix(std::vector<std::string>& strs, std::string& min_ele_str, int len) {
        for (int i = 0; i < (int)strs.size(); ++i) {
            std::string subStr = strs[i].substr(0, len);
            std::string preStr = min_ele_str.substr(0, len);
            if (subStr != preStr) {
                return false;
            }
        }
        return true;
    }
};

/*
 给你一个字符串 s，找到 s 中最长的回文子串。
 
 输入：s = "babad"
 输出："bab"
 
 输入：s = "cbbd"
 输出："bb"
 
 */
class Solution_5 {
public:
    std::string longestPalindrome(std::string s) {
        /*
         std::string maxStr = "";
         for (int i = 0; i < (int)s.length(); ++i) {
             for (int len = 1; len <= (int)s.length() - i; ++len) {
                 std::string subStr = s.substr(i, len);
 //                std::cout << "subStr: " << subStr << std::endl;
                 if (isPalindrome(subStr) && maxStr.length() < len) {
                     maxStr = subStr;
                 }
             }
         }
         return maxStr;
         */
        // 动态规划
        int len = (int)s.length();
        std::vector<int> inner(len, 0);
        std::vector<std::vector<int>> dp(s.length(), inner);
        std::string max_str = s.substr(0,1);
        for (int i = 0; i < len; ++i) {
            dp[i][i] = 1;
            std::cout << "i: " << i << ",j: " << i << std::endl;
        }
        // 枚举子串长度
        for (int L = 2; L <= len; ++L) {
            // 枚举左边界
            for (int l = 0; l < len; ++l) {
                int r = L - 1 + l;
                if (r > len - 1) {
                    break;
                }
                if (s[l] != s[r]) {
                    dp[l][r] = 0;
                } else {
                    if (r-l < 3) {
                        dp[l][r] = 1;
                    } else {
                        dp[l][r] = dp[l+1][r-1];
                    }
                }
                if (dp[l][r] == 1 && L > max_str.length()) {
                    max_str = s.substr(l,L);
                }
            }
        }
        
        /*
         for (int i = 0; i < len && i < len-1; ++i) {
 //            std::cout << s.substr(i,1) << std::endl;
             std::cout << "i: " << i << ",j: " << i+1 << std::endl;
             if (s[i] == s[i+1]) {
                 dp[i][i+1] = 1;
                 max_str = max_str.length() < 2 ? s.substr(i, 1) : max_str;
             }
         }
         for (int i = 1; i < len-1; ++i) {
             for (int step = 1; step <= std::min(i, len-1-i); ++step) {
                 int l = i-step, r = i+step;
                 if (dp[l+1][r-1] == 1 && s[l] == s[r]) {
                     dp[l][r] = 1;
                 }
                 if (dp[l+1][r] == 1 && s[l] == s[r+1]) {
                     dp[l][r+1] = 1;
                 }
                 std::cout << "i: " << l << ",j: " << r << std::endl;
 //                std::cout << s.substr(l,r-l+1) << std::endl;
                 max_str = max_str.length() < r-l+1 ? s.substr(i, r-l+1) : max_str;
             }
         }
         */
        
        return max_str;
    }
    
    bool isPalindrome(std::string s) {
        int len = (int)s.size();
        int mid = len / 2;
        if (len % 2 == 0) {
            s.insert(s.begin() + mid, 'a');
        }
        int l = mid - 1, r = mid + 1;
        while (l >= 0) {
            if (s[l] != s[r]) {
                return false;
            }
            --l;
            ++r;
        }
        return true;
    }
};

/*
 给你一个字符串 s ，请你反转字符串中 单词 的顺序。

 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

 */
class Solution_6 {
public:
    std::string reverseWords(std::string s) {
        
        return "";
    }
};

/*
 实现 strStr() 函数。

 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

 说明：

 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。
 
 示例 1：

 输入：haystack = "hello", needle = "ll"
 输出：2
 示例 2：

 输入：haystack = "aaaaa", needle = "bba"
 输出：-1

 */
class Solution_7 {
public:
    int strStr(std::string haystack, std::string needle) {
        
        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            bool same = false;
            for (int j = 0; j < needle.length(); ++j) {
                if (haystack[i+j] != needle[j]) {
                    same = false;
                    break;
                }
                same = true;
            }
            if (same) {
                return i;
            }
        }
        return 0;
    }
};

/*
 反转字符串
 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

 */
class Solution_8 {
public:
    void reverseString(std::vector<char>& s) {
        int l = 0, r = (int)s.size()-1;
        while (l < r) {
            auto tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            ++l;
            --r;
        }
    }
};

/*
 给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

 以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。

 你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

 你所设计的解决方案必须只使用常量级的额外空间。

 示例 1：

 输入：numbers = [2,7,11,15], target = 9
 输出：[1,2]
 解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
 示例 2：

 输入：numbers = [2,3,4], target = 6
 输出：[1,3]
 解释：2 与 4 之和等于目标数 6 。因此 index1 = 1, index2 = 3 。返回 [1, 3] 。
 示例 3：

 输入：numbers = [-1,0], target = -1
 输出：[1,2]
 解释：-1 与 0 之和等于目标数 -1 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。

 */
class Solution_9 {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        /*
         // 哈希表 O(n)
         std::unordered_map<int, int> map;
         for (int i = 0; i < (int)numbers.size(); ++i) {
             int a = target-numbers[i];
             if (map.find(a) == map.end()) {
                 map.insert({numbers[i], i});
             } else {
                 return {map[a] + 1, i + 1};
             }
         }
         return {};
         */
        
        // 双指针
        int l = 0, r = (int)numbers.size()-1;
        while (l<r) {
            int res = numbers[l] + numbers[r];
            if (res < target) {
                ++l;
            } else if(res > target) {
                --r;
            } else {
                return {l+1,r+1};
            }
        }
        return {};
        
    }
};

/*
 原地移除数组中元素
 
 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

 */
class Solution_10 {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int slow = 0, quick = 0;
        while (quick < nums.size()) {
            int q_item = nums[quick];
            if (q_item != val) {
                nums[slow] = q_item;
                ++slow;
            }
            ++quick;
        }
        return slow;
    }
};
/*
 给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。

 示例 1：
 输入：nums = [1,1,0,1,1,1]
 输出：3
 解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
 示例 2:

 输入：nums = [1,0,1,1,0,1]
 输出：2

 */
class Solution_11 {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        /*
         int maxLen = 0, curLen = 0;
         int slow = 0, quick = 0;
         while (quick < nums.size()) {
             int q_item = nums[quick];
             if (q_item == 1) {
                 ++curLen;
             } else {
                 maxLen = std::max(maxLen, curLen);
                 curLen = 0;
                 ++slow;
             }
             ++quick;
         }
         return std::max(maxLen, curLen);
         */
        int maxLen = 0, curLen = 0;
        int slow = 0;
        for (int quick = 0; quick < nums.size(); ++quick) {
            int q_item = nums[quick];
            if (q_item == 1) {
                ++curLen;
            } else {
                maxLen = std::max(maxLen, curLen);
                curLen = 0;
                ++slow;
            }
        }
        return std::max(maxLen, curLen);
    }
};

/*
 长度最小子数组
 
 给定一个含有 n 个正整数的数组和一个正整数 target 。

 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 示例 1：

 输入：target = 7, nums = [2,3,1,2,4,3]
 输出：2
 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 示例 2：

 输入：target = 4, nums = [1,4,4]
 输出：1
 示例 3：

 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 输出：0

 */
class Solution_12 {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        // 滑动窗口
        /*
         if (nums.size() == 1) {
             return nums[0] >= target ? 1 : 0;
         }
         if (nums[0] >= target) {
             return 1;
         }
         int l = 0, r = 1;
         int minLen = (int)nums.size();
         int total = nums[l] + nums[r];
         while (l < nums.size() && l <= r) {
             if (total >= target) {
                 minLen = std::min(minLen, r-l+1);
                 total -= nums[l];
                 ++l;
             } else {
                 ++r;
                 if (r == nums.size()) {
                     break;
                 }
                 total += nums[r];
             }
         }
         return l == 0 ? 0 : minLen;
         */
        
        // 前缀和 + 二分
        
        return 0;
    }
};

/*
 完全平方数
 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

  
 示例 1：

 输入：n = 12
 输出：3
 解释：12 = 4 + 4 + 4
 示例 2：

 输入：n = 13
 输出：2
 解释：13 = 4 + 9
 */
class Solution_13 {
public:
    int numSquares(int n) {
        return 0;
    }
};

/*
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

 有效字符串需满足：

 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 每个右括号都有一个对应的相同类型的左括号。

 */
class Solution_14 {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (auto& c : s) {
            if (stack.empty()) {
                stack.push(c);
                continue;
            }
            if (isMatch(stack.top(), c)) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
    
    bool isMatch(char& c1, char& c2) {
        return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
    }
};

/*
 每日温度
 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

 示例 1:

 输入: temperatures = [73,74,75,71,69,72,76,73]
 输出: [1,1,4,2,1,1,0,0]
 示例 2:

 输入: temperatures = [30,40,50,60]
 输出: [1,1,1,0]
 示例 3:

 输入: temperatures = [30,60,90]
 输出: [1,1,0]

 */

class Solution_15 {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = static_cast<int>(temperatures.size());
        std::vector<int> ans(n);
        std::stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};

/*
 逆波兰式
 
 示例 1：

 输入：tokens = ["2","1","+","3","*"]
 输出：9
 解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
 示例 2：

 输入：tokens = ["4","13","5","/","+"]
 输出：6
 解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6

 */
class Solution_16 {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<std::string> s;
        for (auto &c : tokens) {
            if (isOperator(c)) {
                std::string b = s.top();
                s.pop();
                std::string a = s.top();
                s.pop();
                
                int r = operate(std::stoi(a), std::stoi(b), c);
                s.push(std::to_string(r));
                continue;
            }
            s.push(c);
        }
        return std::stoi(s.top());
    }
    
    bool isOperator(std::string& c) {
        return c == "+" || c == "-" || c == "*" || c == "/";
    }
    
    int operate(int a, int b, std::string& c) {
        if (c == "+") {
            return a + b;
        }
        if (c == "-") {
            return a - b;
        }
        if (c == "*") {
            return a * b;
        }
        if (c == "/") {
            return a / b;
        }
        throw "operator is invalid";
    }
};

/*
 判断链表中是否有环
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution_17 {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode *slow = head;
        ListNode *quick = head->next;
        while (slow != quick) {
            if (quick == nullptr || quick->next == nullptr) {
                return false;
            }
            slow = slow->next;
            quick = quick->next->next;
        }
        return true;
    }
};
/*
 返回链表开始入环的节点
 */
class Solution_18 {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *quick = head->next;
        while (slow != quick) {
            if (quick == nullptr || quick->next == nullptr) {
                return nullptr;
            }
            slow = slow->next;
            quick = quick->next->next;
        }
        ListNode *p = head;
        while (p != slow) {
            p = p->next;
            slow = slow->next;
        }
        return p;
    }
};
/*
 class Solution {
 public:
     ListNode *detectCycle(ListNode *head) {
         ListNode *slow = head, *fast = head;
         while (fast != nullptr) {
             slow = slow->next;
             if (fast->next == nullptr) {
                 return nullptr;
             }
             fast = fast->next->next;
             if (fast == slow) {
                 ListNode *ptr = head;
                 while (ptr != slow) {
                     ptr = ptr->next;
                     slow = slow->next;
                 }
                 return ptr;
             }
         }
         return nullptr;
     }
 };
 */

/*
 class Solution {
 public:
     bool hasCycle(ListNode *head) {
         if (head == nullptr || head->next == nullptr) {
             return false;
         }
         ListNode *slow = head;
         ListNode *quick = head->next;
         while (slow != quick) {
             if (quick == nullptr || quick->next == nullptr) {
                 return false;
             }
             slow = slow->next;
             quick = quick->next->next;
         }
         return false;
     }
 };
 */

/*
 class Solution {
 public:
     bool hasCycle(ListNode* head) {
         if (head == nullptr || head->next == nullptr) {
             return false;
         }
         ListNode* slow = head;
         ListNode* fast = head->next;
         while (slow != fast) {
             if (fast == nullptr || fast->next == nullptr) {
                 return false;
             }
             slow = slow->next;
             fast = fast->next->next;
         }
         return true;
     }
 };
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 class Solution {
 public:
     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if (headA == nullptr || headB == nullptr) {
             return nullptr;
         }
         ListNode *pA = headA, *pB = headB;
         while (pA != pB) {
             pA = pA == nullptr ? headB : pA->next;
             pB = pB == nullptr ? headA : pB->next;
         }
         return pA;
     }
 };
 */
class Solution_19 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *p_a = headA;
        ListNode *p_b = headB;
        if (p_b != p_a) {
            p_a = p_a == nullptr ? headB : p_a->next;
            p_b = p_b == nullptr ? headA : p_b->next;
        }
        return p_a;
    }
};

/*
 删除链表倒数第n个节点
 */
class Solution_20 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 快慢指针解法
        /*
         ListNode *l0 = new ListNode(0);
         l0->next = head;
         ListNode *slow = l0;
         ListNode *fast = l0;
         for (int i = 0; i < n; ++i) {
             fast = fast->next;
         }
         while (fast->next) {
             slow = slow->next;
             fast = fast->next;
         }
         ListNode *tmp = slow->next;
         slow->next = slow->next->next;
         delete tmp;
         return l0->next;
         */
        
        // 栈
        ListNode *l0 = new ListNode(0);
        l0->next = head;
        ListNode *p = l0;
        std::stack<ListNode *> s;
        while (p) {
            s.push(p);
            p = p->next;
        }
        ListNode *curr = p;
        for (int i = 0; i < n; ++i) {
            curr = s.top();
            s.pop();
        }
        ListNode *tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
        return l0->next;
    }
};
/*
 翻转单链表
 */
class Solution_21 {
public:
    ListNode* reverseList(ListNode* head) {
        /*
         // 迭代的方式
         if (head == nullptr) {
             return nullptr;
         }
         ListNode *p = head;
         while (p->next) {
             ListNode *tmp = p->next;
             p->next = p->next->next;
             tmp->next = head;
             head = tmp;
         }
         return head;
         */
        // 递归的方式
        
        if (!head || !head->next) {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
        
        /*
         if (!head || !head->next) {
            return head;
         }
         ListNode* newHead = reverseList(head->next);
         head->next->next = head;
         head->next = nullptr;
         return newHead;
         */
    }
};

/*
 移除链表元素
 */
class Solution_22 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        /*
         // 迭代
         ListNode *l0 = new ListNode(0);
         l0->next = head;
         ListNode *p = l0;
         while (p->next) {
             if (p->next->val != val) {
                 p = p->next;
                 continue;
             }
             ListNode *tmp = p->next;
             p->next = p->next->next;
             delete tmp;
         }
         return l0->next;
         */
        
        // 递归
        if (!head) {
            return nullptr;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};

/*
 奇偶链表
 */
class Solution_23 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        ListNode *evenList = fast;
        while (fast && fast->next) {
            slow->next = fast->next;
            slow = slow->next;
            fast->next = slow->next;
            fast = fast->next;
        }
        slow->next = evenList;
        return head;
    }
};

/*
 判断回文链表
 */
class Solution_24 {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return false;
        }
        if (!head->next) {
            return true;
        }
        ListNode *slow = head, *fast = head;
        std::stack<ListNode *> s;
        while (fast->next && fast->next->next) {
            s.push(slow);
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next) { // 偶数长度
            s.push(slow);
        }
        fast = slow->next;
        while (!s.empty() && fast) {
            ListNode *tmp = s.top();
            if (tmp->val != fast->val) {
                return false;
            }
            s.pop();
            fast = fast->next;
        }
        if (!s.empty() || fast) {
            return false;
        }
        return true;
    }
};

/*
 合并链表
 
 输入：l1 = [1,2,4], l2 = [1,3,4]
 输出：[1,1,2,3,4,4]
 示例 2：

 输入：l1 = [], l2 = []
 输出：[]
 示例 3：

 输入：l1 = [], l2 = [0]
 输出：[0]

 */
class Solution_25 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *l0 = new ListNode(0);
        l0->next = list1;
        ListNode *p1 = l0, *p2 = list2;
        while (p1->next && p2) {
            if (p2->val < p1->next->val) {
                ListNode *tmp = p2->next;
                p2->next = p1->next;
                p1->next = p2;
                p2 = tmp;
            }
            p1 = p1->next;
        }
        if (p2) {
            p1->next = p2;
        }
        return l0->next;
    }
};
/*
 两数相加
 */
class Solution_26 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(0), *p = l3;
        int o = 0;
        while (l1 || l2) {
            int res = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + o;
            p->next = new ListNode(res % 10);
            p = p->next;
            o = res / 10;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        if (o == 1) {
            p->next = new ListNode(1);
        }
        return l3->next;
    }
};

/*
 旋转链表
 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 */
class Solution_27 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }
        int len = 0;
        ListNode *p = head;
        while (p->next) {
            p = p->next;
            ++len;
        }
        ++len;
        int step = len - k % len -1;
        ListNode *q = head;
        for (int i = 0; i < step; ++i) {
            q = q->next;
        }
        if (!q->next) {
            return head;
        }
        ListNode *newHead = q->next;
        p->next = head;
        q->next = nullptr;
        return newHead;
    }
};

/*

存在重复元素
 */
class Solution_28 {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if(set.find(num) != set.cend()) {
                return true;
            } else {
                set.insert(num);
            }
        }
        return false;
    }
};

/*
 只出现一次的数字
 */
class Solution_29 {
public:
    int singleNumber(std::vector<int>& nums) {
        /*
         std::unordered_set<int> set;
         for (auto i : nums) {
             auto it = set.find(i);
             if (it != set.cend()) {
                 set.erase(it);
             } else {
                 set.insert(i);
             }
         }
         return *set.cbegin();
         */
        // 异或
        int res = 0;
        for (auto i : nums) {
            res = res ^ i;
        }
        return res;
    }
};

/*
 字符串中第一个唯一字符
 */
class Solution_30 {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> hashMap;
        for (auto &c : s) {
            auto it = hashMap.find(c);
            if (it != hashMap.cend()) {
                ++(it->second);
            } else {
                hashMap.insert({c, 1});
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            auto c = s[i];
            if (hashMap[c] == 1) {
                return i;
            }
        }
        return -1;
    }
};

/*
 无重复字符的最长子串长度
 
 示例 1:

 输入: s = "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 示例 2:

 输入: s = "bbbbb"
 输出: 1
 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 示例 3:

 输入: s = "pwwkew"
 输出: 3
 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 */
class Solution_31 {
public:
    // "abcabcbb"
    // "bbba"
    // "abba"
    // "aabaab!bb"
    int lengthOfLongestSubstring(std::string s) {
        int maxLen = 0;
        int l = 0;
        std::unordered_map<char, int> hashMap;
        for (int r = 0; r < s.size(); ++r) {
            auto& c = s[r];
            auto it = hashMap.find(c);
            if (it == hashMap.cend()) {
                hashMap.insert({c, r});
            } else {
                int index = it->second;
                if (index >= l) {
                    l = index + 1;
                }
                it->second = r;
            }
            maxLen = std::max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
/*
 class Solution {
 public:
     int lengthOfLongestSubstring(string s) {
         // 哈希集合，记录每个字符是否出现过
         unordered_set<char> occ;
         int n = s.size();
         // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
         int rk = -1, ans = 0;
         // 枚举左指针的位置，初始值隐性地表示为 -1
         for (int i = 0; i < n; ++i) {
             if (i != 0) {
                 // 左指针向右移动一格，移除一个字符
                 occ.erase(s[i - 1]);
             }
             while (rk + 1 < n && !occ.count(s[rk + 1])) {
                 // 不断地移动右指针
                 occ.insert(s[rk + 1]);
                 ++rk;
             }
             // 第 i 到 rk 个字符是一个极长的无重复字符子串
             ans = max(ans, rk - i + 1);
         }
         return ans;
     }
 };
 */
/*
 前k高频元素
 */
class Solution_32 {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashMap.find(nums[i]);
            if (it == hashMap.cend()) {
                hashMap.insert({nums[i], 1});
            } else {
                ++(it->second);
            }
        }
        std::vector<std::pair<int, int>> vec;
        for (auto& item : hashMap) {
            vec.push_back(item);
        }
        std::sort(vec.begin(), vec.end(), [](std::pair<int, int> &item1, std::pair<int, int> &item2){
            return  item1.second > item2.second;
        });
        std::vector<std::pair<int, int>> res = std::vector<std::pair<int, int>>(vec.cbegin(), vec.cbegin()+k);
        std::vector<int> result;
        for (auto& item : res) {
            result.push_back(item.first);
        }
        return result;
    }
};


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 前序遍历
 */
class Solution_33 {
public:
    
    std::vector<int> preorderTraversal(TreeNode* root) {
        /*
         if (!root) {
             return {};
         }
         std::vector<int> vec;
         std::stack<TreeNode *> stack;
         std::unordered_set<TreeNode *> set;
         vec.push_back(root->val);
         stack.push(root);
         set.insert(root);
         while (!stack.empty()) {
             root = stack.top();
             TreeNode *tmpNode;
             if (root->left && set.find(root->left) == set.cend()) {
                 tmpNode = root->left;
             } else if (root->right && set.find(root->right) == set.cend()) {
                 tmpNode = root->right;
             } else {
                 stack.pop();
                 continue;
             }
             vec.push_back(tmpNode->val);
             stack.push(tmpNode);
             set.insert(tmpNode);
         }
         return vec;
         */
        
        
        
        
        /*
         // 层序遍历
         std::vector<int> vec;
         std::queue<TreeNode *> queue;
         queue.push(root);
         while (!queue.empty()) {
             auto frontItem = queue.front();
             vec.push_back(frontItem->val);
             queue.pop();
             if (frontItem->left) {
                 queue.push(frontItem->left);
             }
             if (frontItem->right) {
                 queue.push(frontItem->right);
             }
         }
         return vec;
         */
        
        /*
         // 迭代
         if (!root) {
             return {};
         }
         std::vector<int> vec;
         std::stack<TreeNode *> stack;
         stack.push(root);
         while (!stack.empty()) {
             auto topItem = stack.top();
             vec.push_back(topItem->val);
             stack.pop();
             if (topItem->right) {
                 stack.push(topItem->right);
             }
             if (topItem->left) {
                 stack.push(topItem->left);
             }
         }
         return vec;
         */
        
        /*
         // 递归一
         if (!root) {
             return {};
         }
         if (!root->left && !root->right) {
             return {root->val};
         }
         std::vector<int> vec;
         vec.push_back(root->val);
         if (root->left) {
             auto l_vec = preorderTraversal(root->left);
             vec.insert(vec.end(), l_vec.cbegin(), l_vec.cend());
 //            for (auto i : l_vec) {
 //                vec.push_back(i);
 //            }
         }
         if (root->right) {
             auto r_vec = preorderTraversal(root->right);
             vec.insert(vec.end(), r_vec.cbegin(), r_vec.cend());
 //            for (auto i : r_vec) {
 //                vec.push_back(i);
 //            }
         }
         return vec;
         */

         // 递归二
        std::vector<int> res;
         if (!root) {
             return res;
         }
         preorderPrecess(root, res);
         return res;
    }
    
    void preorderPrecess(TreeNode* root, std::vector<int>& vec) {
        if (!root) {
            return;
        }
        vec.push_back(root->val);
        preorderPrecess(root->left, vec);
        preorderPrecess(root->right, vec);
    }
    
};

/*
 中序遍历
 */
class Solution_34 {
public:
    
    /*
     // 迭代
     // 使用栈和set标记是否访问
     std::vector<int> inorderTraversal(TreeNode* root) {
         std::vector<int> vec;
         if (!root) {
             return vec;
         }
         std::stack<TreeNode*> stack;
         std::unordered_set<TreeNode*>visited_set;
         stack.push(root);
         while (!stack.empty()) {
             root = stack.top();
             if (root->left && visited_set.find(root->left) == visited_set.cend()) {
                 root = root->left;
                 stack.push(root);
                 continue;
             }
             vec.push_back(root->val);
             visited_set.insert(root);
             stack.pop();
             if (root->right) {
                 root = root->right;
                 stack.push(root);
             }
         }
         return vec;
     }
     */
    
    
    /*
     class Solution {
     public:
         vector<int> inorderTraversal(TreeNode* root) {
             vector<int> res;
             stack<TreeNode*> stk;
             while (root != nullptr || !stk.empty()) {
                 while (root != nullptr) {
                     stk.push(root);
                     root = root->left;
                 }
                 root = stk.top();
                 stk.pop();
                 res.push_back(root->val);
                 root = root->right;
             }
             return res;
         }
     };
     */
    
    /*
     // 递归
     std::vector<int> inorderTraversal(TreeNode* root) {
         if (!root) {
             return {};
         }
         std::vector<int> res;
         inorderPrecess(root, res);
         return res;
     }
     
     void inorderPrecess(TreeNode* root, std::vector<int> &vec) {
         if (!root) {
             return;
         }
         inorderPrecess(root->left, vec);
         vec.push_back(root->val);
         inorderPrecess(root->right, vec);
     }
     */
    
};

/*
 后序遍历
 */
class Solution_35 {
public:
    
    // 迭代
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        if (!root) {
            return vec;
        }
        std::stack<TreeNode*> stack;
        std::unordered_set<TreeNode*> visited_set; // 记录是否访问过
        stack.push(root);
        while (!stack.empty()) {
            root = stack.top();
            if (root->left && visited_set.find(root->left) == visited_set.cend()) { // 如果有左节点并且没有访问过
                root = root->left;
                stack.push(root);
                continue;
            }
            if (root->right && visited_set.find(root->right) == visited_set.cend()) { // 如果有右节点并且没有访问过
                root = root->right;
                stack.push(root);
                continue;
            }
            vec.push_back(root->val);
            visited_set.insert(root); // 标记访问过
            stack.pop();
        }
        return vec;
    }
    
    
    /*
     // 迭代
     std::vector<int> postorderTraversal(TreeNode* root) {
         std::stack<TreeNode *> stack;
         std::vector<int> vec;
         while (root || !stack.empty()) {
             while (root) {
                 stack.push(root);
                 root = root->left;
             }
             root = stack.top();
             stack.pop();
             root = stack.top();
             while (root) {
                 stack.push(root);
                 root = root->right;
             }
             root = stack.top();
             vec.push_back(root->val);
             stack.pop();
         }
         return vec;
     }
     
     */
    
    
    /*
     // 递归
     std::vector<int> postorderTraversal(TreeNode* root) {
         if (!root) {
             return {};
         }
         std::vector<int> res;
         postorderProcess(root, res);
         return res;
     }
     void postorderProcess(TreeNode* root, std::vector<int> &vec) {
         if (!root) {
             return;
         }
         postorderProcess(root->left, vec);
         postorderProcess(root->right, vec);
         vec.push_back(root->val);
     }
     */
    
};

/*
 层序遍历
 */
class Solution_36 {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        std::queue<TreeNode *> queue;
        queue.push(root);
        std::vector<std::vector<int>> res;
        while (!queue.empty()) {
            std::vector<int> vec;
            int size = static_cast<int>(queue.size());
            for (int i = size; i > 0; --i) {
                auto frontItem = queue.front();
                vec.push_back(frontItem->val);
                queue.pop();
                if (frontItem->left) {
                    queue.push(frontItem->left);
                }
                if (frontItem->right) {
                    queue.push(frontItem->right);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};

/*
 二叉树的最大深度
 */
class Solution_37 {
public:
    /*
     // 递归（自底向上）
     int maxDepth(TreeNode* root) {
         if (!root) {
             return 0;
         }
         if (!root->left && !root->right) {
             return 1;
         }
         return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
     }
     */
    
    /*
     // 迭代 层序遍历（自上而下）
     int maxDepth(TreeNode* root) {
         if (!root) {
             return 0;
         }
         std::queue<TreeNode*> queue;
         queue.push(root);
         int max_deep = 0;
         while (!queue.empty()) {
             int size = static_cast<int>(queue.size());
             for (int i = 0; i < size; ++i) {
                 TreeNode *front = queue.front();
                 if (front->left) {
                     queue.push(front->left);
                 }
                 if (front->right) {
                     queue.push(front->right);
                 }
                 queue.pop();
             }
             ++max_deep;
         }
         return max_deep;
     }
     */
    
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int max_deep = 1;
        std::stack<std::pair<TreeNode *, int>> stack;
        stack.push({root, 1});
        std::unordered_set<TreeNode *> visited_set;
        while (!stack.empty()) {
            auto top = stack.top();
            max_deep = std::max(max_deep, top.second);
            if (top.first->left && visited_set.find(top.first->left) == visited_set.cend()) {
                stack.push({top.first->left, ++top.second});
                visited_set.insert(top.first->left);
                continue;
            }
            if (top.first->right && visited_set.find(top.first->right) == visited_set.cend()) {
                stack.push({top.first->right, ++top.second});
                visited_set.insert(top.first->right);
                continue;
            }
            stack.pop();
        }
        return max_deep;
    }
    
};

// 对称二叉树
class Solution_38 {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return false;
        }
        reverse(root->left);
        return isEqual(root->left, root->right);
    }
    
    void reverse(TreeNode* root) {
        if (!root) {
            return;
        }
        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        reverse(root->left);
        reverse(root->right);
    }
    
    bool isEqual(TreeNode* left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }
        if (left && right && left->val == right->val) {
            return isEqual(left->left, right->left) && isEqual(left->right, right->right);
        }
        return false;
    }
};

// 路径总和
class Solution_39 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 递归
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return root->val == targetSum;
        }
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
        /*
         if (!root) {
             return false;
         }
         std::stack<std::pair<TreeNode *, int>> stack;
         stack.push({root, root->val});
         std::unordered_set<TreeNode *> visited_set;
         while (!stack.empty()) {
             auto top = stack.top();
             if (top.first->left && visited_set.find(top.first->left) == visited_set.cend()) {
                 stack.push({top.first->left, top.second + top.first->left->val});
                 continue;
             }
             if (top.first->right && visited_set.find(top.first->right) == visited_set.cend()) {
                 stack.push({top.first->right, top.second + top.first->right->val});
                 continue;
             }
             if (!top.first->left && !top.first->right && top.second == targetSum) {
                 return true;
             }
             visited_set.insert(top.first);
             stack.pop();
         }
         return false;
         */
        // 迭代
        
    }
};

// 从中序和后序遍历序列构造二叉树
/*
 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]

 */
class Solution_40 {
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        return nullptr;
    }
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution_41 {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        std::queue<Node *> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = static_cast<int>(queue.size());
            Node *head = new Node(0), *p = head;
            for (int i = 0; i < size; ++i) {
                Node *front = queue.front();
                queue.pop();
                p->next = front;
                p = p->next;
                if (front->left) {
                    queue.push(front->left);
                }
                if (front->right) {
                    queue.push(front->right);
                }
            }
            delete head;
        }
        return root;
    }
};

// 二叉树最近公共祖先
class Solution_42 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::stack<TreeNode*> p_stack;
        std::stack<TreeNode*> q_stack;
        
        traversal(root, p, p_stack);
        traversal(root, q, q_stack);
        
        std::unordered_set<TreeNode*> p_set;
        while (!p_stack.empty()) {
            p_set.insert(p_stack.top());
            p_stack.pop();
        }
        
        while (!q_stack.empty()) {
            if (p_set.find(q_stack.top()) != p_set.cend()) {
                return q_stack.top();
            }
            q_stack.pop();
        }
        return nullptr;
    }
    
    void traversal(TreeNode* root, TreeNode* target,std::stack<TreeNode*>& stack) {
        if (!root) {
            return;
        }
        stack.push(root);
        if (root == target) {
            return;
        }
        std::unordered_set<TreeNode*> visited_set;
        visited_set.insert(root);
        while (root) {
            if (root->left && visited_set.find(root->left) == visited_set.cend()) {
                root = root->left;
                stack.push(root);
                if (root == target) {
                    return;
                }
                visited_set.insert(root);
            }
            else if (root->right && visited_set.find(root->right) == visited_set.cend()) {
                root = root->right;
                stack.push(root);
                if (root == target) {
                    return;
                }
                visited_set.insert(root);
            }
            else {
                stack.pop();
                root = stack.top();
            }
        }
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    /*
     Solution_1 *s_1 = new Solution_1();
     
     std::vector<int> v1;
     std::vector<int> v2 = {1};
     std::vector<int> v3 = {1,2};
     std::vector<int> v4 = {1,2,1};
     std::vector<int> v5 = {1,2,3};
     std::vector<int> v6 = {1,2,3,-2};
     std::vector<int> v7 = {2, 0, 0, 0, 2};
     std::vector<int> v8 = {2, -2};
     std::vector<int> v9 = {2, 0, -5, 1, 2};
     std::vector<int> v10 = {2, 0, -5, 1, 2,-5};
     
     int r1 = s_1->pivotIndex(v1);
     int r2 = s_1->pivotIndex(v2);
     int r3 = s_1->pivotIndex(v3);
     int r4 = s_1->pivotIndex(v4);
     int r5 = s_1->pivotIndex(v5);
     int r6 = s_1->pivotIndex(v6);
     int r7 = s_1->pivotIndex(v7);
     int r8 = s_1->pivotIndex(v8);
     int r9 = s_1->pivotIndex(v9);
     int r10 = s_1->pivotIndex(v10);
     
     std::cout << "r1中心下标是：" << r1 << std::endl;
     std::cout << "r2中心下标是：" << r2 << std::endl;
     std::cout << "r3中心下标是：" << r3 << std::endl;
     std::cout << "r4中心下标是：" << r4 << std::endl;
     std::cout << "r5中心下标是：" << r5 << std::endl;
     std::cout << "r6中心下标是：" << r6 << std::endl;
     std::cout << "r7中心下标是：" << r7 << std::endl;
     std::cout << "r8中心下标是：" << r8 << std::endl;
     std::cout << "r9中心下标是：" << r9 << std::endl;
     std::cout << "r10中心下标是：" << r10 << std::endl;

     delete s_1;
     */
    
    /*
     Solution_2 *s_2 = new Solution_2();
     std::vector<int> v1; int target1 = 1;
     std::vector<int> v2 = {1}; int target2 = 1;
     std::vector<int> v3 = {1}; int target3 = 0;
     std::vector<int> v4 = {1}; int target4 = 2;
     std::vector<int> v5 = {1,2}; int target5 = 0;
     std::vector<int> v6 = {1,2}; int target6 = 1;
     std::vector<int> v7 = {1,2}; int target7 = 2;
     std::vector<int> v8 = {1,2}; int target8 = 5;
     std::vector<int> v9 = {1,4}; int target9 = 3;
     std::vector<int> v10 = {1,4,6,7}; int target10 = 0;
     std::vector<int> v11 = {1,4,6,7}; int target11 = 1;
     std::vector<int> v12 = {1,4,6,7}; int target12 = 2;
     std::vector<int> v13 = {1,4,6,7}; int target13 = 4;
     std::vector<int> v14 = {1,4,6,7}; int target14 = 5;
     std::vector<int> v15 = {1,4,6,7}; int target15 = 6;
     std::vector<int> v16 = {1,4,6,8}; int target16 = 7;
     std::vector<int> v17 = {1,4,6,8}; int target17 = 8;
     std::vector<int> v18 = {1,4,6,8}; int target18 = 10;
     
     int r1 = s_2->searchInsert(v1, target1);
     int r2 = s_2->searchInsert(v2, target2);
     int r3 = s_2->searchInsert(v3, target3);
     int r4 = s_2->searchInsert(v4, target4);
     int r5 = s_2->searchInsert(v5, target5);
     int r6 = s_2->searchInsert(v6, target6);
     int r7 = s_2->searchInsert(v7, target7);
     int r8 = s_2->searchInsert(v8, target8);
     int r9 = s_2->searchInsert(v9, target9);
     int r10 = s_2->searchInsert(v10, target10);
     int r11 = s_2->searchInsert(v11, target11);
     int r12 = s_2->searchInsert(v12, target12);
     int r13 = s_2->searchInsert(v13, target13);
     int r14 = s_2->searchInsert(v14, target14);
     int r15 = s_2->searchInsert(v15, target15);
     int r16 = s_2->searchInsert(v16, target16);
     int r17 = s_2->searchInsert(v17, target17);
     int r18 = s_2->searchInsert(v18, target18);
     
     std::cout << "r1:" << (r1 == 0 ? "正确" : "错误") << std::endl;
     std::cout << "r2:" << (r2 == 0 ? "正确" : "错误") << std::endl;
     std::cout << "r3:" << (r3 == 0 ? "正确" : "错误") << std::endl;
     std::cout << "r4:" << (r4 == 1 ? "正确" : "错误") << std::endl;
     std::cout << "r5:" << (r5 == 0 ? "正确" : "错误") << std::endl;
     std::cout << "r6:" << (r6 == 0 ? "正确" : "错误") << std::endl;
     std::cout << "r7:" << (r7 == 1 ? "正确" : "错误") << std::endl;
     std::cout << "r8:" << (r8 == 2 ? "正确" : "错误") << std::endl;
     std::cout << "r9:" << (r9 == 1 ? "正确" : "错误") << std::endl;
     std::cout << "r10:" << (r10 == 0 ? "正确" : "错误") << std::endl;
     std::cout << "r11:" << (r11 == 0 ? "正确" : "错误") << std::endl;
     std::cout << "r12:" << (r12 == 1 ? "正确" : "错误") << std::endl;
     std::cout << "r13:" << (r13 == 1 ? "正确" : "错误") << std::endl;
     std::cout << "r14:" << (r14 == 2 ? "正确" : "错误") << std::endl;
     std::cout << "r15:" << (r15 == 2 ? "正确" : "错误") << std::endl;
     std::cout << "r16:" << (r16 == 3 ? "正确" : "错误") << std::endl;
     std::cout << "r17:" << (r17 == 3 ? "正确" : "错误") << std::endl;
     std::cout << "r18:" << (r18 == 4 ? "正确" : "错误") << std::endl;
     
     delete s_2;
     */
    
    /*
     Solution_3 *s_3 = new Solution_3();
 //    [[1,3],[2,6],[8,10],[15,18]]
     std::vector<std::vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
     std::vector<std::vector<int>> r = s_3->merge(v);
     for (int i = 0; i < r.size(); ++i) {
         std::cout << "元素" << i << ": start - " << r[i][0] << ", end - " << r[i][1] << std::endl;
     }
     delete s_3;
     */
    
    /*
     std::vector<int> nums = {1,2,3};
     nums.push_back(4);
     nums.insert(nums.cbegin()+1, 0);
     nums.erase(nums.cend()-2, nums.cend());

     for (auto num: nums) {
         std::cout << "元素：" << num << std::endl;
     }
     */
    
    
//    std::string a = "abc";
//    std::cout << "a.length: " << a.length() << ", a.size: " << a.size() << std::endl;
    
    /*
     Solution_4 *s_4 = new Solution_4();
     std::vector<std::string> v1 = {"flower","flow","flowht","flow"};
     std::string common = s_4->longestCommonPrefix(v1);
     std::cout << "v1 common str: " << common << std::endl;
     delete s_4;
     */
    
    /*
     Solution_5 *s_5 = new Solution_5();
 //    bool isP = s_5->isPalindrome("ab");
 //    std::cout << (isP ? "是回文字符串" : "不是回文字符串") << std::endl;
     std::string palindrome = s_5->longestPalindrome("vaaaaaav");
     std::cout << "最长回文子串是: " << palindrome << std::endl;
     delete s_5;
     */
    /*
     Solution_7 *s_7 = new Solution_7();
     int ans = s_7->strStr("hello", "ello");
     std::cout << "ans: " << ans <<std::endl;
     delete s_7;
     */
    
    /*
     Solution_8 *s_8 = new Solution_8();
     std::vector<char> s = {'a','b','c','d','e'};
     s_8->reverseString(s);
     for (auto &c : s) {
         std::cout << c << std::endl;
     }
     delete s_8;
     */
    
    /*
     Solution_9 *s_9 = new Solution_9();
     std::vector<int> v = {2,7,11,15};
     int target = 9;
     std::vector<int> r = s_9->twoSum(v, target);
     std::cout << r[0] << "," << r[1] << std::endl;
     delete s_9;
     */
    
    /*
     Solution_10 *s_10 = new Solution_10();
     std::vector<int> v = {3,2,2,3,4};
     int val = 2;
     int res = s_10->removeElement(v, val);
     std::cout << res <<std::endl;
     delete s_10;
     */
    /*
    Solution_11 *s_11 = new Solution_11();
    std::vector<int> v = {0,1,0,1,0,1,1,0};
    int res = s_11->findMaxConsecutiveOnes(v);
    std::cout << res << std::endl;
    delete s_11;
    */
    
    /*
     Solution_12 *s_12 = new Solution_12();
     std::vector<int> nums = {5};
     int target = 7;
     int res = s_12->minSubArrayLen(target, nums);
     std::cout << res << std::endl;
     delete s_12;
     */
    
    /*
     MyQueue<int> *queue = new MyQueue<int>();
     bool isEmpty = queue->isEmpty();
     queue->enqueue(1);
     queue->enqueue(2);
     queue->enqueue(3);
     
     int a = queue->front();
     queue->dequeue();
     int b = queue->front();
     queue->dequeue();
     queue->dequeue();
     bool empty = queue->isEmpty();
     delete queue;
     */
    
    /*
     MyCircularQueue<int> *queue = new MyCircularQueue<int>(5);
     bool empty = queue->isEmpty();
     queue->enQueue(1);
     queue->enQueue(2);
     queue->enQueue(3);
     queue->enQueue(4);
     queue->enQueue(5);
     bool full = queue->isFull();
     bool enqueue = queue->enQueue(6);
     queue->deQueue();
     queue->deQueue();
     queue->enQueue(5);
     delete queue;
     */
    
    /*
     Solution_14 *s_14 = new Solution_14();
     bool res = s_14->isValid("()[]{}");
     std::cout << (res ? "是合法字符串" : "不是合法字符串") << std::endl;
     delete s_14;
     */
    
    /*
     Solution_15 *s_15 = new Solution_15();
     std::vector<int> v = {73,74,75,71,69,72,76,73};
     std::vector<int> res = s_15->dailyTemperatures(v);
     
     for (auto& i : res) {
         std::cout << i << ", " ;
     }
     std::cout << std::endl;
     delete s_15;
     */
    /*
     Solution_16 *s_16 = new Solution_16();
     std::vector<std::string> token = {"4","13","5","/","+"};
     int r = s_16->evalRPN(token);
     std::cout << "r: " << r <<std::endl;
     delete s_16;
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
    
    
     /*
      ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
      [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
      */
     
    /*
     MyDoubleLinkedList::MyLinkedList *obj = new MyDoubleLinkedList::MyLinkedList();
      obj->addAtHead(1);
      obj->addAtHead(2);
      obj->addAtHead(3);
      int r0 = obj->get(0);
      int r1 = obj->get(1);
      int r2 = obj->get(2);
      obj->traverse();
      
      obj->addAtTail(4);
      obj->addAtTail(5);
      obj->addAtTail(6);

      obj->traverse();

      obj->addAtIndex(1, 11);
      obj->addAtIndex(3, 13);
      obj->traverse();

      obj->deleteAtIndex(3);
      obj->deleteAtIndex(1);
      obj->traverse();
     */
    
    /*
     Solution_29 *s_29 = new Solution_29();
     std::vector<int> v = {1,2,2,3,1,3,4};
     int num = s_29->singleNumber(v);
     std::cout << "num: " << num << std::endl;
     delete s_29;
     */
    
    /*
     Solution_30 *s_30 = new Solution_30();
     int res = s_30->firstUniqChar("aabbcdd");
     std::cout << "first index: " << res <<std::endl;
     delete s_30;
     */
    
    /*
     Solution_31 *s_31 = new Solution_31();
     int res = s_31->lengthOfLongestSubstring("aabaab!bb");
     std::cout << "maxLen: " << res << std::endl;
     delete s_31;
     */
    
    /*
     Solution_32 *s_32 = new Solution_32();
     std::vector<int> v = {1};
     std::vector<int> res = s_32->topKFrequent(v, 1);
     
     for (auto& i : res) {
         std::cout << i;
     }
     std::cout << std::endl;
     delete s_32;
     */
    
    
     TreeNode *node1 = new TreeNode(1);
     TreeNode *node2 = new TreeNode(2);
     TreeNode *node3 = new TreeNode(2);
     TreeNode *node4 = new TreeNode(3);
     TreeNode *node5 = new TreeNode(4);
     TreeNode *node6 = new TreeNode(3);
     TreeNode *node7 = new TreeNode(4);
     
     node3->left = node7;
     node3->right = node6;
     
     node2->left = node4;
     node2->right = node5;
     
     node1->left = node2;
     node1->right = node3;
     
     TreeNode *root = node1;
     
    
    /*
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(2);
    Node *node4 = new Node(3);
    Node *node5 = new Node(4);
    Node *node6 = new Node(3);
    Node *node7 = new Node(4);
    
    node3->left = node7;
    node3->right = node6;
    
    node2->left = node4;
    node2->right = node5;
    
    node1->left = node2;
    node1->right = node3;
    
    Node *root = node1;
    */
    
     // Solution_33 *s_33 = new Solution_33();
     // std::vector<int> res = s_33->preorderTraversal(root);
     // delete s_33;
     
    
    
     // Solution_34 *s_34 = new Solution_34();
     // std::vector<int> res = s_34->inorderTraversal(root);
     // delete s_34;
    
    
//    Solution_35 *s_35 = new Solution_35();
//    std::vector<int> res = s_35->postorderTraversal(root);
//    delete s_35;
    
//    for (auto i : res) {
//        std::cout << i << ", ";
//    }
//    std::cout << std::endl;
    
//    Solution_37 *s_37 = new Solution_37();
//    int maxDeep = s_37->maxDepth(root);
//    std::cout << "maxDeep: " << maxDeep << std::endl;
//    delete s_37;
    /*
     Solution_38 *s_38 = new Solution_38();
     bool res = s_38->isSymmetric(root);
     std::cout << (res ? "对称" : "不对称") << std::endl;
     delete s_38;
     */
    
    /*
     Solution_39 *s_39 = new Solution_39();
     bool res = s_39->hasPathSum(root, 8);
     std::cout << (res ? "有满足条件的路径和" : "没有满足条件的路径和") << std::endl;
     delete s_39;
     */
    
    /*
     Solution_41 *s_41 = new Solution_41();
     Node *res = s_41->connect(root);
 //    std::cout << (res ? "有满足条件的路径和" : "没有满足条件的路径和") << std::endl;
     delete s_41;
     */
    
    Solution_42 *s_42 = new Solution_42();
    TreeNode *ans = s_42->lowestCommonAncestor(root, node1, node2);
    std::cout << ans->val << std::endl;
    delete s_42;
    
    delete node3;
    delete node2;
    delete node1;
    
    
    
    
    
    return 0;
}


/*
 class Solution {
 public:
     ListNode* oddEvenList(ListNode* head) {
         if (head == nullptr) {
             return head;
         }
         ListNode* evenHead = head->next;
         ListNode* odd = head;
         ListNode* even = evenHead;
         while (even != nullptr && even->next != nullptr) {
             odd->next = even->next;
             odd = odd->next;
             even->next = odd->next;
             even = even->next;
         }
         odd->next = evenHead;
         return head;
     }
 };
 */
