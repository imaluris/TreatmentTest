// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

#include "canlib.h"
#include <QPlainTextEdit>
#include "mainwindow.h"
#include "tcanmxreader.h"


extern CanHandle hnd;
extern canStatus stat;
extern MainWindow *w;
extern QPlainTextEdit *listCan;
extern TCanMxReader worker;

enum CanDisplayType {
    Standard,
    Fixed
};

extern CanDisplayType displayType;


#endif // GLOBALS_H
