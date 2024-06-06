class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int > mp;
        int n = hand.size();

        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        for(auto it = mp.begin();it!=mp.end();){
            if(it->second > 0){
                for(int i=0 ;i<groupSize;i++){
                    if(mp[it->first+i]>0){
                        mp[it->first+i]--;
                    }
                    else{
                        return false;
                    }
                }
                
            }
            else{
                    it++;
                }
        }
        return true;
    }
};