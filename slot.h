#ifndef SLOT_H
#define SLOT_H

#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include <QtWidgets>

class Slot : public QLabel
{
    Q_OBJECT

public:
     explicit Slot(QWidget *parent = nullptr);
    size_t bg = 0;
    QString BGStatus();
    QString image = "background-image: none;";
private slots:
    void on_change_clicked();
    void on_exit_clicked();
    void on_color_clicked();
private:
    size_t type = 0;

    QColor color;
    QFrame* menu;
    void mousePressEvent(QMouseEvent *event) override;
    void setup_menu_button(QPushButton *button, int x, int y, int w, int h, QString name);
    void SetImage();
};
#endif // SLOT_H
