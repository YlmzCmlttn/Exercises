#include <iostream>
#include <forward_list>
#include <list>
#include <assert.h>
#include <limits>
template <typename QueueType>
class Queue
{
private:
    std::list<QueueType> mData;
public:    
    inline std::size_t size()const{return mData.size();}
    inline void push(const QueueType& val){mData.push_back(val);};
    inline QueueType& top(){return mData.front();}
    inline void pop(){mData.pop_front();}
};


int main(){
    Queue<int> queue;
    queue.push(11);
    std::cout<<queue.top()<<std::endl;
    queue.push(12);
    std::cout<<queue.top()<<std::endl;
    queue.pop();
    std::cout<<queue.top()<<std::endl;
    queue.pop();
    for(uint i =0;i<10;i++){
        queue.push(i);
    }
    std::cout<<queue.top()<<std::endl;
    for(uint i =0;i<10;i++){
        std::cout<<queue.top()<<std::endl;
        queue.pop();        
    }
    
    return 0;
}