# 🧩 Maximum Balanced Shipment

**Link:** [Leetcode](https://leetcode.com/problems/maximum-balanced-shipments)
**Difficulty:** Easy
**Tags:** Logical

---

## 🧠 Intuition
- Check where we can make shipment 

---

## 📝 Approach
- Start at ```index=1``` check whether we get minimum of elements of that subarray 
- If yes then increase the cnt
- Then start from the Next element 

---

## ⏱️ Time Complexity
- **Time:** $$O(1)$$
- **Space:** $$O(0)$$

---

## 📌 Key Concepts
- Array based Logical


---

## 🧾 Code (C++)
```cpp
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxBalancedShipments(vector<int>& wt) {
        int cnt =0;
        int maxi =wt[0];
        for(int i=1;i<wt.size();i++){
            maxi = max(maxi,wt[i]);
            if(maxi > wt[i]){
                cnt++;
                i++;
                if(i<wt.size()){
                    maxi = wt[i];
                }
            }
        }
        return cnt;
    }
};
int main()
{
    Solution obj;
    
    return 0;
}
```

