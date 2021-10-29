//Problem Link - https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, ans, 1, 0, "(");
        return ans;
    }
    void solve(int n, vector<string>& ans, int open, int close, string curr){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            solve(n, ans, open+1, close, curr+"(");
        }
        if(close<open){
            solve(n, ans, open, close+1, curr+")");
        }
    }
};
