#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll=long long;
    long long bruteTotalScore(int hp,vector<int>&d, vector<int>&req){
        long long res=0;
        int n=d.size();
        for(int i=0;i<n;i++){
            int p=hp;
            int cnt=0;
            for(int j=i;j<n;j++){
                p-=d[j];
                if(p>=req[j]){
                    cnt++;
                }
            }    
            res+=cnt;         
        }   
        return res;
    }

    int getLeftIndexUsingBinarySearch(int currIndex,int hp,vector<int>&pref,vector<int>&req){

        int l=0;
        int r=currIndex;
        int index=-1;
        while(l<=r){
            int mid = (l+r)/2;
            int diff = mid==0 ? 0 : pref[mid-1];
            int remain = hp - (pref[currIndex] - diff);
            if( remain>=0 and remain >= req[currIndex]){
                index=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return index;
    }
    long long totalScore(int hp, vector<int>& d, vector<int>& req) {    
        ll res=0;
        int n=d.size();
        vector<int>pref(n);
        pref[0]=d[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + d[i];
        }
        // cout<<"\n";
        for(int i=0;i<n;i++){

            int l = getLeftIndexUsingBinarySearch(i,hp,pref,req);
            if(l==-1){
                continue;
            }
            res += i-l+1;
        }
        return res;
    }
};
int main()
{
    Solution obj;
    vector<int>damage = {4,6,3,10,5};
    vector<int>requirement = {12,7,5,4,1};
    int hp=20;

    cout<<obj.bruteTotalScore(hp,damage,requirement)<<endl;;
    cout<<obj.totalScore(hp,damage,requirement)<<endl;;
    
    return 0;
}