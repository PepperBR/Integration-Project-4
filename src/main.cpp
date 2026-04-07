#include "ui/Ui.h"
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Ui ui;
    ui.run();
    return 0;
}