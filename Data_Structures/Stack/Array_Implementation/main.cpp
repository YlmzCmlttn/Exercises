#include <iostream>
#include <array>
#include <assert.h>
#include <limits>
template <typename StackType,std::size_t StackSize>
class Stack
{
private:
    std::array<StackType,StackSize> m_Data;
    std::size_t m_Top;
    inline bool isEmpty()const{return (m_Top==static_cast<std::size_t>(std::numeric_limits<std::size_t>::max()))?true:false;};
    inline bool isFull()const{return m_Top==StackSize;};
public:
    Stack():m_Top{std::numeric_limits<std::size_t>::max()}{};
    
    inline std::size_t size()const{return StackSize;}
    
    
    inline void push(const StackType& val){
        assert(!isFull());
        m_Data[++m_Top]=val;
    };

    inline StackType& top(){
        assert(!isEmpty());
        return m_Data[m_Top];
    }
    inline void pop(){
        assert(!isEmpty());
        m_Top--;
    }
};


int main(){
    Stack<int,10> stack;
    stack.push(11);
    std::cout<<stack.top()<<std::endl;
    stack.push(12);
    std::cout<<stack.top()<<std::endl;
    stack.pop();
    std::cout<<stack.top()<<std::endl;
    
    return 0;
}