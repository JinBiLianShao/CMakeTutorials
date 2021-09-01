#include "ProgressBar.h"
#include "Sleep.h"
#include "Printer.h"

int main()
{
    ProgressBar bar;
    Printer p;
    p.info("=========  downloading  =========\n");

    Sleep s;
    s.for_(2000);

    bar.run();

    return 0;
}
