#include <iostream>
#include <list>
struct HtmlElement
{
    std::string m_Name;
    std::string m_Text;
    std::list<HtmlElement> m_Elements;
    HtmlElement(){}
    HtmlElement(const std::string& name,const std::string& text):m_Name{name},m_Text{text}{}
    std::string addIndent(const std::string& str,const unsigned int& indent)const{
        std::string ret;
        for(unsigned int i=0;i<indent;i++)
            ret +="\t";
        ret+=str;
        return ret;
    }
    std::string addOpenBracker(const std::string& str)const{
        return "<"+str+">";
    }
    std::string addCloseBracker(const std::string& str)const{
        return "</"+str+">";
    }
    std::string str(const unsigned int& indent = 0)const{        
        std::string ret;

        ret+=addIndent(addOpenBracker(m_Name),indent);
        ret+="\n";
        ret+=addIndent(m_Text,indent+1);
        ret+="\n";
        for(auto e : m_Elements)
            ret += e.str(indent+1);           
        ret+="\n";
        ret+=addIndent(addCloseBracker(m_Name),indent);
        ret+="\n";
        return ret;
    }    
};

struct HtmlBuilder
{
    HtmlElement root;
    HtmlBuilder(const std::string& rootName){root.m_Name=rootName;}
    void addChild(const std::string& childName,const std::string& childText){
        HtmlElement e{childName,childText};
        root.m_Elements.emplace_back(e);
    }
    std::string str(){return root.str();}
};



int main(){
    HtmlBuilder builder{"ul"};
    builder.addChild("li","A");
    builder.addChild("li","B");
    builder.addChild("li","C");    
    std::cout<<(builder.str())<<std::endl;
    return 0;
}