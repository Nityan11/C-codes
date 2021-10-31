using namespace std;

#include <iostream>
#include <limits>
#include <vector>
#include <climits>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int i= 0, j = 0;
    int minl = INT_MAX;
    int sum = 0;
    while(j<arr.size()) {
      sum = sum + arr[j];
      if(sum<S) {
        j++;
      }
      else {
        minl = min(minl,j-i+1);
        sum = sum - arr[i] - arr[j];
        i++;

      }
    }
    return minl;
  }
};