class MinStack {
public:
    stack<long long> s;
    long long mini;

    MinStack() {
        mini = 0;
    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            mini = val;
        } 
        else if (val < mini) {
            s.push(2LL * val - mini);  
            mini = val;
        } 
        else {
            s.push(val);
        }
    }

    void pop() {
        if (s.empty()) return;

        long long curr = s.top();
        s.pop();

        if (curr < mini) {
            mini = 2 * mini - curr;   
        }

        if (s.empty()) {
            mini = 0;               
        }
    }

    int top() {
        if (s.empty()) return -1;

        long long curr = s.top();
        if (curr < mini)
            return (int)mini;
        return (int)curr;
    }

    int getMin() {
        if (s.empty()) return -1;
        return (int)mini;
    }
};
