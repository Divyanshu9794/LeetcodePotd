class Solution {
public:

#include<limits.h>
#include<queue>
class node{
    public:
        int data;
        int row;
        int col;
        node(int d,int r,int c)
        {
            data=d;
            row=r;
            col=c;
        }
};
class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};



    vector<int> smallestRange(vector<vector<int>>& a) {
        int k = a.size();
        int mini= INT_MAX,maxi=INT_MIN;

        priority_queue<node*,vector<node*>,compare> q;

        for(int i=0;i<k;i++){
            int ele = a[i][0];
            mini = min(mini,ele);
            maxi=max(maxi,ele);
            q.push(new node(ele,i,0));
        }

        int start=mini,end = maxi;
        while(!q.empty()){
            node* temp=q.top();
            q.pop();
            mini=temp->data;
            if(maxi-mini < end-start){
                start=mini;
                end=maxi;
            }


            if(temp->col+1<a[temp->row].size()){
                maxi=max(maxi,a[temp->row][temp->col+1]);
                q.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));
            }
            else{

                break;
            }


        }
            return {start,end};
        
    }
};