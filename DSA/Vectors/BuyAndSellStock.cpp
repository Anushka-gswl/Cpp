#include <iostream>
#include <vector>
using namespace std;

//Brute Force
int maxProfit(vector<int> prices){
    int mp = 0;
    int bestBuy = prices[0];
    for(int i = 1; i < prices.size(); i++){
        if( prices[i] > bestBuy){
            mp = max(mp, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return mp;
}

int main(){
    int n;
    cout<<"Enter size of Prices array: ";
    cin>>n;
    vector<int> prices(n);
    cout<<"Enter values in array:\n";
    for(int i = 0; i < n; i++){
        cin>>prices[i];
    }
    int mp = maxProfit(prices);
    cout<<"Maximum profit is: "<<mp;
    return 0;
}