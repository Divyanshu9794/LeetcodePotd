//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) { 
        vector<int> least_prime(n+1, 0); 
        least_prime[1] = 1; 
        for (int i = 2; i <= n; i++) { 
            if (least_prime[i] == 0) {  
                least_prime[i] = i; 
                for (int j = 2*i; j <= n; j += i) 
                    if (least_prime[j] == 0) 
                       least_prime[j] = i; 
            } 
        } 
        return least_prime;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends