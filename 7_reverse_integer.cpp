/*

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

Example 4:

Input: x = 0
Output: 0

 

Constraints:

    -231 <= x <= 231 - 1

*/

#include <iostream>
#include <algorithm>

int reverse(int x);

int main() {

    int num1 = 123, num2 = -123, num3 = 120, num4 = 1534236469;
    std::cout << reverse(num1) << std::endl;
    std::cout << reverse(num2) << std::endl;
    std::cout << reverse(num3) << std::endl;
    std::cout << reverse(num4) << std::endl;
    return 0;
}

int reverse(int x) {
    int sign = 1;
    int result;
    if (x < 0) {
        sign = -1;
    }

    auto s = std::to_string(x);
    reverse(s.begin(), s.end());


    try {
        return sign * stoi(s);
    } catch (const std::out_of_range& oor) {
        return 0;
    }

}
