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