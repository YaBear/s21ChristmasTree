#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetupToyContainer();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toy_bg_switcher_toggled(bool checked)
{
    if (checked) {
        for(auto item : toy_container_) {
            item->bg = 1;
            item->setStyleSheet(item->BGStatus() + item->image);
        }
    } else {
        for(auto item : toy_container_) {
            item->bg = 0;
            item->setStyleSheet(item->BGStatus() + item->image);
        }
    }
}

void MainWindow::SetupToyContainer() {
    toy_container_.push_back(ui->toy_slot_2);
    toy_container_.push_back(ui->toy_slot_3);
    toy_container_.push_back(ui->toy_slot_4);
    toy_container_.push_back(ui->toy_slot_5);
    toy_container_.push_back(ui->toy_slot_6);
    toy_container_.push_back(ui->toy_slot_7);
    toy_container_.push_back(ui->toy_slot_8);
    toy_container_.push_back(ui->toy_slot_9);
    toy_container_.push_back(ui->toy_slot_10);
    toy_container_.push_back(ui->toy_slot_11);
    toy_container_.push_back(ui->toy_slot_12);
    toy_container_.push_back(ui->toy_slot_13);
    toy_container_.push_back(ui->toy_slot_14);
    toy_container_.push_back(ui->toy_slot_15);
    toy_container_.push_back(ui->toy_slot_16);
    toy_container_.push_back(ui->toy_slot_17);
    toy_container_.push_back(ui->toy_slot_18);
    toy_container_.push_back(ui->toy_slot_19);
    toy_container_.push_back(ui->toy_slot_20);
    toy_container_.push_back(ui->toy_slot_21);
    toy_container_.push_back(ui->toy_slot_22);
}
