#include <vector>
#include <iostream>
#include <fstream>
#include <utility>
enum class Color{Black,White,Red,Blue,Green};
enum class Type{Sedan,Station,SUV,Bus,Truck,Minibus,Van};

class Vehicle{
public:
    std::string m_ModelName;
    Color m_Color;
    Type m_Type;
};

template<typename T> class Specification{
public:
    virtual bool isSatisfied(const T *item)const=0;
};

template <typename T> class Filter{
public:
    virtual std::vector<T*> filter(const std::vector<T*> items,const Specification<T>& spec)const=0;
};

class VehicleFilter : Filter<Vehicle>{
public:
    std::vector<Vehicle*> filter(const std::vector<Vehicle*> items,const Specification<Vehicle>& spec)const override{
        std::vector<Vehicle*> result;
        for(auto& p: items)
            if(spec.isSatisfied(p))
                result.push_back(p);
        return result;
    }
};

class VehicleColorSpecification : public Specification<Vehicle>{
public:
    Color m_Color;
    explicit VehicleColorSpecification(const Color color):m_Color{color}{}
    bool isSatisfied(const Vehicle* item)const override{
        return item->m_Color == m_Color;
    }
};

class VehicleTypeSpecification : public  Specification<Vehicle>{
public:
    Type m_Type;
    explicit VehicleTypeSpecification(const Type type):m_Type{type}{}
    bool isSatisfied(const Vehicle* item)const override{
        return item->m_Type == m_Type;
    }
};
template <typename T> class AndSpecification : public Specification<T>{
public:
    const Specification<T>& m_First;
    const Specification<T>& m_Second;
    AndSpecification(const Specification<T>& first,const Specification<T>& second):m_First{first},m_Second{second}{}

    bool isSatisfied(const T* item)const override{
        return m_First.isSatisfied(item)&&m_Second.isSatisfied(item);
    }
};


int main(){
    Vehicle car1{"Mercedes",Color::White,Type::Sedan};
    Vehicle car2{"Seat",Color::Red,Type::SUV};
    Vehicle car3{"Togg",Color::Green,Type::SUV};

    std::vector<Vehicle*> all{&car1,&car2,&car3};

    VehicleTypeSpecification suv(Type::SUV);
    VehicleColorSpecification green(Color::Green);
    AndSpecification<Vehicle> green_and_suv{ suv, green };

    VehicleFilter vf;

    auto big_green_things = vf.filter(all, green_and_suv);
    for (auto& x : big_green_things)
        std::cout << x->m_ModelName<<std::endl;
    
    return 0;
}
