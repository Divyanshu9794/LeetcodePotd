//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        int fives=0,tens=0;
        for(auto i:bills) {
            if(i==5) fives++;
            else if(i==10) {
                if(!fives) return 0;
                fives--; tens++;
            }
            else {
                if(!fives) return 0;
                else if(!tens) {
                    if(fives<3) return 0;
                    fives-=3;
                }
                else {
                    fives--; tens--;
                }
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends