class Solution {
public:
    static bool comp(vector<int> &a , vector<int> &b){
            return a[1]<b[1];
        }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),comp);
        if(courses.size()==0) return 0;
        priority_queue <int> pq;
        int sum=0;
        for(auto i: courses){
            sum += i[0];
            pq.push(i[0]);
            if(sum > i[1]){
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
