#ifndef QTPROGRAMWIN_H
#define QTPROGRAMWIN_H

#include <QMainWindow>
#include <string>
namespace Ui {
class QtProgramWin;
}

class QtProgramWin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QtProgramWin(QWidget *parent = 0);
    ~QtProgramWin();
    
private:
    Ui::QtProgramWin *ui;
	double result;
	double input1;
	double input2;
	bool input1decimal;
	bool input2decimal;
	QString operation;

protected:
	bool eventFilter(QObject *o, QEvent *e);
	
public slots:
	//void inputSelect();
	void numberClicked();
	void operatorClicked();
	void equalClicked();
	void delClicked();
	void clearClicked();
	void decimalClicked();
	void operatorKeypress(char op);
	
};

#endif // QTPROGRAMWIN_H
