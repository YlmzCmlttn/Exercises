#pragma once
#include "Email.h"
class EmailHeaderBuilder;
class EmailBodyBuilder;
class AbstractEmailBuilder
{
protected:
    Email &m_Email;
    explicit AbstractEmailBuilder(Email &email) : m_Email(email) {}
public:
    operator Email() const
    {
        return std::move(m_Email);
    };
    EmailHeaderBuilder header() const;
    EmailBodyBuilder body() const;
};