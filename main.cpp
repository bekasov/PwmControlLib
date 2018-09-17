#include <iostream>
#include <string>

#include "SysClassPwmConfigProvider.h"


using namespace std;

int main() {
    cout << "Hello, World!" << std::endl;

    SysClassPwmConfigProvider config("/sys/class/pwm/pwmchip0", 0);

    cout << config.GetResourceRequestPath() << " -> " << config.GetAcquireValue() << endl;
    cout << config.GetResourceRequestPath(true) << " -> " << config.GetReleaseValue() << endl;
    cout << config.GetDutyPath() << endl;
    cout << config.GetPeriodPath() << endl;
    cout << config.GetEnablePath() << " -> " << config.GetEnableValue() << endl;
    cout << config.GetEnablePath() << " -> " << config.GetDisableValue() << endl;

    return 0;
}