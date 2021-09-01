#include "ProgressBar.h"
#include "Sleep.h"
#include "Printer.h"

int main()
{
    ProgressBar bar;
    Sleep sleep;
    Printer printer;

    printer.info("===== DOWNLOADING =====\n");
    sleep.for_(800);

    bar.run();

    return 0;
}
