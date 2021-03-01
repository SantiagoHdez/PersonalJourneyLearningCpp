/*
 * Leetcode Problem N°1
 * Two-Sum
 * First version: 01/03/2021
*/
#include <vector>

using namespace std;

/*
 * SOLUTION TO THE PROBLEM
 */ 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((nums.at(i)+nums.at(j))==target){
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>{};
    }
};