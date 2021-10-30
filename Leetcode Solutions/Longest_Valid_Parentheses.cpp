//https://leetcode.com/problems/longest-valid-parentheses

int longestValidParentheses(string s) {
        int n = s.length();
        
        int open_ph =0;
        for(int i = n-1; i >=0; --i)
            if(s[i] == ')') ++open_ph;
            else if(open)--open_ph;
                else s[i] =0; //bad open  ()(() => ()x()
            
        open_ph =0;
        int max_ph=0, curr_ph=0;
        
        for(char c :s){
            if(c){// not bad open
                if(c==')'){
                   if(open_ph){
                        ++curr_ph;
                        --open_ph;
                       continue; 
                   }
                }else{
                    ++open_ph;
                    continue;
                }    
            }
            if(curr_ph){// not valid chain
                max_ph = max(max_ph,curr_ph);
                curr_ph = 0;
            }
           
        }
        return max(max_ph,curr_ph)<<1; // *2
    }