#include "temperatura.h"
#include "ui_temperatura.h"
#include <QDebug>

Temperatura::Temperatura(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Temperatura)
{
    ui->setupUi(this);
    //Conexion de signal / slots
    connect(ui->dialCent, SIGNAL(valueChanged(int)), this, SLOT(cent2Fahr_Kelv(int)));
    connect(ui->dialFahr, SIGNAL(valueChanged(int)), this, SLOT(fahr2Cent_Kelv(int)));
    connect(ui->dialKelv, SIGNAL(valueChanged(int)), this, SLOT(kelv2Cent_Fahr(int)));

    //Establecer cambio de manito
    connect(ui->dialCent, SIGNAL(sliderPressed()), this, SLOT(cambiarManito()));
    connect(ui->dialCent, SIGNAL(sliderReleased()), this, SLOT(cambiarManito()));
    connect(ui->dialFahr, SIGNAL(sliderPressed()), this, SLOT(cambiarManito()));
    connect(ui->dialFahr, SIGNAL(sliderReleased()), this, SLOT(cambiarManito()));
    connect(ui->dialKelv, SIGNAL(sliderPressed()), this, SLOT(cambiarManito()));
    connect(ui->dialKelv, SIGNAL(sliderReleased()), this, SLOT(cambiarManito()));

    // Establecer el valor inicial de F en el dial
    ui->dialFahr->setValue(32);
    //Establecer el valor inicial de C en el dial
    ui->dialCent->setValue(0);
    //Establecer el valor inicial de K en el dial
    ui->dialKelv->setValue(273);

    // Establecer el valor inicial de F en el label
    ui->lblFahr->setText("32 °F");
    //Establecer el valor inicial de C en el label
    ui->lblCent->setText("0 °C");
    //Establecer el valor inicial de K en el label
    ui->lblKelv->setText("273 K");
}

Temperatura::~Temperatura()
{
    delete ui;
}

void Temperatura::cent2Fahr_Kelv(int valor)
{

    if(ui->dialCent->hasFocus()){
        float f = (valor * 9.0/5) + 32;
        ui->dialFahr->setValue(f);
        float k = valor + 273.15;
        ui->dialKelv->setValue(k);

        //Cambio de float a QString
        QString Cent = QString::number(valor);
        QString Fahr = QString::number(f);
        QString Kelv = QString::number(k);
        //Temperatura exacta en un label
        ui->lblCent->setText(Cent + " °C");
        ui->lblFahr->setText(Fahr + " °F");
        ui->lblKelv->setText(Kelv + "  K");
    }
}

void Temperatura::fahr2Cent_Kelv(int valor)
{
    if(ui->dialFahr->hasFocus()){
        float c = (valor - 32) * 5.0/9;
        ui->dialCent->setValue(c);
        float k = (valor - 32) * 5.0/9 + 273.15;
        ui->dialKelv->setValue(k);

        //Cambio de float a QString
        QString Fahr = QString::number(valor);
        QString Cent = QString::number(c);
        QString Kelv = QString::number(k);
        //Temperatura exacta en un label
        ui->lblCent->setText(Cent + " °C");
        ui->lblFahr->setText(Fahr + " °F");
        ui->lblKelv->setText(Kelv + "  K");
    }
}

void Temperatura::kelv2Cent_Fahr(int valor)
{
    if(ui->dialKelv->hasFocus()){
        float c = valor - 273.15;
        ui->dialCent->setValue(c);
        float f = (valor - 273.15) * 9.0/5 + 32;
        ui->dialFahr->setValue(f);

        //Cambio de float a QString
        QString Kelv = QString::number(valor);
        QString Fahr = QString::number(f);
        QString Cent = QString::number(c);
        //Temperatura exacta en un label
        ui->lblCent->setText(Cent + " °C");
        ui->lblFahr->setText(Fahr + " °F");
        ui->lblKelv->setText(Kelv + "  K");
    }
}

void Temperatura::cambiarManito()
{
    if(ui->dialCent->hasFocus()){
        if(ui->dialCent->cursor()== Qt::OpenHandCursor){
            ui->dialCent->setCursor(Qt::ClosedHandCursor);
        }else
            ui->dialCent->setCursor(Qt::OpenHandCursor);

    }else if (ui->dialFahr->hasFocus()){
        if(ui->dialFahr->cursor()== Qt::OpenHandCursor){
            ui->dialFahr->setCursor(Qt::ClosedHandCursor);
        }else
            ui->dialFahr->setCursor(Qt::OpenHandCursor);

    }else if (ui->dialKelv->hasFocus()){
        if(ui->dialKelv->cursor()== Qt::OpenHandCursor){
            ui->dialKelv->setCursor(Qt::ClosedHandCursor);
        }else
            ui->dialKelv->setCursor(Qt::OpenHandCursor);
    }
}
