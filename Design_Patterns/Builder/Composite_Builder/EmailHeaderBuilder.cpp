#include "EmailHeaderBuilder.h"
EmailHeaderBuilder::EmailHeaderBuilder(Email &email):AbstractEmailBuilder{email}{

}
EmailHeaderBuilder& EmailHeaderBuilder::from(const std::string &from){
    m_Email.m_From = from;
    return *this;
}
EmailHeaderBuilder& EmailHeaderBuilder::to(const std::string &to){
    m_Email.m_To = to;
    return *this;
}
EmailHeaderBuilder& EmailHeaderBuilder::subject(const std::string &subject){
    m_Email.m_Subject = subject;
    return *this;
}