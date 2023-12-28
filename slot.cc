#include "slot.h"

Slot::Slot(QWidget *parent) : QLabel(parent)
{
    color.setRed(255);
    color.setBlue(255);
    color.setGreen(255);
}

void Slot::mousePressEvent(QMouseEvent *event)
{
    QPointF pos = event->globalPosition();

    menu = new QFrame();
    menu->setWindowFlags(Qt::SplashScreen);
    menu->setGeometry(pos.x() + 20, pos.y() + 20, 150, 100);
    menu->setFrameShape(QFrame::Box);

    QPushButton* change = new QPushButton(menu);
    connect(change, SIGNAL(clicked()), this,
            SLOT(on_change_clicked()));
    setup_menu_button(change, 0, 0, 150, 30, "Сменить");

    QPushButton* color = new QPushButton(menu);
    connect(color, SIGNAL(clicked()), this,
            SLOT(on_color_clicked()));
    setup_menu_button(color, 0, 35, 150, 30, "Цвет");

    QPushButton* exit = new QPushButton(menu);
    connect(exit, SIGNAL(clicked()), this,
            SLOT(on_exit_clicked()));
    setup_menu_button(exit, 0, 70, 150, 30, "Закрыть");

    menu->show();
}

void Slot::setup_menu_button(QPushButton *button, int x, int y, int w, int h, QString name) {
    button->setText(name);
    button->setGeometry(x, y, w, h);
    button->show();
}

void Slot::on_color_clicked() {
    color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if (color.isValid()) {
        SetImage();
    }
}

void Slot::on_exit_clicked() {
    delete(menu);
}

void Slot::on_change_clicked() {
    if (++this->type > 3) {
        this->type = 0;
    }

    SetImage();
}

void Slot::SetImage() {
    QPixmap source_image;

    if (this->type == 0) {
        this->image = "background-image: none;";
        source_image.load(":/empty.png");
    } else if (this->type == 1) {
        this->image = "background-image: url(\":/toy_round.png\");";
        source_image.load(":/toy_round.png");
    } else if (this->type == 2) {
        this->image = "background-image: url(\":/toy_star.png\");";
        source_image.load(":/toy_star.png");
    } else if (this->type == 3) {
        this->image = "background-image: url(\":/logo.png\");";
        source_image.load(":/logo.png");
    }

    this->setStyleSheet(BGStatus() + image);

    QPixmap new_image = source_image;
    QPainter painter(&new_image);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    this->color.setAlpha(125);

    if (this->type == 0) {
        painter.eraseRect(new_image.rect());
    } else {
        painter.fillRect(new_image.rect(), this->color);
    }

    painter.end();

    this->setPixmap(new_image);
}

QString Slot::BGStatus() {
    if (this->bg == 0) {
        return "background: none;";
    } else {
        return "background: grey;";
    }
}
