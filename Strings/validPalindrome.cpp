#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

class Solution {
public:
    /*string correct(string s){ //caused TLE
        string str = "";
        for(int i = 0; i<s.size(); i++){
            if(isupper(s[i])){
                s[i] = tolower(s[i]);
            }
            if(s[i]>=48 && s[i]<=57 || s[i]>=97 && s[i]<=122){
                str = str + s[i];
            }
        }
        //cout<<str<<endl;
        return str;
    }*/

    //isalnum() functions returns a non zero integer if the character is alphanumeric
    bool isPalindrome(string s) {
        
        if(s.size() <=1){
            return true;
        }
        
        int i = 0;
        int j = s.size()-1;
        while(i<j){
           if(!isalnum(s[i])){
               i++;
           }
            else if(!isalnum(s[j])){
                j--;
            }
            else if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            else{
                cout<<s[i];
                i++;
                j--;
            }
        }
        return true;
    }
};