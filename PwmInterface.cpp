#include "PwmInterface.h"


PwmInterface::PwmInterface(uint8_t pwmNumber, uint32_t period, unique_ptr<IPwmDriverConfigProvider> config)
    : config(move(config)), period(period), pwmNumber(pwmNumber)
{
}

void PwmInterface::Open()
{
    this->writeToFile(this->config->GetResourceRequestPath(false), this->config->GetAcquireValue());
}

void PwmInterface::Close()
{
    this->writeToFile(this->config->GetResourceRequestPath(true), this->config->GetReleaseValue());
}

void PwmInterface::Enable()
{
    this->writeToFile(this->config->GetEnablePath(), this->config->GetEnableValue());
}

void PwmInterface::Disable()
{
    this->writeToFile(this->config->GetEnablePath(), this->config->GetDisableValue());
}

void PwmInterface::SetDuty(uint32_t value)
{
    this->writeToFile(this->config->GetDutyPath(), value);
}

uint32_t PwmInterface::GetDuty()
{
    return 0;
}

uint32_t PwmInterface::GetPeriod()
{
    return 0;
}
