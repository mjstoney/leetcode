/*

Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

 

Example 1:

Input: x = 121
Output: true

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Example 4:

Input: x = -101
Output: false

 

Constraints:

    -231 <= x <= 231 - 1

 
Follow up: Could you solve it without converting the integer to a string?

*/

#include <iostream>

bool isPalindrome(int x);

int main() {
    std::cout << isPalindrome(121) << std::endl;
    std::cout << isPalindrome(1234567899) << std::endl;





}

bool isPalindrome(int x) {
    int copy = x, digit, reverse = 0;
    
    if (x < 0) {
        return false;
    }

    do {
        digit = copy % 10;
        if (reverse > INT32_MAX / 10) {
            
            return false;
        }
        reverse = (reverse * 10) + digit;
        copy /= 10; 
    } while(copy > 0);
    std::cout << x << "\t" << reverse << std::endl;
    if (x == reverse) {
        return true;
    } else return false;
}