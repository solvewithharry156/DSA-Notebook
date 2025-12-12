# 🧩 3767. Maximize Points After Choosing K Tasks

**Link:** [Leetcode](https://leetcode.com/problems/maximize-points-after-choosing-k-tasks)

**Difficulty:** Medium

**Tags:** Sorting | Greedy

---

## 🧠 Intuition
- First intuition come to mind is which to k should be selected from the techniques1
- And then from remaining we can choose the maximum between any of the techiniques 
- For that we among that k what parameter should be checked 
- we have to find that which first k will be added in final result
- Hence those values contributing more in final result will be added 
- so to check this find max diffrences having ```t1[i] > t2[i]``` that top k values we will add

---

## 📝 Approach
- For checking the whcih values to consider store the diffrence with index in pair or 2d vector
- then sort them in decending order and that top k will added in final res 
- Out of remaining choose the maximum values .
- return final result 

---

## ⏱️ Time Complexity
- **Time:** $$O(nlogn)$$
- **Space:** $$O(n)$$

---

## 📌 Key Concepts
- Greedy, thinking which values to choose

---

## 🧾 Code (C++)
```cpp
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void print(vector<int>&vec){
        cout<<"Elements : ";
        for(int i:vec){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    long long maxPoints(vector<int>& t1, vector<int>& t2,   int k) {
        
        int n = t1.size();
        vector<vector<int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({t1[i]-t2[i],i});
        }
        sort(vec.rbegin(),vec.rend());
        long long res=0;
        for(int i=0;i<k;i++){
            res+=t1[vec[i][1]];
        }
        for(int i=k;i<n;i++){
            res+= max(t1[vec[i][1]],t2[vec[i][1]]);
        }
        return res;
    }
};
int main()
{
    Solution obj;
    vector<int>t1={5,2,10};
    vector<int>t2= {10,3,2};
    cout<<obj.maxPoints(t1,t2,2)<<endl;;    
    return 0;
}
```

