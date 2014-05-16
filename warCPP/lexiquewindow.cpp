#include "lexiquewindow.h"

LexiqueWindow::LexiqueWindow() : QWidget()
{
    setFixedSize(640, 320);

    setStyleSheet(QLatin1String("background-image: url(:/fond/Lexique)"));


}
