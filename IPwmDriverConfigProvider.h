#pragma once

#include <string>


using namespace std;

class IPwmDriverConfigProvider
{
public:
    virtual string GetResourceRequestPath(bool toClose = false) = 0;
    virtual string GetPeriodPath() = 0;
    virtual string GetDutyPath() = 0;
    virtual string GetEnablePath() = 0;

    virtual string GetAcquireValue() = 0;
    virtual string GetReleaseValue() = 0;
    virtual string GetEnableValue() = 0;
    virtual string GetDisableValue() = 0;

    virtual ~IPwmDriverConfigProvider() = default;
};
