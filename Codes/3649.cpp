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

int main()
{
    Solution obj;
    vector<int>vec={-3,2,-1,4};
    vector<int>vec1={0,1,2,3};
    cout<<obj.perfectPairs(vec)<<endl;
    
    return 0;
}