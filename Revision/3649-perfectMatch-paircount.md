# 🧩 Number of Perfect Pairs

**Link:** [Leetcode](https://leetcode.com/problems/number-of-perfect-pairs)
**Difficulty:** Medium 
**Tags:** Sorting | Math reasoning | Binary-Search

---

# Condition for the Perfect pair 
- i < j  
- Let a = nums[i], b = nums[j]. Then:
    - ```min(|a - b|, |a + b|) <= min(|a|, |b|)```
    - ```max(|a - b|, |a + b|) >= max(|a|, |b|)```


--- 

## 🧠 Intuition

- Check for which are the number possible we can use for making the pairs.
- By doing the calculation or normal using the test case and conclude the results from it .

---

## 📝 Approach
- 1st consider the both positive numbers so in first condition its always a+b will greater then a or b
- Hence we have to consider the ```|a-b|``` and by this if we are a then the next number should be 
- ``` <= 2x```
- After checking conditions for the both negative , one positve one negative its working same 
- Hence it will same 
- So make all elements positive then sort and work on it 
- So sort the array and using binary search take the element less than equal to 2x if we are the x as current element


---

## ⏱️ Time Complexity
- **Time:** $$O(nlogn)$$
- **Space:** $$O(1)$$

---

## 📌 Key Concepts
- Taking the mathematical reasoning out of it and solve 


---

## 🧾 Code (C++)
```cpp

class Solution {
    public:
    void print(vector<int>&vec){
        cout<<"Elements : ";
        for(int i:vec){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    long long perfectPairs(vector<int>& nums) {
        long long res = 0;

        for(int i=0;i<nums.size();i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            
            int index = upper_bound(nums.begin(),nums.end(),2*(nums[i])) - nums.begin();
            if(index!=i){
                res += (index-i-1);
            } 
        }
        return res;
        
    }
};

```
 
