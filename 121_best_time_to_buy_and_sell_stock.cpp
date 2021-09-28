/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different 
day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

 

Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104
U: input is array of ints, length 1->105, values 1->104
M: matches with two pointer problems?
P: front and back index move inward: front = buy, back = sell
    back decreases to find MAX for front value
I
R
E

*/

#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
    int front = 0;
    int back = prices.size() - 1;
    int profit = 0;
    int min_front = prices[0];
    int max_back = prices[prices.size() - 1];

    while(front < back) {
        if(prices[front] < min_front) min_front = prices[front];
        if(prices[back] > max_back) max_back = prices[back];
        front++;
        back--;
    }
    profit = max_back - min_front;
    return profit > 0 ? profit : 0;
}


int main() {
    std::vector<int> prices{ 7,1,5,3,6,4 };
    std::cout << maxProfit(prices);
}