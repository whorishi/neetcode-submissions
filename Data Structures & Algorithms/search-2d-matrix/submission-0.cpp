class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int start=0, end=(m*n)-1;

        while(start<=end){
            int mid = start + (end-start)/2;

            int ele = matrix[mid/n][mid%n];

            if(ele==target) return true;
            else if(ele>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return false;
    }
};



// first /n -> 8/4 -> 2nd row -> rem->0 i.e 0th index  2,0

