#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSensors(int n, int m, int k) {
        int side = (2 * k) + 1;
        int a,b;
        if(n % side == 0){
            a=n/side;
        }else{
            a=(n/side) +1;
        }
        if(m%side == 0){
            b = m/side;
        }else{
            b = (m/side) + 1;
        }
        return a*b;
    }
};
int main()
{
    Solution obj;
    cout<<obj.minSensors(5,5,1)<<endl;
    return 0;
}