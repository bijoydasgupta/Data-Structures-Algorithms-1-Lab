#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k): key(k), left(nullptr), right(nullptr){}
};

Node* insertNode(Node* root, int key)
{
    if(root==nullptr) return new Node(key);
    if(key<root->key) root->left=insertNode(root->left, key);
    else if(key>root->key) root->right=insertNode(root->right, key);

    return root;
}

Node* minValueNode(Node* node)
{
    Node* cur=node;
    while(cur!=nullptr && cur->left!=nullptr)
    {
        cur=cur->left;
    }
    return cur;
}

Node* deleteNode(Node* root, int key)
{
    if(root==nullptr) return nullptr;
    if(key<root->key)
    {
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->key)
    {
        root->right=deleteNode(root->right,key);
    }
    else
    {
        if(root->left==nullptr)
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==nullptr)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *inorderSucc=minValueNode(root->right);
            root->key=inorderSucc->key;
            root->right=deleteNode(root->right, inorderSucc->key);
        }
    }
}

bool searchNode(Node* root, int key)
{
    if (root==nullptr) return false;
    if(root->key==key) return true;
    else if(key<root->key) return searchNode(root->left,key);
    else return searchNode(root->right, key);
}

void inorder(Node* root)
{
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if(!root) return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
}

int main()
{
    Node* root=nullptr;
    while(true)
    {
        cout<<"\nBST Menu:\n";
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Inorder Traversal"<<endl;
        cout<<"5. Preorder Traversal"<<endl;
        cout<<"6. Postorder Traversal"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Give your choice: "<<endl;
        int ch;
        cin>>ch;

        if(ch==0) break;
        if(ch==1)
        {
            int x;
            cout<<"Insert key: ";
            cin>>x;
            root=insertNode(root, x);
        }

        if(ch==2)
        {
            int x;
            cout<<"Delete key: ";
            cin>>x;
            if(searchNode(root,x)==true)
            {
                root=deleteNode(root,x);
                cout<<"Deleted "<<x<<"."<<endl;
            }
            else cout<<"Key not found."<<endl;
        }
        else if(ch==3)
        {
            int x;
            cout<<"Search key: ";
            cin>>x;
            if(searchNode(root, x))
            {
                cout<<"Key found"<<endl;
            }
            else cout<<"Key not found"<<endl;
        }
        else if(ch==4)
        {
            cout<<"Inorder: ";
            inorder(root);
            cout<<endl;
        }

        else if(ch==5)
        {
            cout<<"Preorder: ";
            preorder(root);
            cout<<endl;
        }
        else if(ch==6)
        {
            cout<<"Postorder: ";
            postorder(root);
            cout<<endl;
        }
    }
    return 0;
}
