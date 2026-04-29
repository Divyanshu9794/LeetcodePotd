class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        long long x = val;
        if(st.empty()){
            mini = x;
            st.push(x);
        }
        else{
            if(x > mini){
                st.push(x);
            }
            else{
                st.push(2*x - mini);
                mini = x;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        
        long long x = st.top();
        st.pop();
        
        if(x < mini){
            mini = 2*mini - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        
        long long x = st.top();
        if(x > mini) return (int)x;
        return (int)mini;
    }
    
    int getMin() {
        return (int)mini;
    }
};