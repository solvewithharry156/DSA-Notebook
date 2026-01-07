# 🧩 205. Isomorphic Strings

**Link:** [Leetcode](https://leetcode.com/problems/isomorphic-strings)

**Difficulty:** Easy  

**Tags:** Hashing | Strings 

---

## 🧠 Intuition
- Two strings are isomorphic if every character in s always maps to the same character in t,
  and that mapping must be one-to-one (no two characters from s map to the same character in t).
- So we must check:
- ✔ same character → always same mapping
- ✔ no conflicting reverse mapping
- To verify both directions, you maintain two hash maps.

---

## 📝 Approach
- Create two maps
    - mp1: maps characters from s → t
    - mp2: maps characters from t → s
- Traverse both strings together
- Check forward mapping (s → t)
- If s[i] is already in mp1
- But it maps to a different t[i]
- 👉 Strings are NOT isomorphic → return false
- Check reverse mapping (t → s)
- If t[i] already mapped in mp2
- But mapped to a different s[i]
    - 👉 return false
- If mapping doesn’t exist yet
- Store the mapping both ways
    ```s[i] → t[i]
        t[i] → s[i]```
- Repeat for all characters
- If no conflicts found
- Return true → strings are isomorphic


---

## ⏱️ Time Complexity
- **Time:** $$O(n)$$
- **Space:** $$O(0)$$

---

## 📌 Key Concepts


---

## 🧾 Code (C++)

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
       
        unordered_map<char,char>mp1,mp2;

        for(int i=0;i<s.length();i++){
            if(mp1.count(s[i]) and mp1[s[i]] != t[i]){
                return false;
            }
            if(mp2.count(t[i]) and mp2[t[i]] != s[i]){
                return false;
            }
            mp1[s[i]] = t[i];
            mp2[t[i]]=s[i];
        }
        return true;

    }
};

int main()
{
    Solution obj;
    
    string s ="egg";
    string t = "add";

    if(obj.isIsomorphic(s,t)){
        cout<<"Isomorphic"<<endl;
    }else{
        cout<<"NOT -Isomorphic"<<endl;
    }
    

    return 0;
}

```

