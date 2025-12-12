#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> getPrimes(int n){
        vector<int>vec(n+1,1);
        for(int i=2;i*i<=n;i++){
            
            if(vec[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    vec[j]=0;
                }
            }
        }
        vector<int>ans;
        for(int i=2;i<=n;i++){
            if(vec[i]){
                ans.push_back(i);
            }
        }
        return ans;

    }
    void print(vector<int>&vec){
        cout<<"Elements : ";
        for(int i:vec){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    int largestPrime(int n) {
        
        vector<int>vec=getPrimes(n);
        // print(vec);
        unordered_set<int>st(vec.begin(),vec.end());
        
        int res=0;
        long long sum=0;
        for(int i=0;i<vec.size();i++){
            sum+=vec[i];
            if(st.find(sum) != st.end()){
                if(sum > res){
                    res=sum;
                }
            }
        }
        return res;

    }
    
};

class Solution1 {
private:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        if (n <= 3) {
            return true;
        }
        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }

public:
    int largestPrime(int n) {
        if (n == 2) return n;
        
        int ans = 0;
        int sum = 0;
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                sum += i;
                if (sum > n) break;
                if (isPrime(sum)) ans = sum;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    Solution1 obj1;
    int n=19;
    cout<<   obj.largestPrime(n)<<endl;
    cout<<   obj1.largestPrime(n)<<endl;
    return 0;
}