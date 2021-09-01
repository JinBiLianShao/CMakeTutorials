#include "Message.h"

int main()
{
    Message say_hello("hello, CMake World!");
    std::cout << say_hello << std::endl;

    Message say_goodbye("Goodbye, CMake World!");
    std::cout << say_goodbye << std::endl;

    return 0;
}
