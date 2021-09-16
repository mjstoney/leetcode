/*

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Example 4:

Input: s = "([)]"
Output: false

Example 5:

Input: s = "{[]}"
Output: true

 

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.

*/

#include <iostream>
#include <stack>

bool isValid(std::string s); 

int main() {
    std::string str1 = "([{}])";
    std::string str2 = "()[]{}";
    std::string str3 = "{)}";

    std::cout << isValid(str1);
    std::cout << isValid(str2);
    std::cout << isValid(str3);
}

bool isValid(std::string s) {
    std::stack<char> st;

    if (s.length() % 2 != 0) return false;

    for(char ch : s) {
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
            continue;
        }
        if((ch == ')' && st.top() != '(') || (ch == '}' && st.top() != '{') || (ch == ']' && st.top() != '[')) {
            return false;
        }
        st.pop();
    }
    return st.empty();

}