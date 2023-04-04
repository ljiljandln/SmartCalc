#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

extern "C" {
    #include "s21_smartcalc.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_zero,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_one,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_two,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_three,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_four,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_five,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_six,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_seven,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_eight,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_nine,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_dot,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_equalSign,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_mul,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_asin,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_acos,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_atan,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_openBrace,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_closedBrace,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_delete,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_pow,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_x,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
    connect(ui->pushButton_graph,SIGNAL(clicked()),this,SLOT(operators_and_operands()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::operators_and_operands() {
    QString input;
    QPushButton *button = (QPushButton *)sender();
    double xFromInput = ui->doubleSpinBox->text().toDouble();
    if (button->text() == "del") {
        input = "";
        ui->inputText->setText(input);
        ui->labelResult->setText("Result: ");
        ui->widget->clearGraphs();
    } else if (button->text() == "=") {
        input = (ui->inputText->toPlainText() + '\0');
        QByteArray temp;
        temp = input.toUtf8();
        char *charInput = temp.data();

        if (checkString(charInput) == 0) {
            double res = smartCalc(charInput, xFromInput);
            QString res_string;
            res_string = QString::number(res, 'g', 8);
            ui->labelResult->setText("Result: " + res_string);
        } else {
            input = "";
            ui->inputText->setText(input);
            QMessageBox::critical(this, "incorrect statement", "Incorrect statement, please try again!");
        }
    } else if (button->text() == "getGraphic") {
        input = (ui->inputText->toPlainText() + '\0');
        QByteArray temp;
        temp = input.toUtf8();
        char *charInput = temp.data();
        if (checkString(charInput) == 0) {
            b = ui->spinBox->text().toDouble();
            a = -b;
            h = 0.01;
            N = (b - a) / h + 2;
            QVector<double> x(N), y(N);
            for (double X = a; X <= b; X += h) {
                x.push_back(X);
                stack s = parseInput(charInput, X);
                y.push_back(calculate(getPolish(s)));
            }

            ui->widget->clearGraphs();
            ui->widget->addGraph();
            ui->widget->graph(0)->setData(x, y);

            ui->widget->replot();
            ui->widget->setInteraction(QCP::iRangeZoom, true);
            ui->widget->setInteraction(QCP::iRangeDrag, true);
            x.clear();
            y.clear();
        }
    } else {
        input = (ui->inputText->toPlainText() + button->text());
        ui->inputText->setText(input);
        ui->widget->clearGraphs();
    }
}
