/*Q:Symmetric binary tree check
Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree*/

#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left,*right; };

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->left=n->right=NULL; return n; }

int isMirror(struct Node* a, struct Node* b){
    if(!a && !b) return 1;
    if(!a || !b) return 0;
    return (a->data==b->data) && isMirror(a->left,b->right) && isMirror(a->right,b->left);
}

int main(){
    int n; scanf("%d",&n); int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    struct Node* nodes[n]; for(int i=0;i<n;i++) nodes[i]=arr[i]==-1?NULL:newNode(arr[i]);
    for(int i=0,j=1;j<n;i++){ if(nodes[i]){ if(j<n) nodes[i]->left=nodes[j++]; if(j<n) nodes[i]->right=nodes[j++]; } }
    printf("%s",isMirror(nodes[0]->left,nodes[0]->right)?"YES":"NO");
    return 0;
}