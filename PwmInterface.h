#pragma once

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <memory>

#include "IPwmDriverConfigProvider.h"


using namespace std;

class PwmInterface final
{
private:
    unique_ptr<IPwmDriverConfigProvider> config;
    uint32_t period;
    uint8_t pwmNumber;

public:
    class PwmInterfaceException;

    PwmInterface(uint8_t pwmNumber, uint32_t period, unique_ptr<IPwmDriverConfigProvider> config);

    void Open();
    void Close();
    void Enable();
    void Disable();

    void SetDuty(uint32_t value);
    uint32_t GetDuty();

    uint32_t GetPeriod();

private:
    template <typename TValue>
    void writeToFile(string fullPath, const TValue& value);
};

template <typename TValue>
void PwmInterface::writeToFile(string fullPath, const TValue& value)
{
    ofstream outputFile {fullPath};

    outputFile.exceptions(outputFile.exceptions() | ios_base::failbit);

    try
    {
        outputFile << value;
    }
    catch (const ios_base::failure& e)
    {
        throw PwmInterfaceException("I/O error with file \"" + fullPath + "\"");
    }
    catch (const exception& e)
    {
        throw PwmInterfaceException("Error: " + string(e.what()));
    }
}


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
