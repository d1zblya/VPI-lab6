#include "mywidget.h"

MyWidget::~MyWidget() {}

void MyWidget::slotSqua() {
    double d;
    QString tmp;
    d = line1->text().toDouble();
    d = d * d;
    labsign->setText("");
    line2->setText(tmp.setNum(d));
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
    bsqua = new QPushButton("*", this);
    bclear = new QPushButton("C", this);
    labsign = new QLabel("", this);
    labis = new QLabel("^2=", this);

    line1->move(60, 30);
    line1->resize(70, 20);
    labis->move(140, 30);
    labis->resize(30, 20);
    line2->move(180, 30);
    line2->resize(70, 20);
    line2->setReadOnly(true);

    bsqua->move(70, 80);
    bsqua->resize(50, 50);
    bclear->move(190, 80);
    bclear->resize(50, 50);

    connect(bsqua, SIGNAL(clicked()), this, SLOT(slotSqua()));
    connect(bclear, SIGNAL(clicked()), this, SLOT(slotClear()));
}
