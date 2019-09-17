// #include <iostream>
// using namespace std;

// struct ListNode{
//     int val;
//     ListNode *next;
//     ListNode (int v=0):val(v),next(NULL){}
// };

// ListNode* reverseList(ListNode **pListhead){
    
//     if(*pListhead==NULL){
//         return NULL;
//     }
//     if((*pListhead)->next==NULL){
//         return *pListhead;
//     }

//     ListNode *preNode =NULL;
//     ListNode *curNode =*pListhead;
//     ListNode *reverseHead =NULL;

//     while(curNode!=NULL){
//         ListNode *nextNode=curNode->next;
//         if(nextNode==NULL)
//         {//如果当前节点下一个节点==NULL的话, 翻转链表头则为当前节点
//             reverseHead=curNode;
//         }
//         //如果当前节点的下一节点不为空
//         curNode->next=preNode;
//         preNode = curNode;
//         curNode = nextNode;
//     }
//     return reverseHead;
// }


// int main(){
//     int a;
//     ListNode *head= new ListNode(0);
//     ListNode *phead=head;
//     for(int i=1;i<10;i++){
//         ListNode *temp =new ListNode(i);
//         phead->next=temp;
//         phead=phead->next;
//     }
//     cout<<"初始链表: ";
//     ListNode *print = head;
//     while(print!= NULL){
//         cout<<print->val<<" ";
//         print=print->next;
//     }
//     cout<<"翻转链表: ";
//     ListNode *rehead=reverseList(&head);
//     while(rehead!=NULL){
//         cout<<rehead->val<<" ";
//         rehead=rehead->next;
//     }
//     cin>>a;
//     return 0;
// }
/*************************************************/
#include <iostream> 
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
};

void MyPrint(ListNode *p){
    while(p!=NULL){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl<<endl;
    return;
}

ListNode* ReverseList(ListNode *phead){
    ListNode *pReversehead = NULL;
    ListNode *pNode = phead;
    ListNode *pPrev = NULL;

    while(pNode!=NULL){
        ListNode *pNext=pNode->next;

        if(pNext==NULL)
        {//如果当前节点的后继为NULL,则是尾节点,即为反转链表的头节点
            pReversehead=pNode;
        }
        //如果不为空,当前结点的后继方向指向前驱节点
        pNode->next=pPrev;
        //指针右移
        pPrev=pNode;
        pNode=pNext;
    }
    return pReversehead;
}

int main(){
    int myarray[]={1};
    int num=sizeof(myarray)/sizeof(int);
   // cout<<"sizeofmyarray "<<num<<endl;
    ListNode *head,*p,*lins,*newHead;
    head=NULL;
    for(int i=0;i<num;i++){
        p = new ListNode;
        p->val=myarray[i];
        p->next=NULL;

        if(head==NULL){//如果这是第一个创建的节点,将头指针指向这个节点
            head=p;
        }
        else
        {
            lins->next=p;//如果这不是第一个创建的节点,则将上一个节点的后继指针指向当前节点
        }
        lins=p;//指针lins也指向当前节点
    }
    cout<<"初始链表: "<<endl;
    MyPrint(head);
    cout<<"反转链表: "<<endl;
    newHead=ReverseList(head);
    MyPrint(newHead);
    cin.get();
    return 0;
}