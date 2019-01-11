class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        data.push(x);
        if(!minimum.empty())
            minimum.push(min(x,minimum.top()));
        else
            minimum.push(x);
    }
    
    void pop() {
        data.pop();
        minimum.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minimum.top();        
    }
    
private:
    
    stack<int> data,minimum;
};
