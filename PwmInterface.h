#pragma once

#include <exception>
#include <string>


using namespace std;

class PwmInterface final
{
public:
    class PwmInterfaceException;


};


class PwmInterface::PwmInterfaceException : public exception
{
private:
    string errorMessage;

public:
    PwmInterfaceException() : errorMessage("") {}
    PwmInterfaceException(const string& errorMessage) : errorMessage(errorMessage) {}

public:
    const char* what() const noexcept override {
        if (this->errorMessage == "")
        {
            return exception::what();
        }

        return this->errorMessage.c_str();
    }

    ~PwmInterfaceException() override = default;
};
