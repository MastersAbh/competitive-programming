#include<bits/stdc++.h>
using namespace std;

struct node { 
    int data; 
    node *left;
    node* right; 
}; 

void printLeaves(node* root) 
{ 
    if (root == NULL) 
        return; 

    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    } 
    printLeaves(root->left);
    printLeaves(root->right);
} 

void printBoundaryLeft(node* root) 
{ 
    if (root == NULL) 
        return; 

    if (root->left != NULL) { 
        cout<<root->data<<" ";
        printBoundaryLeft(root->left); 
    } 
    else if (root->right != NULL) { 
        printf("%d ", root->data); 
        printBoundaryLeft(root->right); 
    } 
} 

void printBoundaryRight(node* root) 
{ 
    if (root == NULL) 
        return; 

    if (root->right != NULL) { 
        printBoundaryRight(root->right); 
        cout<<root->data<<" ";
    } 
    else if (root->left != NULL) { 
        printBoundaryRight(root->left); 
        cout<<root->data<<" ";
    }  
} 

void printBoundary(node* root) 
{ 
    if (root == NULL) 
        return; 

    cout<<root->data<<" ";

    printBoundaryLeft(root->left); 
    printLeaves(root);
    printBoundaryRight(root->right); 
} 

node* newNode(int data) 
{ 
    node* temp = new node(); 

    temp->data = data; 
    temp->left = temp->right = NULL; 

    return temp; 
} 

int main() 
{  
    node* root = newNode(20); 
    root->left = newNode(8); 
    root->left->left = newNode(4); 
    root->left->right = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
    root->right = newNode(22); 
    root->right->right = newNode(25); 

    printBoundary(root); 

    return 0; 
} 
