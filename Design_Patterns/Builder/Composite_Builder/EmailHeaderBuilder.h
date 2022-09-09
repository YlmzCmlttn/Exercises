#pragma once
#include <string>
#include "EmailBuilder.h"
class EmailHeaderBuilder : public AbstractEmailBuilder
{
public:
    explicit EmailHeaderBuilder(Email &email);
    EmailHeaderBuilder &from(const std::string &from);
    EmailHeaderBuilder &to(const std::string &to);
    EmailHeaderBuilder &subject(const std::string &subject);
};