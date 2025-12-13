#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool checkAlphanumeric(string s){
        if(s==""){
            return false;
        }
        for(char c:s){
            if(!((c>='a' and c<='z') or (c>='A' and c<='Z') or c=='_' or (c>='0' and c<='9'))){
                return false;
            }
        }
        return true;
    }
    bool validBusiness(string &s){
        if(s =="electronics" or s=="grocery" or s=="pharmacy" or s=="restaurant"){
            return true;
        }
        return false;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>res;
        int n=code.size();
        vector<vector<string>>vec;
        for(int i=0;i<n;i++){
            if(isActive[i] and checkAlphanumeric(code[i]) and validBusiness(businessLine[i])){
                vec.push_back({code[i],businessLine[i]});
            }
        }
        unordered_map<string,int>mp;
        mp["electronics"]=1;mp["grocery"]=2;
        mp["pharmacy"]=3;mp["restaurant"]=4;

        sort(vec.begin(),vec.end(),[](const vector<string>&a,const vector<string>&b){

            if(a[1]==b[1]){
                if(a[0] < b[0]){
                    return true;
                }else{
                    return false;
                }
            }else{
                
                if(a[1] > b[1]){
                    return false;
                }else{
                    return true;
                }

            }
        });


        for(int i=0;i<vec.size();i++){
            res.push_back(vec[i][0]);
        }
        return res;
    }  
};

int main()
{
    Solution obj;
    vector<string>code={"GROCERY15","ELECTRONICS_50","DISCOUNT10"};
    vector<string>businessline ={"grocery","electronics","invalid"};
    vector<bool>isActive={false,true,true};

    vector<string>res = obj.validateCoupons(code,businessline,isActive);
    for(auto i:res){
        cout<<i<<" ";
    }
    cout<<endl;
    // if(obj.checkAlphanumeric("abc123ABC")){
    //     cout<<"Yes"<<endl;
    // }else{
    //     cout<<"NO"<<endl;
    // }
    return 0;
}