class Solution {
public:
    string reorganizeString(string str) {
    
        map<char,int>mp;int n=str.size();
        for(int i=0;i<n;i++){
            mp[str[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i:mp)
        pq.push(make_pair(i.second,i.first));
        string ans=str;
        int k=0;
        while(!pq.empty()){
            int m=pq.top().first;
            while(m--){
                if(k>=n)
                k=1;
                ans[k]=pq.top().second;
                k+=2;
            }
            pq.pop();
        }
        for(int i=0;i<n-1;i++){
            if(ans[i]==ans[i+1])
            return "";
        }
        return ans;
     
    }
};
