#include "AbstractEmailBuilder.h"
#include "EmailBuilder.h"
#include "EmailBodyBuilder.h"
#include "EmailHeaderBuilder.h"
EmailHeaderBuilder AbstractEmailBuilder::header() const
{
    std::cout<<"AbstractEmailBuilder::header()"<<std::endl;
    return EmailHeaderBuilder{m_Email};
};
EmailBodyBuilder AbstractEmailBuilder::body() const
{
    std::cout<<"AbstractEmailBuilder::body()"<<std::endl;
    return EmailBodyBuilder{m_Email};
};