class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++){
            int m = 0;
            for (int j = i + 1; j < arr.size(); j++){
                m = max(m, arr[j]);
            }
            arr[i] = m;

        }
        int end = arr.size() - 1;
        arr[end] = -1;
        return arr;

        






    }
};