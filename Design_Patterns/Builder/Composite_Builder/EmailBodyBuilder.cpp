#include "EmailBodyBuilder.h"
EmailBodyBuilder::EmailBodyBuilder(Email &email):AbstractEmailBuilder{email}{
    std::cout<<"EmailBodyBuilder::EmailBodyBuilder"<<std::endl;
}
EmailBodyBuilder& EmailBodyBuilder::body(const std::string &body){
    std::cout<<"EmailBodyBuilder::body"<<std::endl;
    m_Email.m_Body = body;
    return *this;
}
EmailBodyBuilder& EmailBodyBuilder::attachment(const std::string &attachment){
    std::cout<<"EmailBodyBuilder::attachment"<<std::endl;
    m_Email.m_Attachment = attachment;
    return *this;
}