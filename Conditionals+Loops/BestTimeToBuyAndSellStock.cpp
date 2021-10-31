#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        int sell = INT_MIN;
        for(int i = 0; i<prices.size(); i++){
            if(prices[i]<buy){
                buy = prices[i];
            }
            if(prices[i]-buy > profit){
                profit = prices[i] - buy;
            }
        }
        return profit;
        
    }
};