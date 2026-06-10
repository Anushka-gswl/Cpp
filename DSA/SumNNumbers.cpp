#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int sum = 0, oddSum = 0, evenSum = 0;

    for(int i=1; i<=n; i++) {
        sum+=i;
        if(i%2==0){
            evenSum+=i;
        } else{
            oddSum+=i;
        }
    }

    int j=1, sum1=0, evenSum1=0, oddSum1=0;
     while(j<=n){
        sum1+=j;
        if(j%2==0){
            evenSum1 += j;
        } else{
            oddSum1 += j;
        }
        j++;
     }
    
    cout<<sum<<'\n'<<oddSum<<'\n'<<evenSum<<'\n';
    cout<<sum1<<'\n'<<oddSum1<<'\n'<<evenSum1;
    return 0;
}