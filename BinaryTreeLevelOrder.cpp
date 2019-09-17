//#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <queue>
#include <vector>
#include <stack>

using namespace std;
#define TElemType int;

struct TreeNode
{
    int val; //数据
    struct TreeNode *lchild, *rchild;
    //TreeNode(int x):val(x),lchild(NULL),rchild(NULL){}
};

TreeNode *CreatTree()
{
    int ch;
    TreeNode *t;
    cin >> ch;
    if (ch == 0)
    {
        t = NULL;
    }
    else
    {
        t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        t->val = ch;
        t->lchild = CreatTree();
        t->rchild = CreatTree();
    }
    return t;
}

void pre_display(TreeNode *head)
{
    if (head)
    {
        cout << head->val << " ";
        pre_display(head->lchild);
        pre_display(head->rchild);
    }
}

void preorder_display(TreeNode *head)
{
    //如果传入的节点为空, 则返回
    if (head == NULL)
    {
        return;
    }
    //声明一个TreeNode类型的栈
    stack<TreeNode *> s;
    //节点入栈
    s.push(head);
    //如果栈不为空
    while (s.empty() == false)
    {
        //弹出当前节点
        head = s.top();
        cout << head->val << " ";
        s.pop();
        //如果有 右孩子
        if (head->rchild != NULL)
        {
            s.push(head->rchild);
        }
        //如果有 左孩子
        if (head->lchild != NULL)
        {
            s.push(head->lchild);
        }
    }
}

void in_display(TreeNode *head)
{
    if (head)
    {
        in_display(head->lchild);
        cout << head->val << " ";
        in_display(head->rchild);
    }
}

void inorder_displayer(TreeNode *head)
{
    if (head == NULL)
    {
        return;
    }
    stack<TreeNode *> s;
    while (s.empty() == false || head != NULL)
    {
        while (head != NULL)
        {
            s.push(head);
            head = head->lchild;
        }
        head = s.top();
        cout << head->val << " ";
        s.pop();
        head = head->rchild;
    }
}

void post_display(TreeNode* head){
    if(head==NULL){
        return;
    }
    post_display(head->lchild);
    post_display(head->rchild);
    cout<<head->val<<" ";
}

void postorder_display(TreeNode* head){
    cout<<"postorder:"<<endl;
    if(head==NULL){
        return;
    }
    stack <TreeNode* > s1;
    stack <TreeNode* > s2;
    //根节点入栈1
    s1.push(head);

    //
    while(!s1.empty()){
        head=s1.top();
        s2.push(head);
        s1.pop();
        if(head->lchild!=NULL){
            s1.push(head->lchild);
        }
        if(head->rchild!=NULL){
            s1.push(head->rchild);
        }
    }
   // cout<<"s2 size: "<<s2.size()<<endl;
    while(!s2.empty()){
        cout<<s2.top()->val<<"- ";
        s2.pop();
    }
}

/*层次遍历*/
void BinaryTreeLevelOrder(TreeNode *T)
{
    if (T == NULL)
        return;
    TreeNode *temp;
    queue<TreeNode *> q;
    q.push(T);
    while (q.empty() == false)
    {                             //队列不为空, 返回false
        temp = q.front();         //取队头
        cout << temp->val << " "; //打印队头的值
        if (temp->lchild)
        {
            q.push(temp->lchild);
        }
        if (temp->rchild)
        {
            q.push(temp->rchild);
        }
        q.pop();
    }
}

int main()
{
    TreeNode *head;
    TreeNode *p;
    head = NULL;
    p = CreatTree();
    pre_display(p);
    cout << endl
         << "feidigui: ";
    preorder_display(p);
    cout << endl;
    in_display(p);
    cout << endl;
    inorder_displayer(p);
    cout << endl;
    post_display(p);
    cout << endl;
    postorder_display(p);
    cout << endl
         << "LevelOrder: ";
    BinaryTreeLevelOrder(p);
    cin.get();
    return 0;
}

void postorder_display(TreeNode* head){
    cout<<"postorder:"<<endl;
    if(head==NULL){
        return;
    }
    stack <TreeNode* > s1;
    stack <TreeNode* > s2;
    //根节点入栈1
    s1.push(head);

    //
    while(!s1.empty()){
        head=s1.top();
        s2.push(head);
        s1.pop();
        if(head->lchild!=NULL){
            s1.push(head->lchild);
        }
        if(head->rchild!=NULL){
            s1.push(head->rchild);
        }
    }
   // cout<<"s2 size: "<<s2.size()<<endl;
    while(!s2.empty()){
        cout<<s2.top()->val<<"- ";
        s2.pop();
    }
}


void postorder(TreeNode* head){
    if(head==NULL){
        return;
    }
    stack <TreeNode*> s1;
    stack <TreeNode*> s2;

    s1.push(head);
    while(!s1.empty()){
        head=s1.top();
        s1.pop();
        s2.push(head);

        if(head->lchild!=NULL){
            s1.push(head->lchild);
        }
        if(head->rchild!=NULL){
            s1.push(head->rchild);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->val<<" ";
        s2.pop();
    }
    return;
}