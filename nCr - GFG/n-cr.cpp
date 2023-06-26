//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
        if(r>n) return 0;
        else{
            long long p=pow(10,9)+7;
            vector<vector<int>>ar(n+1,vector <int> (n+1));
            ar[0][0]=1;
            ar[1][0]=1;
            ar[1][1]=1;
            for(int i=2;i<=n;i++){
                ar[i][0]=1;
                ar[i][i]=1;
            }
            for(int i=2;i<=n;i++){
                for(int j=1;j<n;j++){
                    ar[i][j]=((ar[i-1][j]%p)+(ar[i-1][j-1]%p))%p;
                }
            }
            return ar[n][r];
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends