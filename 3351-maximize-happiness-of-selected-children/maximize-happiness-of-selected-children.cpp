#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        priority_queue<int, vector<int>, greater<int>> pq(happiness.begin(), happiness.begin()+k);//minheap
        for(int i=k; i<n; i++){
            pq.push(happiness[i]);
            pq.pop();
        }
        long long sum=0;
        for(int i=k-1; i>=0; i--){
            long long x=max(0, pq.top()-i);
        //    cout<<x<<endl;
            pq.pop();
            sum+=x;
        }
        return sum;
        
    }
};