//Top View of a Tree
#include <bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
#define mkp make_pair

struct Node{
    ll data;
    ll hd;
    Node * left,*right; 
    Node(ll val)
    {
        data=val;
        hd=INT_MAX;
        left=NULL;
        right=NULL;
    }
};

void topView(Node* root)
{
    if (root==NULL) {
        return;
    }
    map<ll,ll> mp;
    ll hd = 0;
    queue<Node*> q;
    q.push(root);
    root->hd = 0;
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        hd = temp->hd;
        if (mp[hd] == 0) {
            mp[hd] = temp->data;  
        }      
        if (temp->left != NULL) {
            temp->left->hd=hd-1;
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            temp->right->hd=hd+1;
            q.push(temp->right);
        } 
     }
    map<ll,ll>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
        cout << it->second << " ";
 }

int main()
{
    faster
    Node *root=new Node(20);
    root->left=new Node(8);
    root->right=new Node(22);
    root->left->left=new Node(5);
    root->left->right=new Node(3);
    root->right->left=new Node(4);
    root->right->right=new Node(25);
    root->left->right->left=new Node(10);
    root->left->right->right=new Node(14);
    topView(root);
    return 0;
}

/*
Output:
5 8 20 22 25 
*/
