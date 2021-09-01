#pragma once

#include <iostream>
#include <string>

class Printer final {
public:
    Printer() = default;
    ~Printer() = default;

    void info(std::string& info) const;
    void info(const char *info) const;
};
