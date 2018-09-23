#include <iostream>
#include <string>

#include "SysClassPwmConfigProvider.h"
#include "PwmInterface.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "Hello, World!" << std::endl;

    auto config = make_unique<SysClassPwmConfigProvider>("/sys/class/pwm/pwmchip0", 0);

    cout << config->GetResourceRequestPath() << " -> " << config->GetAcquireValue() << endl;
    cout << config->GetResourceRequestPath(true) << " -> " << config->GetReleaseValue() << endl;
    cout << config->GetDutyPath() << endl;
    cout << config->GetPeriodPath() << endl;
    cout << config->GetEnablePath() << " -> " << config->GetEnableValue() << endl;
    cout << config->GetEnablePath() << " -> " << config->GetDisableValue() << endl;

    if (argc < 3)
    {
        cout << "Usage: " << argv[0] << " <period> <duty_cycle>" << endl;
        return 1;
    }

    uint32_t period = stoi(argv[1]);
    uint32_t duty = stoi(argv[2]);

    cout << "period: " << period << "; duty: " << duty << endl;

    PwmInterface pwm(0, period, move(config));

    bool fail = false;
    try
    {
        pwm.Open();
        pwm.SetDuty(duty);
        pwm.Enable();
    }
    catch(const PwmInterface::PwmInterfaceException& e)
    {
        cout << "Error : " << e.what() << endl;
        fail = true;
    }

    try
    {
        // pwm.Close();
    }
    catch (...)
    {
        // ignored
    }

    return fail;
}