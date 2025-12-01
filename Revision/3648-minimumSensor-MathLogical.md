# 🧩 Problem Title

**Link:** [Leetcode]()
**Difficulty:** Medium
**Tags:** Maths | Logical 

---

## 🧠 Intuition
- With given value of k how much grid size we can cover in one time
- Hence Find side length of squre with K
- Find how many minimum squars required for the covering the given matrix

---

## 📝 Approach
- Find side lenght : ```side = 2*k + 1;```
- Find vertically required squares and those horizantally required and counted how many required.
- ```a = m%side == 0 ? m/side : (m/side) + 1```
- ```b = n%side == 0 ? n/side : (n/side) + 1```
- ```return a*b```

---

## ⏱️ Time Complexity
- **Time:** $$O(1)$$
- **Space:** $$O(1)$$

---

## 📌 Key Concepts
- Maths 

---

## 🧾 Code (C++)
```cpp
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSensors(int n, int m, int k) {
        int side = (2 * k) + 1;
        int a,b;
        if(n % side == 0){
            a=n/side;
        }else{
            a=(n/side) +1;
        }
        if(m%side == 0){
            b = m/side;
        }else{
            b = (m/side) + 1;
        }
        return a*b;
    }
};
int main()
{
    Solution obj;
    cout<<obj.minSensors(5,5,1)<<endl;
    return 0;
}
```
 
