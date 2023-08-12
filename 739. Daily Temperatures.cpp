class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int>s;
        vector<int>diff(temperatures.size(),0);
       
        s.push(0);
        for(int  i=1 ;i < temperatures.size();i++)
        {
           
            while(!s.empty())
            {
               bool flag = false;
               
                if(temperatures[s.top()]<temperatures[i])
                   { diff[s.top()] = i-(s.top());
                    s.pop();
                    flag = true;}
                    if(!flag || s.size()==0){
                        s.push(i);
                        break;
                    }
                    
        }

                }
    

        
        return diff;
    }
};
