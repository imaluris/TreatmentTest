// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

#include "canlib.h"
#include <QListWidget>
#include "mainwindow.h"
#include "tcanmxreader.h"


extern CanHandle hnd;
extern canStatus stat;
extern MainWindow *w;
extern QListWidget *listCan;
extern TCanMxReader worker;

#endif // GLOBALS_H
