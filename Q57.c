/*Q:Mirror binary tree
Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively*/

#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left,*right; };

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->left=n->right=NULL; return n; }

struct Node* buildTree(int arr[], int n){
    struct Node* nodes[n]; for(int i=0;i<n;i++) nodes[i]=arr[i]==-1?NULL:newNode(arr[i]);
    for(int i=0,j=1;j<n;i++){ if(nodes[i]){ if(j<n) nodes[i]->left=nodes[j++]; if(j<n) nodes[i]->right=nodes[j++]; } }
    return nodes[0];
}

void mirror(struct Node* root){ if(!root) return; struct Node* t=root->left; root->left=root->right; root->right=t; mirror(root->left); mirror(root->right); }

void inorder(struct Node* root){ if(!root) return; inorder(root->left); printf("%d ",root->data); inorder(root->right); }

int main(){
    int n; scanf("%d",&n); int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    struct Node* root=buildTree(arr,n);
    mirror(root);
    inorder(root);
    return 0;
}
