#include <iostream>


template<typename Type>
class Node
{
private:
    template<typename NodeType>
    friend class RootNode;
    Node():m_Val{NULL},m_Next{nullptr}{};
    explicit Node(const Type& val):m_Val{val},m_Next{nullptr}{};
    mutable Type m_Val;
    Node* m_Next;
};

template<typename NodeType>
class RootNode{
    Node<NodeType>* root;
public:
    RootNode():root{new Node<NodeType>{}}{};
    inline const Node<NodeType> getRoot()const{return *root;}
    inline void emplaceFront(const NodeType& val){
        Node<NodeType>*tmp = new Node<NodeType>(val);
        tmp->m_Next = root->m_Next;
        root->m_Next = tmp;
    }
    inline void emplaceBack(const NodeType& val){
        Node<NodeType>* tmp = root;
        while(tmp->m_Next){
            tmp = tmp->m_Next;
        }
        tmp->m_Next = new Node<NodeType>(val);        
    }
    inline void erase(const unsigned int& index){
        Node<NodeType>* tmp = root->m_Next;
        if(index == 0){
            root->m_Next = tmp->m_Next;
            delete tmp;        
        }
        
        for(unsigned int i =0;i<index-1;i++){
            if(tmp)
                tmp = tmp->m_Next;
            else
                return;
        }
        Node<NodeType>* tmpNext = tmp->m_Next;
        tmp->m_Next = tmpNext->m_Next;
        delete tmpNext;
    }
    inline void insert(const unsigned int& index, const NodeType& val){
        if(index==0){
            emplaceFront(val);
            return;
        }
        Node<NodeType>* tmp = root->m_Next;
        for(unsigned int i =0;i<index-1;i++){
            if(tmp)
                tmp = tmp->m_Next;
            else
                return;
        }
        Node<NodeType>* newNode = new Node<NodeType>(val);
        newNode->m_Next = tmp->m_Next;
        tmp->m_Next = newNode;
    }
    inline void print(){
        Node<NodeType>* tmp = root->m_Next;
        printNode(tmp);
    }
    inline void reversePrint(){
        Node<NodeType>* tmp = root->m_Next;
        reversePrintNode(tmp);
        std::cout<<std::endl;
    }
    inline void printNode(Node<NodeType>* node){
        if(!node){
            std::cout<<std::endl;
            return;
        }
        std::cout<<node->m_Val<<" ";
        printNode(node->m_Next);
    }
    inline void reversePrintNode(Node<NodeType>* node){
        if(!node){            
            return;
        }
        reversePrintNode(node->m_Next);
        std::cout<<node->m_Val<<" ";        
    }
};

int main(){
    auto root = RootNode<int>();    
    for(uint i=0;i<10;i++){
        root.emplaceBack(i);
        root.emplaceFront(i);
        root.print();
    }   
    root.insert(5,100);
    root.reversePrint();
    root.print();
    return 0;
}