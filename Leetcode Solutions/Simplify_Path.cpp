//https://leetcode.com/problems/simplify-path

class Solution {
    string makePathFromTokens(const vector<string> &tokens) {
        string path = "/";
        for(size_t i = 0; i < tokens.size(); ++i) {
            path += tokens[i];
            if(i != tokens.size() - 1)
                path += '/';
        }
        return path;
    }
    vector<string> buildTokens(const string &path) {
        vector<string> tokens;
        string token;
        
        auto processToken = [&token, &tokens](){
            if(token != "") {
                if(token != "..") {
                    if(token != ".") {
                        tokens.push_back(move(token));
                    }
                } else {
                    if(!tokens.empty()) {
                        tokens.pop_back();
                    }
                }
                token = "";
            }
        };
        
        for(char c : path) {
            if(c == '/') {
                processToken();
            } else {
                token += c;
            }
        }
        
        processToken();
        return tokens;        
    }
public:
    string simplifyPath(string path) {
        return makePathFromTokens(buildTokens(path));
    }
};