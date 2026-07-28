#include<iostream>
using namespace std;
struct node{
    char info;
    struct node *next;
};
node *start=NULL;
node *GetNode(){
    node *p;
    p=(node*)malloc(sizeof(struct node));
    return p;
}
void InsBeg(char x)
{
    node *p;
    p=GetNode();
    p->info=x;
    p->next=start;
    start=p;
}
void InsEnd(char x){
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
int CountNodes(){
    node *tmp;
    tmp=start;
    int count=0;
    while(tmp!=NULL){
        count++;
        tmp=tmp->next;
    }
    return count;
}
int main(){
    start=NULL;
    InsBeg('A');
    InsBeg('B');
    InsBeg('C');
    InsBeg('D');
    InsBeg('E');
    InsEnd('X');
    InsEnd('Y');
    InsEnd('Z');
    Traverse();
    int count=CountNodes();
    cout<<"\n"<<count;
    return 0;
}