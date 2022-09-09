#include "EmailBodyBuilder.h"
EmailBodyBuilder::EmailBodyBuilder(Email &email):AbstractEmailBuilder{email}{

}
EmailBodyBuilder& EmailBodyBuilder::body(const std::string &body){
    m_Email.m_Body = body;
    return *this;
}
EmailBodyBuilder& EmailBodyBuilder::attachment(const std::string &attachment){
    m_Email.m_Attachment = attachment;
    return *this;
}