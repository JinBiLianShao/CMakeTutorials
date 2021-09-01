#pragma once

#include <thread>
#include <chrono>

class Sleep final {
public:
    Sleep() = default;
    ~Sleep() = default;

    void for_(int mills) const;
};
