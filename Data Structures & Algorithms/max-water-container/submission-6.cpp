class Solution {
public:
    int maxArea(vector<int>& heights) {
        int marea = 0;
        int l = 0, r = heights.size() - 1;

        while (l < r){
            int area = min(heights[r], heights[l]) * (r-l);
            marea = max(area, marea);

            if (heights[l] <= heights[r]){
                l++;
            } else{
                r--;
            }
            
        }
        return marea;
    }
};
