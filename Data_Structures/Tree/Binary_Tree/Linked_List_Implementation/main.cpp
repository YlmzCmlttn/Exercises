#include <iostream>
#include <forward_list>
#include <list>
#include <assert.h>
#include <limits>
#include <bits/stdc++.h>
template <typename Type>
class Node
{
private:
    Node* mLeft;
    Node* mRight;
    Type mData;
    template <typename NodeType>
    friend class BST;
public:
    Node():mLeft{nullptr},mRight{nullptr}{}
    Node(const Type& val):mLeft{nullptr},mRight{nullptr},mData{val}{}
    void insert(const Type& val){
        if(val>mData){
            insert(mRight,val);
        }else if(val<mData){
            insert(mLeft,val);
        }else{
            assert(false);
        }
    }
    void insert(Node<Type>*& node,const Type& val){
        if(node){
            node->insert(val);
        }else{
            node = new Node<Type>(val);
        }
    }
};
template <typename NodeType>
class BST{
private:
    Node<NodeType>* mRoot;
    NodeType mData;

    void inorder(const Node<NodeType>* node)const{
        if(!node)return;
        inorder(node->mLeft);
        std::cout<<node->mData<<std::endl;
        inorder(node->mRight);
    }
    void preorder(const Node<NodeType>* node)const{
        if(!node)return;
        std::cout<<node->mData<<std::endl;
        inorder(node->mLeft);        
        inorder(node->mRight);
    }
    void postorder(const Node<NodeType>* node)const{
        if(!node)return;
        inorder(node->mLeft);        
        inorder(node->mRight);
        std::cout<<node->mData<<std::endl;
    }

public:
    BST():mRoot{nullptr}{}
    BST(const NodeType& val):mRoot{nullptr},mData{val}{}
    void insert(const NodeType& val){
        if(mRoot){
            mRoot->insert(val);
        }else{
            mRoot = new Node<NodeType>(val);
        }
    }
    void inOrder()const{
        std::cout<<"In-Order"<<std::endl;
        inorder(mRoot);
    }
    void preOrder()const{
        std::cout<<"Pre-Order"<<std::endl;
        preorder(mRoot);
    }
    void postOrder()const{
        std::cout<<"Post-Order"<<std::endl;
        postorder(mRoot);
    }
};


using namespace std;
 
int main()
{
    map<int, int> m;
 
    m[6] = 11; // Insertion by indexing
 
    // Direct pair insertion
    m.insert({ 4, 5 });
 
    // Insertion of pair by make_pair
    m.insert(make_pair(8, 5));
 
    cout << "Elements in map:\n";
    for (auto it : m)
        cout << "[ " << it.first << ", "
             << it.second << "]\n"; // Sorted
 
    return 0;
}


// int main(){
//     BST<int> bst;
//     bst.insert(10);
//     bst.insert(1);
//     bst.insert(4);
//     bst.insert(11);
//     bst.insert(15);
//     bst.insert(16);
//     bst.preOrder();
//     bst.inOrder();
//     bst.postOrder();

    
//     return 0;
// }