class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int rowIdx = 1; rowIdx <= numRows; rowIdx++){
            vector<int> newRow;
            if(!ans.empty()){
                const int ansLen = ans.size();
                const vector<int>& lastRow = ans[ansLen - 1];
                newRow = lastRow;

                const int lastRowLen = lastRow.size();
                for(int lastRowIdx = 1; lastRowIdx < lastRowLen; lastRowIdx++){
                    const int rowVal = lastRow[lastRowIdx] + lastRow[lastRowIdx - 1];
                    newRow[lastRowIdx] = rowVal; 
                }
            }
            newRow.push_back(1);

            ans.push_back(newRow);
        }
        return ans;
    }
};