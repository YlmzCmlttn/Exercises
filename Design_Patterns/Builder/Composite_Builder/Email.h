#pragma once
#include <string>
#include <sstream>
#include <iostream>
class EmailBuilder;
class EmailHeaderBuilder;
class EmailBodyBuilder;
class Email
{
public:
    friend EmailBuilder;
    friend EmailHeaderBuilder;
    friend EmailBodyBuilder;
    friend std::ostream &operator<<(std::ostream &os, const Email &obj);
    static EmailBuilder create();
private:
    Email() = default;
    std::string m_From;
    std::string m_To;
    std::string m_Subject;
    std::string m_Body;
    std::string m_Attachment;
};