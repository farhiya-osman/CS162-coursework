#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool containsDuplicate (vector<int>& nums){
	//Type your answer here:
	for(int i = 0; i< nums.size(); i++){
		for(int j = i+1; j<nums.size(); j++){
			if(nums[i] == nums[j]){
				return true; 
			}  
	 	}
	}
	return false;
}