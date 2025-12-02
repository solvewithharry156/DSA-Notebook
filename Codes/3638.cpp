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