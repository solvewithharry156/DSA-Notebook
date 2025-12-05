#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getLeftSideLarge(vector<int>&nums,vector<int>&left){
        int n=left.size();
        left[0]=0;
        stack<int>st;
        st.push(nums[0]);

        for(int i=1;i<n;i++){

            if(st.size() == 0){
                left[i]=0;
                st.push(nums[i]);    
            }else{
                while(st.empty() == false and st.top() < nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    left[i]=0;
                }else{
                    left[i] = st.top();
                }
                st.push(nums[i]);
            }

        }

    }
    void getRightSideLarge(vector<int>&nums,vector<int>&right){
        int n=nums.size();
        right[n-1] = 0;
        stack<int>st;
        st.push(nums[n-1]);
        
        for(int i=n-2;i>=0;i--){
            if(st.size() == 0){
                st.push(nums[i]);
                right[i] = 0;
            }else{
                while(st.empty() == false and nums[i] > st.top()){
                    st.pop();
                }
                if(st.empty()){
                    right[i] = 0;
                }else{
                    right[i] = st.top();
                }
                st.push(nums[i]);
            }
        }

    }
    void print(vector<int>&vec){
        cout<<"Elements : ";
        for(int i:vec){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    long long bowlSubarrays(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>left(n);
        vector<int>right(n);
        getRightSideLarge(nums,right);
        getLeftSideLarge(nums,left);
        print(right);
        print(left);
        
        int cnt= 0;
        for(int i=1;i<n-1;i++){
            if(left[i] and right[i]){
                cnt++;
            }
        }
        return cnt;

    }
};

int main()
{
    Solution obj;

    vector<int>vec = {10,9,8,7,6,11,12,13,14};
    cout<<obj.bowlSubarrays(vec)<<endl;
    
    return 0;
}