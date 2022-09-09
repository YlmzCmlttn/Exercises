#include "AbstractEmailBuilder.h"
#include "EmailBuilder.h"
#include "EmailBodyBuilder.h"
#include "EmailHeaderBuilder.h"
EmailHeaderBuilder AbstractEmailBuilder::header() const
{
    return EmailHeaderBuilder{m_Email};
};
EmailBodyBuilder AbstractEmailBuilder::body() const
{
    return EmailBodyBuilder{m_Email};
};