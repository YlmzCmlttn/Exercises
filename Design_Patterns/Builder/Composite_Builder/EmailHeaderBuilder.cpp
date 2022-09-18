#include "EmailHeaderBuilder.h"
EmailHeaderBuilder::EmailHeaderBuilder(Email &email):AbstractEmailBuilder{email}{
    std::cout<<"EmailHeaderBuilder::EmailHeaderBuilder"<<std::endl;
}
EmailHeaderBuilder& EmailHeaderBuilder::from(const std::string &from){
    std::cout<<"EmailHeaderBuilder::from"<<std::endl;
    m_Email.m_From = from;
    return *this;
}
EmailHeaderBuilder& EmailHeaderBuilder::to(const std::string &to){
    std::cout<<"EmailHeaderBuilder::to"<<std::endl;
    m_Email.m_To = to;
    return *this;
}
EmailHeaderBuilder& EmailHeaderBuilder::subject(const std::string &subject){
    std::cout<<"EmailHeaderBuilder::subject"<<std::endl;
    m_Email.m_Subject = subject;
    return *this;
}