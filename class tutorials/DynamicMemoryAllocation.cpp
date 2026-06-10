#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
    int *y;
    int n;
    cin>>n;
    y=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        cin>>*(y+i);
    }
    for(int i=0;i<n;i++)
    {
        cout<<*(y+i)<<" ";
    }
    return 0;
}