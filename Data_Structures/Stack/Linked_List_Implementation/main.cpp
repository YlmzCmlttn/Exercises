#include <iostream>
#include <forward_list>
#include <list>
#include <assert.h>
#include <limits>
template <typename StackType>
class Stack
{
private:
    std::forward_list<StackType> m_Data;
    std::size_t m_Size=0;
public:    
    inline std::size_t size()const{return m_Size;}
    inline void push(const StackType& val){m_Data.push_front(val);m_Size++;};
    inline StackType& top(){return m_Data.front();}
    inline void pop(){m_Data.pop_front();m_Size--;}
};


int main(){
    Stack<int> stack;
    std::cout<<sizeof(std::list<int>)<<std::endl;
    std::cout<<sizeof(std::forward_list<int>)+sizeof(std::forward_list<std::size_t>)<<std::endl;
    stack.push(11);
    std::cout<<stack.top()<<std::endl;
    stack.push(12);
    std::cout<<stack.top()<<std::endl;
    stack.pop();
    std::cout<<stack.top()<<std::endl;
    for(uint i=0;i<1011;i++){
        stack.push(i);
    }
    std::cout<<stack.size()<<std::endl;
    return 0;
}