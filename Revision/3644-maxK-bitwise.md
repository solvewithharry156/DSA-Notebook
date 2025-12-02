# 🧩 Maximum K to Sort a Permutation

**Link:** [Leetcode](https://leetcode.com/problems/maximum-k-to-sort-a-permutation)
**Difficulty:** Easy 
**Tags:** Bitwise operation

---

## 🧠 Intuition
- Check which number is not on its correct place
- Hence those elements need to swap
- There is less description by leetcode
- Hence for submition take commulative bitwise and of elements not at correct position

---

## 📝 Approach
- Start with k=INT_MAX
- Then take the commulative bitwise AND of elements not at correct position

---

## ⏱️ Time Complexity
- **Time:** $$O(n)$$
- **Space:** $$O(1)$$

---

## 📌 Key Concepts
- Logical
- Bitwise

---

## 🧾 Code (C++)
```cpp
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==i){
                continue;
            }
            if(k==INT_MAX){
                k=nums[i];
            }else{
                k = nums[i]&k;   
            }
            
        }
        return k==INT_MAX ? 0 : k;
    }
};
int main()
{
    Solution obj;
    vector<int>nums = {0,3,2,1};
    cout<<obj.sortPermutation(nums)<<endl;;   
    return 0;
}
```

