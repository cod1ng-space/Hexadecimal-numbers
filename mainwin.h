#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QBoxLayout>
#include <QLabel>
#include <QMessageBox>

class MainWin : public QWidget
{
    Q_OBJECT
private:
    QPushButton *buttonSum, *buttonSub, *buttonExit;
    QLineEdit *lineEditFirstNum, *lineEditSecondNum, *lineEditOutput;
    QGridLayout *mainLayout;
    QLabel *labelFirstNum, *labelSecondNum, *labelOutput;
    bool isNumbersCorrect();
public:
    MainWin(QWidget *parent = nullptr);
    ~MainWin();
    signals:
    void outputString(QString text);
public slots:
    void summarizeTheNumbers();
    void substractTheNumbers();
    void outputDataToScreen(QString text);
};
#endif // MAINWIN_H
