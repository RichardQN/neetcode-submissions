class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = l + 1;
        int profit = 0;
        while (r < prices.size()){
            if (prices[l] < prices[r]){
                int day_profit = prices[r] - prices[l];
                profit = max(profit, day_profit);
            } else {
                l = r;
            }
            r++;
            

        }
        return profit;
    }
};
