class Solution {
public:
    vector<int> findnse(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n:st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findpsee(vector<int>& arr){
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]> arr[i]){
                st.pop();
            }
            psee[i] = st.empty() ? -1:st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findnse(arr);
        vector<int> psee = findpsee(arr);
        int n = arr.size();
        int total =0;
        int mod= (int)(1e9+7);
        for(int i=0;i<n;i++){
            int left = i-psee[i];
            int right = nse[i]-i;
            total = (total + (right * left * 1LL * arr[i])%mod)%mod;

        }
        return total;
    }
};