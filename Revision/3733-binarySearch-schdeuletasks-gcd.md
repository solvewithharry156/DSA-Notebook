# 🧩 3733. Minimum Time to Complete All Deliveries

**Link:** [Leetcode](https://leetcode.com/problems/minimum-time-to-complete-all-deliveries)

**Difficulty:**  Medium

**Tags:** Sorting | Binary Search | GCD | LCM | Math Reasoning

---

## 🧠 Intuition
- We can check multiple options using the binary search with minimum and max values possible
- Then by studying the conditions define the requirements , if they are satidfied then we can return tru for that T
- Hence apply binary search technique to minimize the result

---

## 📝 Approach
- First the required slots should be available for the individuals drones 
- Check them individually 
- ```T - (T / ri) < di```
- Then if slots that both drones are charging cannot be use hence after removing them does that hrs T works for given T
- ```(d1+d2) > (T -(T / lcm)) return false``` 
- Atleast the withhout any gap consecutively ```d1+d2``` places should be available
- If this conditions are satisfied then we that time T works for us 
- So by using the binary search we can minimize the value

---

## ⏱️ Time Complexity
- **Time:** $$O(logn)$$
- **Space:** $$O(1)$$

---

## 📌 Key Concepts
- For LCM calculation Sometime ```lcm(a,b)``` function in c++ not available 
- Hence use ```a*b / gcd(a,b);```

---

## 🧾 Code (C++)
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int getGCD(long long a,long long b){
     
        while (b>0)
        {
            if(b>a){
                swap(a,b);
            }else{
                a = a%b;
            }
        }
        return a;
        
    }
    bool isPossible(long long T,long long d1,long long d2,int r1,int r2,long long lcm){
        if(T - (T / r1) < d1){
            return false;
        }
        if(T - (T / r2) < d2){
            return false;
        }
        if((d1+d2) > (T -(T / lcm))){
            return false;
        }
        return true;



    }
    long long minimumTime(vector<int>& d, vector<int>& r) {

        long long left = 0;
        long long right = 1e18;
        long long lcmVal = (long long)(r[0]) * (long long)r[1]  / getGCD(r[1],r[0]);
        long long res=right;
        while(left<=right){
            long long mid = (left+right) / 2;
            if(isPossible(mid,d[0],d[1],r[0],r[1],lcmVal)){
                right=mid-1;
                res=min(res,mid);
            }else{
                left=mid+1;
            }
        }
        return res;

    }
};

int main()
{
    Solution obj;   
    vector<int>d={3,1};
    vector<int>r ={2,3};
    cout<<obj.minimumTime(d,r)<<endl;
    return 0;
}
```

