//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    vector<string> res;
		    sort(S.begin(),S.end());
		    string first=S;
		    res.push_back(S);
		    do{
		        
		        next_permutation(S.begin(),S.end());
		        res.push_back(S);
		        
		    }
		    while(S!=first);
		    
		    res.pop_back();
		    
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends