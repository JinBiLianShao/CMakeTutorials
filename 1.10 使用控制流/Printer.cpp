#include "Printer.h"

void Printer::info(std::string &info) const
{
    std::cout << info;
}

void Printer::info(const char *info) const
{
    std::cout << info;
}
