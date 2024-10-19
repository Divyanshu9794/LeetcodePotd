class Solution {
public:
    string invert(int n,string temp){
        string newtemp="";
        for(int i=0;i<=n;i++){
            if(temp[i]=='1')
            newtemp+='0';
            else
            newtemp+='1';
        }

        return newtemp;
    }
    char findKthBit(int n, int k) {

        string temp="0";

        for(int i=0;i<n;i++){
            temp=temp+"1";
            int ind=temp.length()-2;
            string inverted=invert(ind,temp);
            reverse(inverted.begin(),inverted.end());
            temp=temp+inverted;
        }

        //cout<<temp<<endl;

        return temp[k-1];
        
    }
};