#include <iostream>
class InteractiveObject{
public:
    virtual void interact()=0;
    virtual ~InteractiveObject()=default;
};
class Door : public InteractiveObject{
    bool m_Open;
public:
    Door():m_Open{false}{}
    inline void interact()override{
        m_Open = !m_Open;
        if(m_Open)
            std::cout<<"Open"<<std::endl;
        else
            std::cout<<"Close"<<std::endl;
    }
};

class Player{
public:
    Player(){}
    inline void interactWith(InteractiveObject* obj){
        if(obj)
            obj->interact();
    }
};

class PlayerTemplateImpl{
public:
    PlayerTemplateImpl(){}
    template <typename InteractObject>
    inline void interactWith(InteractObject* obj){
        if(obj)
            obj->interact();
    }
};

int main(){
    Player p;
    Door d;
    PlayerTemplateImpl p2;
    
    p.interactWith(&d);
    p.interactWith(&d);
    
    p2.interactWith<Door>(&d);
    p2.interactWith<Door>(&d);
    return 0;
}
