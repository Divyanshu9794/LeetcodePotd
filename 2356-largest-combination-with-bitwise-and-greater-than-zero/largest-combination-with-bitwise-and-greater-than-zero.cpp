class Solution {
public:
    int largestCombination(vector<int>& c) {
        
        vector<int>v(24,0);// map vector

        for(int i=0;i<c.size();i++)
        {
               bitset<24>binary(c[i]);// num to binary
               string temp=binary.to_string(); // binary to store

               for(int i=temp.size()-1;i>=0;i--)
               {
               if(temp[i]=='1')
               v[i]++;  // inc that bit fre
               }
        }


        int maxi=INT_MIN; // finding max freq
        for(int i=0;i<v.size();i++)
        {
            maxi=max(maxi,v[i]);
        }

        cout<<maxi;
        return maxi;
    }
};