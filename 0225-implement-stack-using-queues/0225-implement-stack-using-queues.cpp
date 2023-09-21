class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        li.push_back(x);
    }

    int pop() {
        int num = li.back();
        li.pop_back();
        return num;
    }

    int top() {
        return li.back();
    }

    bool empty() {
        return !li.size();
    }

    list<int> li;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */