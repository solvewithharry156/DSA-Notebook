# 🧩 Make sum divisible by p

**Link:** [Link](https://leetcode.com/problems/make-sum-divisible-by-p)

**Difficulty:** Medium 

**Tags:** PrefixSum | Map

---

## 🧠 Intuition
- As check that for whole array how much extra mod value to remove

---

## 📝 Approach
- If calculating ```sum(array)``` we get to know that how much mod value to remove
- Let ```k= SUM(array) % p```
- Then by using the technique k size subarray 
- Find the subarray that sum modulo's is equal to k
- Sometime Prefix MOD - k may become negative handle it
- For handling it use : ```(prefixSum-k + p) % p```

---

## ⏱️ Time Complexity
- **Time:** $$O(n)$$
- **Space:** $$O(n)$$

---

## 📌 Key Concepts
- Prefix Sum with modulo p  
- Handle the modulo if becoming negative by adding mod and then taking the mod  

---

## 🧾 Code (C++)
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int getMinArrayofSumModP(vector<int>nums,int k,int p){
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        int prefixSum = 0;
        int res =n;
        for(int i=0;i<n;i++){
            prefixSum = (prefixSum + nums[i]) % p;
            if(mp.count((prefixSum - k + p) % p)){
                res = min(res,i - mp[(prefixSum - k + p) % p]);
            }
            mp[prefixSum] = i;
        }
        return res;
    }
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;
        for(int i:nums){
            sum+=i;
        }
        if(sum % p ==0){return 0;}
        int req = (sum % p);
        int res = getMinArrayofSumModP(nums,req,p);
        return res==n ? -1:res;
    }
    
};

int main()
{
    Solution obj;
    vector<int>vec ={26,19,11,14,18,4,7,1,30,23,19,8,10,6,26,3};
    int p =26;
    cout<<obj.minSubarray(vec,p)<<endl;
    return 0;
}
```
