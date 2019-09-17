#include <iostream> 
#include <vector>

using namespace std;
/*用时44ms*/
class Solution{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c){
        int a=nums.size();
        int b=nums[0].size();//列数
        if(a*b!=r*c){
            return nums;
        }
        vector<vector<int>> res (r,vector<int>(c));
        for(int i=0;i<a*b;i++){
            res[i/c][i%c]=nums[i/b][i%b];
        }
        return res;
    }
};

// class Solution{
// public:
//     vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c){
//         int x=nums.size();
//         int y=nums[0].size();

//         if(x*y!=r*c){
//             return nums;
//         }
//         vector<vector<int>> res(r,vector<int>(c));
//         for(int i = 0; i<x; i++){
//             for(int j = 0; j<y; j++){
//                 int temp = i*y+j;
//                 int m =temp/c;
//                 int n =temp%c;
//                 res[m][n]=nums[i][j];
//             }
//         }
//         return res;
//     }
// };

int main()
{
    Solution way;
}