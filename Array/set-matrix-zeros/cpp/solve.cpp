#include <bits/stdc++.h>

using namespace std;

// NOTE: IN PLACE
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // FIRST I NEED TO MARK SO THAT LATER I CAN CHANGE THE VALUES BASED ON IT
        // IF I FOUND A ZERO IN A COLUMN OR IN A ROW I CAN SET 0 TO ONE CELL IN THE ROW
        
        int row_len = matrix.size();
        int col_len = matrix[0].size();

        bool should_first_row_zero = false;
        bool should_first_col_zero = false;


        for(int row_idx = 0; row_idx < row_len; row_idx++){
            for(int col_idx = 0; col_idx < col_len; col_idx++){
                const int cell_val = matrix[row_idx][col_idx];
                if(cell_val == 0){
                    // JUST BY THIS WON'T BE ABLE TO DIFFERENTIATE FOR (0,0), WETHER ROW NEED TO BE 0 OR COLUMNS
                    matrix[0][col_idx] = 0;
                    matrix[row_idx][0] = 0;

                    if(row_idx == 0){
                        should_first_row_zero = true;
                    }
                    if(col_idx == 0){
                        should_first_col_zero = true;
                    }
                }
            }
        }

        // SETTING ZEROS FOR ALL ELEMENT EXCEPT THE FIRST ROW AND COLUMN
        for(int row_idx = 1; row_idx < row_len; row_idx++){
            for(int col_idx = 1; col_idx < col_len; col_idx++){
                if(matrix[0][col_idx] == 0 || matrix[row_idx][0]){
                    matrix[row_idx][col_idx] = 0;
                }
            }
        }

        // SETTING ZEROS FOR THE FIRST COLUMN
        for(int row_idx = 0; row_idx < row_len; row_idx++){
            if(should_first_col_zero){
                matrix[row_idx][0] = 0;
            }
        }

        // SETTING ZEROS FOR THE FIRST ROW
        for(int col_idx = 0; col_idx < col_len; col_idx++){
            if(should_first_row_zero){
                matrix[col_idx][0] = 0;
            }
        }
    }
};
int main(){
    return 0;
}

// if(row_idx == 0 && should_first_row_zero) {
//                     matrix[row_idx][col_idx] =  0;
//                 }else if(col_idx == 0 && should_first_col_zero){
//                     matrix[row_idx][col_idx] = 0;
//                 }