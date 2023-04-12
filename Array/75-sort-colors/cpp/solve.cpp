class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int len = nums.size();
        int zeroIdx = 0, oneIdx = 0, twoIdx = len - 1;
        
        while(oneIdx <= twoIdx){
            const int val = nums[oneIdx];
            if(val == 0){
                swap(nums[oneIdx], nums[zeroIdx]);
                zeroIdx++;

                // NOTE: THE REASON I DON'T NEED IT IS BECAUSE THERE WONT BE ANY 2, IF IT WERE, IT WOULD HAVE BEEN EXCHANGED 
                // if(oneIdx < zeroIdx){
                    oneIdx++;
                // }
            }else if(val == 2){
                swap(nums[oneIdx], nums[twoIdx]);
                twoIdx--;
            }else{
                oneIdx++;
            }
        }
    }
};