//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int A[], int n, int k) {
         priority_queue<int> pq;
        for(int i = 0; i< n; i++){
            pq.push(A[i]);
        }
        long long sum = 0;
        while(k--){
            int temp = pq.top();
            sum+= temp;
            pq.pop();
            pq.push(temp/2);
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends