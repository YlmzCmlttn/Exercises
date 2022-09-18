#include "Email.h"
#include "EmailBuilder.h"
EmailBuilder Email::create(){
    std::cout<<"Email::create()"<<std::endl;
    return EmailBuilder{};
}
std::ostream &operator<<(std::ostream &os, const Email &obj){
    return os
           << "from: " << obj.m_From << std::endl
           << "to: " << obj.m_To << std::endl
           << "subject: " << obj.m_Subject << std::endl
           << "body: " << obj.m_Body << std::endl
           << "attachment: " << obj.m_Attachment << std::endl;
}