class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, profit = 0;
        for (int r = 0; r < prices.size(); r++){
            if (prices[r] > prices[l]){
                int day = prices[r] - prices[l];
                profit = max(profit, day);
            } else {
                l = r;
            }

        }
        return profit;
    }
};
