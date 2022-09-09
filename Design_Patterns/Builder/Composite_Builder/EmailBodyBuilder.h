#pragma once
#include <string>
#include "EmailBuilder.h"
class EmailBodyBuilder : public AbstractEmailBuilder
{
public:
    explicit EmailBodyBuilder(Email &email);
    EmailBodyBuilder &body(const std::string &body);
    EmailBodyBuilder &attachment(const std::string &attachment);
};