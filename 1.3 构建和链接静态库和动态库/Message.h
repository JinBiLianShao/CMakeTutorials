#pragma once

#include <iostream>
#include <iosfwd>
#include <string>

class Message {
public:
    Message() = default;
    ~Message() = default;
    inline Message(const std::string& m) : message_(m) {}

    inline friend std::ostream &operator<<(std::ostream& os, Message &obj)
    {
        return obj.printObject(os);
    }

private:
    std::string message_;
    std::ostream &printObject(std::ostream &os);
};

