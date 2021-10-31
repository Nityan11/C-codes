#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> brackets;
        int flag = 0;
        for(int i = 0; i<s.size(); i++) {
            
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                brackets.push(s[i]);
            }
            else if(!brackets.empty()) {
                if(s[i] == ')' && brackets.top() == '('){
                    flag = 1;
                    brackets.pop();
                }
                else if(s[i] == '}' && brackets.top() == '{'){
                    flag = 1;
                    brackets.pop();
                    
                }
                else if(s[i] == ']' && brackets.top() == '['){
                    flag = 1;
                    brackets.pop();
                }
                else{
                brackets.push(s[i]);
            }
            }
            else{
                brackets.push(s[i]);
            }
        }
        if(flag==1 && brackets.empty()){
            return true;
        }
        return false;
    }
};