#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

int MainWindow::factorToScale(QString text)
{
    if(text == "No Influence")
        return 0;
    if(text == "Incidental")
        return 1;
    if(text == "Moderate")
        return 2;
    if(text == "Average")
        return 3;
    if(text == "Significant")
        return 4;
    if(text == "Essential")
        return 5;
}

void MainWindow::on_ufpButton_released()
{
    ui->lineEdit_17->setText(tr("%1").arg(ui->lineEdit_1->text().toInt() * 3));
    ui->lineEdit_16->setText(tr("%1").arg(ui->lineEdit_2->text().toInt() * 4));
    ui->lineEdit_18->setText(tr("%1").arg(ui->lineEdit_3->text().toInt() * 6));

    ui->lineEdit_31->setText(tr("%1").arg(ui->lineEdit_16->text().toInt() +
    ui->lineEdit_17->text().toInt() + ui->lineEdit_18->text().toInt()));


    ui->lineEdit_19->setText(tr("%1").arg(ui->lineEdit_6->text().toInt() * 4));
    ui->lineEdit_20->setText(tr("%1").arg(ui->lineEdit_4->text().toInt() * 5));
    ui->lineEdit_21->setText(tr("%1").arg(ui->lineEdit_5->text().toInt() * 7));

    ui->lineEdit_32->setText(tr("%1").arg(ui->lineEdit_19->text().toInt() +
    ui->lineEdit_20->text().toInt() + ui->lineEdit_21->text().toInt()));


    ui->lineEdit_22->setText(tr("%1").arg(ui->lineEdit_9->text().toInt() * 3));
    ui->lineEdit_23->setText(tr("%1").arg(ui->lineEdit_7->text().toInt() * 4));
    ui->lineEdit_24->setText(tr("%1").arg(ui->lineEdit_8->text().toInt() * 6));

    ui->lineEdit_33->setText(tr("%1").arg(ui->lineEdit_22->text().toInt() +
    ui->lineEdit_23->text().toInt() + ui->lineEdit_24->text().toInt()));


    ui->lineEdit_25->setText(tr("%1").arg(ui->lineEdit_12->text().toInt() * 7));
    ui->lineEdit_26->setText(tr("%1").arg(ui->lineEdit_10->text().toInt() * 10));
    ui->lineEdit_27->setText(tr("%1").arg(ui->lineEdit_11->text().toInt() * 15));

    ui->lineEdit_34->setText(tr("%1").arg(ui->lineEdit_25->text().toInt() +
    ui->lineEdit_26->text().toInt() + ui->lineEdit_27->text().toInt()));


    ui->lineEdit_28->setText(tr("%1").arg(ui->lineEdit_13->text().toInt() * 5));
    ui->lineEdit_29->setText(tr("%1").arg(ui->lineEdit_14->text().toInt() * 7));
    ui->lineEdit_30->setText(tr("%1").arg(ui->lineEdit_15->text().toInt() * 10));

    ui->lineEdit_35->setText(tr("%1").arg(ui->lineEdit_28->text().toInt() +
    ui->lineEdit_29->text().toInt() + ui->lineEdit_30->text().toInt()));


    ui->ufpEdit->setText(tr("%1").arg(ui->lineEdit_31->text().toInt() +
    ui->lineEdit_32->text().toInt() + ui->lineEdit_33->text().toInt() +
    ui->lineEdit_34->text().toInt() + ui->lineEdit_35->text().toInt()));
}

void MainWindow::on_cafButton_released()
{
    int F = factorToScale(ui->comboBox_1->currentText()) +
    factorToScale(ui->comboBox_2->currentText()) +
    factorToScale(ui->comboBox_3->currentText()) +
    factorToScale(ui->comboBox_4->currentText()) +
    factorToScale(ui->comboBox_5->currentText()) +
    factorToScale(ui->comboBox_6->currentText()) +
    factorToScale(ui->comboBox_7->currentText()) +
    factorToScale(ui->comboBox_8->currentText()) +
    factorToScale(ui->comboBox_9->currentText()) +
    factorToScale(ui->comboBox_10->currentText()) +
    factorToScale(ui->comboBox_11->currentText()) +
    factorToScale(ui->comboBox_12->currentText()) +
    factorToScale(ui->comboBox_13->currentText()) +
    factorToScale(ui->comboBox_14->currentText());

    float CAF = F * 0.01 + 0.65;

    ui->cafEdit->setText(tr("%1").arg(CAF));
}

void MainWindow::on_fpButton_released()
{
    on_ufpButton_released();
    on_cafButton_released();

    float FP = ui->ufpEdit->text().toFloat() * ui->cafEdit->text().toFloat();

    ui->statusBar->showMessage(tr("The computed Function Points for the project: %1").arg(FP));
}

MainWindow::~MainWindow()
{
    delete ui;
}

