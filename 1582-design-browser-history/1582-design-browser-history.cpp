class BrowserHistory {
public:
    stack<string> backStack , forwardStack;

    BrowserHistory(string homepage) {
        backStack.push(homepage);
    }
    
    void visit(string url) {
        while(!forwardStack.empty())
            forwardStack.pop();
        backStack.push(url);
    }
    
    string back(int steps) {
        while(backStack.size() > 1 and steps--){
            forwardStack.push(backStack.top());
            backStack.pop();
        }
         return backStack.top();
    }
    
    string forward(int steps) {
        while(!forwardStack.empty() and steps--){
            backStack.push(forwardStack.top());
            forwardStack.pop();
        } 
        
        return backStack.top();
        
    }
};