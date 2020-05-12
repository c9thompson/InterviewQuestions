/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.
*/

class stackNode{
public:
    stackNode(int val, stackNode* next) : val_(val), next_(next) {
        if(next_)
            currMin_ = (val_ < next_->getCurrMin()) ? val : next_->getCurrMin();
        else
            currMin_ = val;
    }
    
    int getVal() { return val_; }
    int getCurrMin() { return currMin_; }
    stackNode* getNext() { return next_; }
    
private:
    int val_;
    int currMin_;
    stackNode* next_;
};

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() : first(NULL) {}
    
    void push(int x) {
        stackNode* tmp = first;
        first = new stackNode(x, tmp);
    }
    
    void pop() {
        if(first){
            stackNode* tmp = first->getNext();
            delete first;
            first = tmp;
        } 
    }
    
    int top() {
        if(first)
            return first->getVal();
        else
            return INT_MIN;
    }
    
    int getMin() {
        if(first)
            return first->getCurrMin();
        else
            return INT_MAX;
    }
    
private:
    stackNode* first;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */