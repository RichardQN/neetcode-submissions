class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int l = 0, r = 1;
        while (r < prices.size()){
            if (prices[r] > prices[l]){
                int day = prices[r] - prices[l];
                profit = max(day, profit);
            } else {
                l = r;
            }
            r++;

        }
        return profit;
    }
};
