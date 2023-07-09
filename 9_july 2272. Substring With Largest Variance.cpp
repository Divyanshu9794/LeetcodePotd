class Solution {
public:
    int largestVariance(string s) {
       
        vector<int> counters(26,0);
        for(char ch : s)
        {
            counters[ch-'a']++;
        }
int ans=0;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                
                if(i==j || counters[i]==0 || counters[j]==0)
                continue;

                char major='a'+i;
                char minor='a'+j;

                int majorcount=0;
                int minorcount=0;

                int localcount=0;
                int restminor=counters[j];

                for(auto ch :s)
                {
                    if(ch==major)
                    {
                        majorcount++;
                    }
                    if(ch==minor)
                    {
                        minorcount++;
                        restminor--;
                    }

                    localcount=majorcount-minorcount;

                    if(minorcount > 0)
                    {
                        ans=max(ans,localcount);
                    }
                    if(localcount < 0 && restminor>0)
                    {
                        localcount=0;
                        majorcount=0;
                        minorcount=0;
                    }

                  
                }
            }
        }
        return ans;
    }
};
