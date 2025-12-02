#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==i){
                continue;
            }
            if(k==INT_MAX){
                k=nums[i];
            }else{
                k = nums[i]&k;   
            }
            
        }
        return k==INT_MAX ? 0 : k;
    }
};
int main()
{
    Solution obj;
    vector<int>nums = {0,3,2,1};
    cout<<obj.sortPermutation(nums)<<endl;;   
    return 0;
}