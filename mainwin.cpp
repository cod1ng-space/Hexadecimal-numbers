#include "mainwin.h"

bool MainWin::isNumbersCorrect()
{
    bool okType1, okType2, okSize1 = (lineEditFirstNum->text().size() <= 12), okSize2 = (lineEditSecondNum->text().size() <= 12);
    lineEditFirstNum->text().toLongLong(&okType1, 16);
    lineEditSecondNum->text().toLongLong(&okType2, 16);
    if ((okType1 && okType2) == 0 || (okSize1 && okSize2) == 0){
        QString textType = "", textSize = "";
        if (okType1 == okType2 && okType1 == 0) textType = " Пожалуйста, проверьте синтаксическую корректность обоих введённых значений.";
        else if (okType1 == 0) textType = " Пожалуйста, проверьте синтаксическую корректность первого введённого значения.";
        else if (okType2 == 0) textType = " Пожалуйста, проверьте синтаксическую корректность второго введдённого значения.";
        if (okSize1 == okSize2 && okSize1 == 0) textSize = " Оба числа должны содержать не более 12 цифр!";
        else if (okSize1 == 0) textSize = " Первое число содержит более 12 цифр!";
        else if (okSize2 == 0) textSize = " Второе число содержит более 12 цифр!";
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setText("Ошибка");
        msg.setInformativeText("Неверно введены шестнадцатеричные числа!" + textType + textSize);
        msg.exec();
        return false;
    }
    return true;
}

MainWin::MainWin(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Шестнадцатеричные числа");
    this->setMinimumWidth(528);
    buttonSum = new QPushButton("Сложить два числа");
    buttonSum->setAutoDefault(false);
    buttonSum->setDefault(false);

    buttonSub = new QPushButton("Вычесть из первого второе число");
    buttonSub->setAutoDefault(false);
    buttonSub->setDefault(false);

    buttonExit = new QPushButton("Выход");
    buttonExit->setAutoDefault(false);
    buttonExit->setDefault(false);

    lineEditFirstNum = new QLineEdit();
    lineEditFirstNum->setPlaceholderText("0123456789ABCDEF");
    lineEditSecondNum = new QLineEdit();
    lineEditSecondNum->setPlaceholderText("0123456789ABCDEF");
    lineEditOutput = new QLineEdit();
    lineEditOutput->setReadOnly(true);

    labelFirstNum = new QLabel("Первое число");
    labelSecondNum = new QLabel("Второе число");
    labelOutput = new QLabel("Результат");

    mainLayout = new QGridLayout();
    mainLayout->addWidget(labelFirstNum, 0, 0);
    mainLayout->addWidget(lineEditFirstNum, 0, 1);
    mainLayout->addWidget(buttonSum, 0, 2);
    mainLayout->addWidget(labelSecondNum, 1, 0);
    mainLayout->addWidget(lineEditSecondNum, 1, 1);
    mainLayout->addWidget(buttonSub, 1, 2);
    mainLayout->setRowStretch(2, 10);
    mainLayout->addWidget(labelOutput, 3, 0);
    mainLayout->addWidget(lineEditOutput, 3, 1);
    mainLayout->addWidget(buttonExit, 3, 2);

    this->setLayout(mainLayout);

    connect(buttonSum, SIGNAL(clicked(bool)), this, SLOT(summarizeTheNumbers()));
    connect(buttonSub, SIGNAL(clicked(bool)), this, SLOT(substractTheNumbers()));
    connect(this, SIGNAL(outputString(QString)), this, SLOT(outputDataToScreen(QString)));
    connect(buttonExit, SIGNAL(clicked(bool)), this, SLOT(close()));
}

MainWin::~MainWin() {}

void MainWin::summarizeTheNumbers()
{
    if (isNumbersCorrect()){
        long long num1 = lineEditFirstNum->text().toLongLong(nullptr, 16),
            num2 = lineEditSecondNum->text().toLongLong(nullptr, 16),
            res = num1 + num2;
        emit outputString(QString::number(res, 16).toUpper());
    }
}

void MainWin::substractTheNumbers(){
    if (isNumbersCorrect()){
        long long num1 = lineEditFirstNum->text().toLongLong(nullptr, 16),
            num2 = lineEditSecondNum->text().toLongLong(nullptr, 16),
            res = num1 - num2;
        emit outputString(QString::number(res, 16).toUpper());
    }
}

void MainWin::outputDataToScreen(QString text)
{
    lineEditOutput->setText(text);
}
