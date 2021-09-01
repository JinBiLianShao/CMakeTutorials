#include "Sleep.h"

void Sleep::for_(int mills) const
{
    std::this_thread::sleep_for(std::chrono::milliseconds(mills));
}
