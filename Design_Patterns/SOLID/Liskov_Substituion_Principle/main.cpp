#include <iostream>
#include <memory>
struct Shape{
    virtual unsigned int area()const=0;
};

struct Rectangle : Shape{
    Rectangle(const unsigned int& width,const unsigned int& height):m_Width{width},m_Height{height}{}
    inline unsigned int getWidth()const{return m_Width;}
    inline unsigned int getHeight()const{return m_Height;}
    inline void setWidth(const unsigned int& width){m_Width=width;}
    inline void setHeight(const unsigned int& height){m_Height=height;}
    inline unsigned int area()const{return m_Width*m_Height;}
private:
    unsigned int m_Width,m_Height;
};

struct Square : Shape{
    Square(const unsigned int& size):m_Size{size}{}
    inline void setSize(const unsigned int& size){m_Size=size;}
    inline unsigned int getSize()const{return m_Size;}
    inline unsigned int area()const{return m_Size*m_Size;}
private:
    unsigned int m_Size;
};

struct ShapeFactory{
    inline static std::unique_ptr<Shape> CreateRectangle(const unsigned int& width,const unsigned int& height){
        return std::make_unique<Rectangle>(width,height);
    };
    inline static std::unique_ptr<Shape> CreateSquare(const unsigned int& size){
        return std::make_unique<Square>(size);
    };
};

int main(){
    auto rect = ShapeFactory::CreateRectangle(10,20);
    std::cout<<rect->area()<<std::endl;
    auto sqr = ShapeFactory::CreateSquare(20);
    std::cout<<sqr->area()<<std::endl;
    return 0;
}
