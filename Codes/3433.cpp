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
    

    vector<int> getMentionUsers(string &s){
        string num="";
        vector<int>ids;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ' or s[i]=='i' or s[i]=='d'){
                if(num.length()>0){
                    ids.push_back(stoi(num));
                }
                num="";
                continue;;
            }
            num+=s[i];
        }
        ids.push_back(stoi(num));
        return ids;

    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int>mentions(numberOfUsers,0);
        int n=events.size();
        sort(events.begin(),events.end(),[] (const vector<string>&a,const vector<string>&b){
            int t1 = stoi(a[1]);
            int t2 = stoi(b[1]);

            if(t1 == t2){
                if(a[0] == "MESSAGE" and b[0] == "OFFLINE"){

                    return false;
                }else{
                    return true;

                }
            }
            return t1 < t2;
        });
        

        for(int i=0;i<n;i++){
            cout<<events[i][0]<<" " <<events[i][1]<<" -> "<<events[i][2]<<endl;
        }
        vector<vector<int>>isOnline;
        for(int i=0;i<numberOfUsers;i++){
            isOnline.push_back({1,0});
        }

        int cntAllMentions=0;
        for(int i=0;i<n;i++){


            
            if(events[i][0]=="MESSAGE"){
                int currentTime = stoi(events[i][1]);
                for(int j=0;j<numberOfUsers;j++){
                    if((currentTime - isOnline[j][1]) >= 60){
                        isOnline[j][0]=1;
                    }
                }

                if(events[i][2]=="ALL"){
                    cntAllMentions++;
                }else if(events[i][2]=="HERE"){
                    for(int j=0;j<numberOfUsers;j++){
                        
                        if(isOnline[j][0]){
                            mentions[j]++;
                        }
                    }
                }else{

                    vector<int>mentionUsers = getMentionUsers(events[i][2]);
                    for(int j:mentionUsers){
                        mentions[j]++;
                    }

                }

            }else{
                int user=stoi(events[i][2]);
                int currentTime = stoi(events[i][1]);
                isOnline[user][0]=0;
                isOnline[user][1]=currentTime;
            }
        }

        // cout<<"all mentions : "<<cntAllMentions<<endl;
        for(int i=0;i<numberOfUsers;i++){
            mentions[i]+=cntAllMentions;
        }
        
        return mentions;

        


    }
    
};

int main()
{
    Solution obj;
    int numberOfUsers = 3;
    vector<vector<string>>events = {
        {"MESSAGE", "10", "id1 id0"},
        {"OFFLINE", "11", "0"},
        {"MESSAGE", "12", "ALL"}
    };

    vector<vector<string>>events2 ={
        {"MESSAGE","2","HERE"},
        {"OFFLINE","2","1"},
        {"OFFLINE","1","0"},
        {"MESSAGE","61","HERE"}
    };
    vector<vector<string>> events3 = {
    {"MESSAGE", "1", "ALL"},
    {"OFFLINE", "66", "1"},
    {"MESSAGE", "66", "HERE"},
    {"OFFLINE", "5", "1"}
};

    vector<int>res = obj.countMentions(numberOfUsers,events3);
    obj.print(res);

    return 0;
}