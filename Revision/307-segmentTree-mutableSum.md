# 🧩 307. Range Sum Query - Mutable

**Link:** [Leetcode](https://leetcode.com/problems/range-sum-query-mutable)

**Difficulty:**  Medium

**Tags:** Segement tree | recursion | 

---

## 🧠 Intuition


---

## 📝 Approach
- 
- 
- 

---

## ⏱️ Time Complexity
- **Time:** $$O(n)$$
- **Space:** $$O(n)$$

---

## 📌 Key Concepts
- Building segment tree

---

## 🧾 Code (C++)
```cpp
#include<bits/stdc++.h>
using namespace std;
class NumArray {
public:

    vector<int>vec;
    vector<int>tree;
    int n;
    void build(int ind,int low,int high){
        if(low == high){
            tree[ind] = vec[low];
            return;
        }
        int mid = (low + high) /2;

        build(1 + mid*2 , low,mid);
        build(2 + mid*2 , mid+1,high);
        tree[ind] = tree[mid*2 + 1] + tree[mid*2 + 2];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        vec= nums;
        tree.resize(4*n);
        build(0,0,n-1);
    }

    void updateVal(int ind,int low,int high,int i,int val){
        if(low==high){
            tree[ind] = val;
            return;
        }
        int mid = (low+high) /2;
        if(i<=mid){
            updateVal((mid*2)+1,low,mid,i,val);
        }else{
            updateVal((mid*2)+2,mid+1,high,i,val);
        }
        tree[ind] = tree[(mid*2) + 1] + tree[(mid*2) + 2];
    }


    void update(int index, int val) {
       updateVal(0,0,n-1,index,val);
    }

    int getSum(int ind,int low,int high,int l,int r){
        if(high<l or r<low){
            return 0;
        }
        if(l<=low and high<=r){
            return tree[ind];
        }
        int mid = (low + high) / 2;
        int left = getSum(mid*2 + 1,low,mid,l,r);
        int right = getSum(mid*2 + 2,mid+1,high,l,r);
        return left+right;
    }

    
    int sumRange(int left, int right) {
        return getSum(0,0,n-1,left,right);
    }
};
int main()
{
    
    vector<int>vec = {1,2,3,4,5};
    //provide the queries here by creating the 2d vector for the sum,update and initialize function

    
    
    return 0;
}

```

