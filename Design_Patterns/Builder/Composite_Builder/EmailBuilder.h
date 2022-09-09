#pragma once
#include "Email.h"
#include "AbstractEmailBuilder.h"
class EmailBuilder : public AbstractEmailBuilder
{
    Email m_Email;
public:
    EmailBuilder();
};