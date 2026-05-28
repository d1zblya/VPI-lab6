#include "mywidget.h"

MyWidget::~MyWidget() {}

void MyWidget::slotSqua() {
    QString str = line1->text();
    if (str.length() >= 2) {
        QChar first = str[0];
        QChar last = str[str.length() - 1];
        str[0] = last;
        str[str.length() - 1] = first;
    }
    line2->setText(str);
}

void MyWidget::slotClear() {
    line1->setText("");
    line2->setText("");
    labsign->setText("");
}

MyWidget::MyWidget() {
    this->resize(300, 150);

    line1 = new QLineEdit(this);
    line2 = new QLineEdit(this);
    bsqua = new QPushButton("swap", this);
    bclear = new QPushButton("C", this);
    labsign = new QLabel("", this);
    labis = new QLabel("=>", this);

    line1->move(60, 30);
    line1->resize(70, 20);
    labis->move(140, 30);
    labis->resize(30, 20);
    line2->move(180, 30);
    line2->resize(70, 20);
    line2->setReadOnly(true);

    bsqua->move(70, 80);
    bsqua->resize(65, 60);
    bclear->move(190, 80);
    bclear->resize(50, 50);

    connect(bsqua, SIGNAL(clicked()), this, SLOT(slotSqua()));
    connect(bclear, SIGNAL(clicked()), this, SLOT(slotClear()));
}
