#include "SysClassPwmConfigProvider.h"


SysClassPwmConfigProvider::SysClassPwmConfigProvider(const string& pwmRootFolderPath, int8_t pwmNumber)
        : pwmRootFolderPath(pwmRootFolderPath), pwmNumber(pwmNumber)
{
    this->pwmControlFolderPath = this->pwmRootFolderPath + "/"
            + this->PWM_CHANNEL_SUBPATH_TEMPLATE + to_string(this->pwmNumber) + "/";
}

string SysClassPwmConfigProvider::GetResourceRequestPath(bool toClose)
{
    return this->pwmRootFolderPath + "/" + (toClose ? this->RELEASE_RESOURCE_REQUEST : this->ACQUIRE_RESOURCE_REQUEST);
}

string SysClassPwmConfigProvider::GetDutyPath()
{
    return this->pwmControlFolderPath + this->DUTY_CYCLE_PARAM_NAME;
}

string SysClassPwmConfigProvider::GetEnablePath()
{
    return this->pwmControlFolderPath + this->ENABLE_AND_DISABLE_PARAM_NAME;
}

string SysClassPwmConfigProvider::GetPeriodPath() {
    return this->pwmControlFolderPath + this->PERIOD_PARAM_NAME;
}

string SysClassPwmConfigProvider::GetAcquireValue() {
    return this->ACQUIRE_VALUE;
}

string SysClassPwmConfigProvider::GetReleaseValue() {
    return this->RELEASE_VALUE;
}

string SysClassPwmConfigProvider::GetEnableValue() {
    return this->ENABLE_VALUE;
}

string SysClassPwmConfigProvider::GetDisableValue() {
    return this->DISABLE_VALUE;
}
