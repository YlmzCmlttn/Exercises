#include <iostream>
template<typename ArrayType, std::size_t ArraySize>
struct Array{
    Array():m_Data{new ArrayType[ArraySize]}{
        
    }
    inline std::size_t size(){return ArraySize;}
    inline ArrayType& at(const std::size_t& index){
        return m_Data[index];
    }
    inline void fill(const ArrayType& val){
        std::fill(m_Data,m_Data+ArraySize,val);
    }
private:
    ArrayType* m_Data;
};
int main(){
    Array<int,10> arr;
    for(size_t i= 0;i<arr.size();i++){
        arr.at(i)=int(i);
        std::cout<<arr.at(i)<<std::endl;
    }
    arr.fill(11);
    for(size_t i= 0;i<arr.size();i++){        
        std::cout<<arr.at(i)<<std::endl;
    }
    return 0;
}