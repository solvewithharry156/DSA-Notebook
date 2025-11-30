# DSA-Notebook


# First Positive Missing

## 📋 Problem Information
- **Problem Number:** 41
- **Platform:** LEETCODE
- **Difficulty:** HARD
- **Topic:** STACK

## 🔗 Problem Link
[LEETCODE - First Positive Missing](https://leetcode.com/problems/first-missing-positive)

## 📝 Problem Description
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

## 💡 Solution Approach
Idea is to Place the element to its correct position.

### Key Points:
- Those number are present in the array we can place them at the correct position by swapping .
- If any element is out of range i.e nums[i] > n and nums[i] < 1 we can ignore that.
- For element in range we can place them at there correct position.
- Ex. [3,4,-1,1] 3 can be placed at 2nd index by swapping.
- If swap if done then again check for that element is it at correct position.
- if any element is at correct position and same element is trying to take that place then continue and check next element.
- Ex.[1,1] for this at 1st index 1 will keep swapping so at condition if(nums[x-1] != x)
- At last check for if(nums[i] != i+1) return i;

## 💻 Code Implementation

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(nums[i] <= n && nums[i] >= 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) return i + 1;
        }

        return n + 1;
    }
};

```

## ⏰ Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## 🏷️ Tags
`Arrays`

---
*Generated on 6/18/2025 | Topic: stack*
