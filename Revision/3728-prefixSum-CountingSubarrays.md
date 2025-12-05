# 🧩 Stable Subarrays With Equal Boundary and Interior Sum

**Link:** [Leetcode](https://leetcode.com/problems/stable-subarrays-with-equal-boundary-and-interior-sum)

**Difficulty:** Medium

**Tags:** PrefixSum | Map

---

## 🧠 Intuition
- We need to find subarrays such at ```a[l] == sum``` of elements from ```[l + 1...r - 1] == a[r]```.
- Let's convert this into a prefix sum style statement, ```pre[r - 1] - pre[l] == a[l] == a[r]```.
- This can also be re-written as, ```pre[r - 1] = a[l] + pre[l] and a[l] == a[r]``` must always be true.
- So firstly, we use a hashmap here inorder to store the prefix sum so far using which later we can find the stable subarrays.
- Here for the map,
    - ```mpp[x] = elements of the array encountered so far.```
    - ```mpp[x][y] = prefix sum when at x.```
- While traversing, we need to check that for every index i, how many indices are there which satisfy ```a[l] == a[r]``` condition and have the same prefix as the current element a[r].
- The count of such elements is added by simply using ```res += mpp[a[i]][pre - a[i]]```.
- An edge case to keep in mind here is that, when ```i > 0 and a[i] == a[i - 1] == 0```, this might be counted as a subarray, but its mentioned in the problem description that the subarray size must be >= 3 so we reduce our count incase such a case is encountered.

---

## 📝 Approach
- Initilize the required variables and map
- Then Till ```i-1``` if that element is present and the ```prefixSum-x``` also present in the map increases the res by those subarrays
- Also handles the edge case of elements containing 0 because the that diffrence might be present 

---

## ⏱️ Time Complexity
- **Time:** $$O(n)$$
- **Space:** $$O(n)$$

---

## 📌 Key Concepts
- Standard counting the subarrays with given sum Problem 

---

## 🧾 Code (C++)
```cpp
#include<bits/stdc++.h>
using namespace std;
class Solution {
    using ll =long long;
public:
    long long countStableSubarrays(vector<int>& cap) {
        int n = cap.size();
        long long cnt =0;
        
        unordered_map<ll ,unordered_map<ll,ll>>mp;
        ll prefixSum = 0;
        
        for(int i =0;i<n;i++){
            int x = cap[i];
            if(mp.count(x) and mp[x].count(prefixSum - x)){
                cnt+= mp[x][prefixSum-x];
            }
            prefixSum += x;
            mp[x][prefixSum]++;
            if(i>0 and cap[i-1] == cap[i] and cap[i]==0){
                cnt--;
            }
        }
        return cnt;

        
    }
};
int main()
{
    Solution obj;
    // vector<int>vec={-4,4,0,0,-8,-4};
    vector<int>vec={9,3,3,3,9};

    cout<<obj.countStableSubarrays(vec)<<endl;
    
    return 0;
}

```

