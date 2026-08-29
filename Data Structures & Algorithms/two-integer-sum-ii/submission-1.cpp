class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int follow = 0;
        int lead = 0;

        for (int i = 0; i < numbers.size(); i++){
            follow = numbers[i];
            for (int j = i; j < numbers.size(); j++){
                lead = numbers[j];
                if (target == (lead + follow)){
                    return {i + 1, j + 1};
                }
            }
        }
        return {};
    }
};
