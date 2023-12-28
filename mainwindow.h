#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "slot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toy_bg_switcher_toggled(bool checked);

private:
    Ui::MainWindow *ui;

    std::list<Slot*> toy_container_;
    void SetupToyContainer();
};
#endif // MAINWINDOW_H
