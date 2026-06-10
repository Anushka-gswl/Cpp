#include<iostream>
using namespace std;
struct node{
    int info;
    struct node *next;
};
node *start=NULL;
node *GetNode(){
    node *p;
    p=(node*)malloc(sizeof(struct node));
    return p;
}
void InsBeg(int x)
{
    node *p;
    p=GetNode();
    p->info=x;
    p->next=start;
    start=p;
}
void InsEnd(int x){
    node *p, *tmp;
    p=GetNode();
    p->info=x;
    p->next=NULL;
    tmp=start;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=p;
}
void Traverse(){
    node *tmp;
    tmp=start;
    while(tmp!=NULL)
    {
        cout<<tmp->info<<" ";
        tmp=tmp->next;
    }
}
void CountNodes(){
    node *tmp;
    tmp=start;
    int ecount=0, ocount=0;
    while(tmp!=NULL){
        if((tmp->info)%2==0)
        {
            ecount++;
        }
        else{
            ocount++;
        }
        tmp=tmp->next;
    }
    cout<<"\n"<<"Number of even data nodes: "<<ecount<<"\n";
    cout<<"Number of odd data nodes: "<<ocount<<"\n";
}
int main(){
    start=NULL;
    InsBeg(1);
    InsBeg(2);
    InsBeg(3);
    InsBeg(4);
    InsBeg(5);
    InsEnd(6);
    InsEnd(7);
    InsEnd(8);
    Traverse();
    CountNodes();
    return 0;
}