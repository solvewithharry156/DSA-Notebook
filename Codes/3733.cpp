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