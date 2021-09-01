#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

auto useless = [](auto a, auto b) {
    return a+b;
};

class ProgressBar final {
public:
    ProgressBar();
    virtual ~ProgressBar() = default;

    void run();

private:
    std::string m_bar;
    std::string m_shap;
};
