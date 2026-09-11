class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int marea = 0;
        while (l < r){
            int area = min(heights[l], heights[r]) * (r-l);
            marea = max(marea, area);

            if (heights[l] <= heights[r]){
                l++;
            } else{
                r--;
            }
        }
        return marea;
    }
};
