#include <iostream>
#include <list>
#include <utility>
struct Tag
{
    std::string m_Name;
    std::string m_Text;
    std::list<Tag> m_Children;
    std::list<std::pair<std::string,std::string>> m_Attributes;
    friend std::ostream& operator<<(std::ostream& os,const Tag& tag){
        os<<tag.m_Name<<" "<<tag.m_Text<<std::endl;
        for(auto attribute : tag.m_Attributes)
            os<<"Attribute: "<<attribute.first<<" "<<attribute.second;
        os<<std::endl;
        for(auto child : tag.m_Children)
            os<<child;
        return os;
    }
protected:
    Tag(const std::string& name,const std::string& text):m_Name{name},m_Text{text}{}
    Tag(const std::string& name,const std::list<Tag>& children):m_Name{name},m_Children{children}{}
};

struct P : Tag
{
    explicit P(const std::string& text):Tag{"p",text}{
    }
    P(std::initializer_list<Tag> children):Tag{"p",children}{
    }
};

struct Img : Tag
{
    explicit Img(const std::string& url):Tag{"img",""}{
        m_Attributes.emplace_back(std::make_pair("src",url));
    }
};



int main(){
    
    std::cout<<
        P {
            Img{"http://test.com"},Img{"http://test.com"},P{P{"Hellooo"},P{"Hey"}}
        }
    <<std::endl;
    return 0;
}