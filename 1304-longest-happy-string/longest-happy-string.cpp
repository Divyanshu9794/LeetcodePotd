class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> tmp(3);
        tmp.push_back({a, 'a'});
        tmp.push_back({b, 'b'});
        tmp.push_back({c, 'c'});

        string ans = "";
        int cnt = 0;
        char pre = '*';
        while(true){
            sort(tmp.rbegin(), tmp.rend());
            if(cnt<2 && tmp[0].first>0){
                if(tmp[0].second != pre){
                    pre = tmp[0].second;
                    cnt = 1;
                }
                else{
                    cnt += 1;
                }
                tmp[0].first--;

                ans += tmp[0].second;
            }
            else {
                if(tmp[0].second != pre && tmp[0].first > 0){
                    pre = tmp[0].second;
                    cnt = 1;

                    tmp[0].first--;

                    ans += tmp[0].second; 
                }
                else if(tmp[1].first > 0){
                    pre = tmp[1].second;
                    cnt = 1;

                    tmp[1].first--;

                    ans += tmp[1].second;
                }
                else{
                    break;
                }
            }
        }

        return ans;
    }
};