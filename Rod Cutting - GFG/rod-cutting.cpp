//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++




class Solution{
  public:
    int cutRod(int p[], int n) {
        //code here
        int i,j,k;
        vector<long long int>dp;
        
        
        for(i=0;i<n;i++){
            dp.push_back(p[i]*1LL);
            for(j=0;j<i;j++){
                dp[i]=max(dp[i],dp[i-j-1]+dp[j]);
                
            }
        }return dp[n-1];
        
    }
};









//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends