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