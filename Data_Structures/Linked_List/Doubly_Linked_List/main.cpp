#include <iostream>
template<typename Type>
class Node
{
public:
    Type m_Val;
    Node* m_Next;
    Node* m_Prev;
};
template<typename Type>
void push(Node<Type>*& headRef,const Type& val){
    Node<Type>* newNode = new Node<Type>();
    newNode->m_Val = val;
    newNode->m_Next = headRef;
    if(headRef)
        headRef->m_Prev = newNode;
    
    headRef= newNode;
}
template<typename Type>
void insertAfter(Node<Type>* prev,const Type& val){
    if(!prev)
        return;
    Node<Type>* newNode = new Node<Type>();
    newNode->m_Val = val;
    newNode->m_Next = prev->m_Next;
    prev->m_Next = newNode;
    newNode->m_Prev = prev;
    if(newNode->m_Next)
        newNode->m_Next->m_Prev = newNode;
}
template<typename Type>
void append(Node<Type>*& headRef,const Type& val){
    Node<Type>* newNode = new Node<Type>();
    Node<Type>* last = headRef;
    newNode->m_Val = val;   

    if(!headRef){
        headRef = newNode;
        return;
    }

    while(last->m_Next)
        last = last->m_Next;
    
    last->m_Next = newNode;
    newNode->m_Prev = last;
    return;
}
template <typename Type>
void printList(Node<Type>* node){
    Node<Type>* last = nullptr;
    std::cout<<"Traversal in forward direction"<<std::endl;
    while(node){
        std::cout<<node->m_Val<<" ";
        last = node;
        node = node->m_Next;
    }

    std::cout<<std::endl<<"Traversal in backward direction"<<std::endl;
    while(last){
        std::cout<<last->m_Val<<" ";
        last = last->m_Prev;
    }
    std::cout<<std::endl;
}


int main(){
    Node<int>* head = NULL;
    append<int>(head, 6);
    printList<int>(head);
    push<int>(head, 7);
    printList<int>(head);
    push<int>(head, 1);
    printList<int>(head);
    append<int>(head, 4);
    printList<int>(head);
    insertAfter<int>(head->m_Next, 8);
    printList<int>(head);
    return 0;
}