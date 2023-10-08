class Solution { 
public: 
    int minProcessingTime(vector<int>& processing_time, vector<int>& T) { 
        sort(processing_time.begin(),processing_time.end()); 
        sort(T.begin(),T.end(),[](const int x,const int y){return x>y;}); 
        int m=0;
        int res=0; 
        for(int st:processing_time){ 
            int current=0;
            int count=0; 
            while(m<T.size() && count<4){ 
                current=max(current,st+T[m]); 
                m++;
                count++; 
            } 
            res=max(res,current); 
        } 
        return res; 
    } 
};