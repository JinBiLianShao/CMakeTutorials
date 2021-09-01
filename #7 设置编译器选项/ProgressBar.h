#pragma once

#include <iostream>
#include <string>
#include "Sleep.h"

class ProgressBar final {
public:
    ProgressBar();
    virtual ~ProgressBar() = default;

    void run();

private:
    std::string m_bar;
    std::string m_shap;
};
