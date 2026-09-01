class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = l + 1;
        int profit = 0;
        while (r < prices.size()){
            if (prices[r] > prices[l]){
                int day = prices[r] - prices[l];
                profit = max(profit, day);
            } else {
                l = r;
            }
            r++;
        }
        return profit;
    }
};
