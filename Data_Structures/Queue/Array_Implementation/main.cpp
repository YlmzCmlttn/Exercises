#include <iostream>
#include <array>
#include <assert.h>
#include <limits>
template <typename StackType,std::size_t StackSize>
class Queue
{
private:
    std::array<StackType,StackSize> mData;
    std::size_t mFront;
    std::size_t mRear;
    inline bool isEmpty()const{return ((mFront == std::numeric_limits<std::size_t>::max()) && (mRear == std::numeric_limits<std::size_t>::max())) ? true : false;};
    inline bool isFull()const{return ((mRear+1)%StackSize)==mFront? true : false;};    
public:
    Queue():mFront{std::numeric_limits<std::size_t>::max()},mRear{std::numeric_limits<std::size_t>::max()}{};
    
    inline std::size_t size()const{return StackSize;}
    
    
    inline void push(const StackType& val){
        if(isFull())return;
        else if(isEmpty()){
            mFront = 0;
            mRear = 0;
        }
        else mRear = (mRear+1)%StackSize;        
        mData[mRear]=val;
    };

    inline StackType& top(){
        assert(!isEmpty());
        return mData[mFront];
    }
    inline void pop(){
        if(isEmpty())return;
        else if(mFront==mRear){
            mFront = std::numeric_limits<std::size_t>::max();
            mRear = std::numeric_limits<std::size_t>::max();
        }else mFront = (mFront+1)%StackSize;
    }
};


int main(){
    Queue<int,10> queue;
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