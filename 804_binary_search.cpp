/*

704. Binary Search
Easy

Given an array of integers nums which is sorted in ascending order, and an integer target, 
write a function to search target in nums. If target exists, then return its index. 
Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

 

Constraints:

    1 <= nums.length <= 104
    -104 < nums[i], target < 104
    All the integers in nums are unique.
    nums is sorted in ascending order.

*/

// UMPIRE
/*
U:  input: int array nums, sorted ascending order
    input: int target
    
    return: if target in nums: index of target in nums
    return: if target not in nums: -1
    
    Must be in O(log n) runtime -> binary search
    
M:  divide and conquer algorithms

P:  nums is sorted in ascending order, split array in two:
        find the middle element, mid
        If target is less than mid
            target is on left split
            split the left side 
        else 
            target is on right split
            split right side
            
*/

#include <iostream>
#include <vector>

using namespace std;
/*
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid = (right - left) / 2;

    while(true) {
        if (right - left <= 1) {
            if(nums[left] == target) {
                return left;
            } else if (nums[right] == target) {
                return right;
            } else return -1;
        }
        if(target == nums[mid] ) {
            return mid;
        } else if (target < nums[mid]) {
            right = mid;
            mid = (right - left) / 2;
        } else if (target > nums[mid]) {
            left = mid;
            mid = mid + (right - left) / 2;
        } 

    }
    return -1;
}
*/

// FASTR
int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int mid = 0;
    while(l <= r )
    {
        mid = (l + r)/2;
        
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    
    return -1;
}
int main() {
    // EX 10           0 1 2 3 4  5
    // Input: nums = [-1,0,3,5,9,12], target = 9
    // Output: 4

    vector<int> nums {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int k = search(nums, target);
    cout << "k: " << k << endl;

    k = search(nums, 2);
    cout << "k: " << k << endl;
}