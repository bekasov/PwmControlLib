#pragma once

#include <iostream>
#include <string>

#include "IPwmDriverConfigProvider.h"


using namespace std;

class SysClassPwmConfigProvider final : public IPwmDriverConfigProvider
{
private:
    string pwmRootFolderPath;
    int8_t pwmNumber;

    string pwmControlFolderPath;

public:
    SysClassPwmConfigProvider(const string &pwmRootFolderPath, int8_t pwmNumber);


    string GetResourceRequestPath(bool toClose = false) override;
    string GetDutyPath() override;
    string GetEnablePath() override;
    string GetPeriodPath() override;

    string GetAcquireValue() override;
    string GetReleaseValue() override;
    string GetEnableValue() override;
    string GetDisableValue() override;

    ~SysClassPwmConfigProvider() override = default;

private:
    const string ACQUIRE_RESOURCE_REQUEST = "export";
    const string RELEASE_RESOURCE_REQUEST = "unexport";

    const string PWM_CHANNEL_SUBPATH_TEMPLATE = "pwm";

    const string DUTY_CYCLE_PARAM_NAME = "duty_cycle";
    const string PERIOD_PARAM_NAME = "period";
    const string ENABLE_AND_DISABLE_PARAM_NAME = "enable";

    const string ACQUIRE_VALUE = "0";
    const string RELEASE_VALUE = "0";
    const string ENABLE_VALUE = "1";
    const string DISABLE_VALUE = "0";
};
