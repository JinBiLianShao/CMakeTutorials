#include <iostream>
#include "ProgressBar.h"

#define PRINT(x) do { \
    std::cout << #x << std::endl; \
} while (false)

int main()
{
#ifdef IS_WINDOWS
    PRINT(Hello from Windows!);
#elif IS_LINUX
    PRINT(Hello from Linux!);
#elif IS_MACOS
    PRINT(Hello from MacOS!);
#else
    PRINT(Hello from an unknown system!);
#endif 

    ProgressBar bar;
    bar.run();

    return 0;
}
