/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

 

Constraints:

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lower-case English letters.

*/

#include <iostream>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs);

int main() {
std::vector<std::string> strs1 = {"ab", "a"}; //, "staopi", "staapoiddoi"};
std::cout << longestCommonPrefix(strs1);
}

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.size() == 1) {
        return strs[0];
    }
    std::string s = strs[0];
    int len = s.length();
    std::string prefix;
    for (int i = 1; i < len; i++) {
        prefix = s.substr(0, i);
        std::cout << prefix << std::endl;
        for (std::string str : strs) {
            if (str.substr(0, i).compare(prefix) != 0) {
                return prefix.substr(0, i);
            }
        }
    }

    return "";
}