/*
Longest Substring with maximum K Distinct Characters
https://www.educative.io/courses/grokking-the-coding-interview/YQQwQMWLx80
*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    int start = 0; int end;
    int rep = 0;
    unordered_map <char, int> mark;
    for(end = 0; end<str.size(); end++) {
      if(mark[str[end]]>0){
        mark[str[end]]++;
      }
      else if(mark[str[end]]==0) {
        if(rep<k) {
          mark[str[end]] = 1;
          rep++;
        }
        else {
          maxLength = max(maxLength,end-start);
          while(rep>=k) {
            mark[str[start]]--;
            if(mark[str[start]] == 0){
              rep--;
            }
            start++;
            end--;
          }
        }
      }
    }
    return maxLength;
  }
};