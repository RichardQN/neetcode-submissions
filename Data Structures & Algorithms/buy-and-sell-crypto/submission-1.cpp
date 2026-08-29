class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for (int j = 0; j < size(prices); j++){
            for (int i = j + 1; i < size(prices); i++){
                int temp = prices[i] - prices[j];
                max = (temp > max) ? temp : max;
            }
        }
        return max;
    }
};
