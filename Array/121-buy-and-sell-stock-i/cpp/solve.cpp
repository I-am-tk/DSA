class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minSoFar = prices[0];
        for(auto price: prices){
            profit = max(profit, price - minSoFar);
            minSoFar = min(minSoFar, price);          
        }
        return profit;
    }
};