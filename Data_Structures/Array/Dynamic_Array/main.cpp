#include <iostream>
#include <memory>
#include <assert.h>
template<typename Type>
struct Vector{
    Vector():m_Capacity{10},m_Size{},m_Data{std::make_unique<Type[]>(10)}{
        
    }
    inline std::size_t size(){return m_Size;}
    inline std::size_t capacity(){return m_Capacity;}
    inline void setSize(const std::size_t& size){        
        if(size>=m_Capacity){
            setCapacity(m_Size+10);
        }
        m_Size=size;
    }
    inline void setCapacity(const std::size_t& capacity){
        if(m_Size>capacity){
            m_Size = capacity;
        }
        m_Capacity=capacity;
        setcapacity();
    }

    inline Type& at(const std::size_t& index){
        if(index<m_Size)
            return m_Data[index];
        assert(false);
    }
    inline void push_back(const Type& val){
        if(m_Size>=m_Capacity){
            setCapacity(m_Size+10);
        }
        m_Size++;
        at(m_Size-1)=val;
    }
private:
    std::size_t m_Capacity;
    std::size_t m_Size;
    std::unique_ptr<Type[]> m_Data;
    inline Type* ptr(){return m_Data.get();};
    inline void setcapacity(){
        std::cout<<"SetCapacity("<<m_Capacity<<")"<<std::endl;
        std::unique_ptr<Type[]> tmp = std::make_unique<Type[]>(m_Capacity);
        std::copy(ptr(),ptr()+m_Size,tmp.get());
        m_Data = std::move(tmp);
    }
    
};
int main(){
    Vector<int> arr;
    for(size_t i= 0;i<101;i++){
        arr.push_back(i);
        std::cout<<arr.at(i)<<std::endl;
    }
    
    return 0;
}