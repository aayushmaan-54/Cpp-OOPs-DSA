// question - Given an array where each element represents the stock price on a particular day, find the maximum profit you can achieve. You can only complete one transaction (buy once and sell once).

#include <iostream>
#include <climits> 
using namespace std;

int maxProfit(int prices[], int size) {
  if (size == 0) return 0;
    
  int minPrice = INT_MAX; 
  int maxProfit = 0;
    
  for (int i = 0; i < size; i++) {
    if (prices[i] < minPrice) {
      minPrice = prices[i];
    } else if (prices[i] - minPrice > maxProfit) {
      maxProfit = prices[i] - minPrice;
    }
  }
    
  return maxProfit;
}

int main() {
  int prices[] = {7, 1, 5, 3, 6, 4};
  int size = sizeof(prices) / sizeof(prices[0]);
    
  int profit = maxProfit(prices, size);
  cout << "Maximum profit: " << profit << endl;
    
  return 0;
}
