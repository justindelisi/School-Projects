#include "qtprogramwin.h"
#include "ui_qtprogramwin.h"
#include <QKeyEvent>
#include <QDoubleValidator>
#include<math.h>


QtProgramWin::QtProgramWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtProgramWin)
{
    ui->setupUi(this);
	result = 0.0;
	input1 = 0.0;
	input2 = 0.0;
	input1decimal = false;
	input2decimal = false;

	//validator for inputs only allowing doubles
	ui->input1->setValidator(new QDoubleValidator);
	ui->input2->setValidator(new QDoubleValidator);

	//event filter for handling keypress
	ui->centralWidget->installEventFilter(this);

	//turn off focus on all buttons in app
	ui->one->setFocusPolicy(Qt::NoFocus);
	ui->two->setFocusPolicy(Qt::NoFocus);
	ui->three->setFocusPolicy(Qt::NoFocus);
	ui->four->setFocusPolicy(Qt::NoFocus);
	ui->five->setFocusPolicy(Qt::NoFocus);
	ui->six->setFocusPolicy(Qt::NoFocus);
	ui->seven->setFocusPolicy(Qt::NoFocus);
	ui->eight->setFocusPolicy(Qt::NoFocus);
	ui->nine->setFocusPolicy(Qt::NoFocus);
	ui->zero->setFocusPolicy(Qt::NoFocus);
	ui->clear->setFocusPolicy(Qt::NoFocus);
	ui->del->setFocusPolicy(Qt::NoFocus);
	ui->decimal->setFocusPolicy(Qt::NoFocus);
	ui->equals->setFocusPolicy(Qt::NoFocus);
	ui->division->setFocusPolicy(Qt::NoFocus);
	ui->multiply->setFocusPolicy(Qt::NoFocus);
	ui->plus->setFocusPolicy(Qt::NoFocus);
	ui->minus->setFocusPolicy(Qt::NoFocus);
	ui->squareroot->setFocusPolicy(Qt::NoFocus);

	//clear and delete clicks
	connect(ui->clear, SIGNAL(clicked()), this, SLOT(clearClicked()));
	connect(ui->del, SIGNAL(clicked()), this, SLOT(delClicked()));

	// for all the digit clicks
	connect(ui->one, SIGNAL(clicked()), this, SLOT(numberClicked()));
	connect(ui->two, SIGNAL(clicked()), this, SLOT(numberClicked()));
	connect(ui->three, SIGNAL(clicked()), this, SLOT(numberClicked()));
	connect(ui->four, SIGNAL(clicked()), this, SLOT(numberClicked()));
	connect(ui->five, SIGNAL(clicked()), this, SLOT(numberClicked()));
	connect(ui->six, SIGNAL(clicked()), this, SLOT(numberClicked()));
	connect(ui->seven, SIGNAL(clicked()), this, SLOT(numberClicked()));
	connect(ui->eight, SIGNAL(clicked()), this, SLOT(numberClicked()));
	connect(ui->nine, SIGNAL(clicked()), this, SLOT(numberClicked()));
	connect(ui->zero, SIGNAL(clicked()), this, SLOT(numberClicked()));

	//operation clicks
	connect(ui->plus, SIGNAL(clicked()), this, SLOT(operatorClicked()));
	connect(ui->minus, SIGNAL(clicked()), this, SLOT(operatorClicked()));
	connect(ui->multiply, SIGNAL(clicked()), this, SLOT(operatorClicked()));
	connect(ui->division, SIGNAL(clicked()), this, SLOT(operatorClicked()));
	connect(ui->squareroot, SIGNAL(clicked()), this, SLOT(operatorClicked()));

	//decimal clicked
	connect(ui->decimal, SIGNAL(clicked()), this, SLOT(decimalClicked()));

	//equals clicked
	connect(ui->equals, SIGNAL(clicked()), this, SLOT(equalClicked()));
	
}

QtProgramWin::~QtProgramWin()
{
    delete ui;
}

//adds numbers to current text box
void QtProgramWin::numberClicked()
{
	QPushButton *clicked = qobject_cast<QPushButton *>(sender());
	QString value = clicked->text();
	if (ui->input1->hasFocus())
		ui->input1->setText(ui->input1->displayText() + value);
	else if (ui->input2->hasFocus())
		ui->input2->setText(ui->input2->displayText() + value);
}

void QtProgramWin:: operatorClicked()
{
	QPushButton *clicked = qobject_cast<QPushButton*>(sender());
	operation = clicked->text();
	ui->operation->setText(operation);
	ui->input2->setFocus();
}

void QtProgramWin::operatorKeypress(char op)
{
	operation = op;
	ui->operation->setText(operation);
	ui->input2->setFocus();
}

void QtProgramWin::equalClicked()
{
	input1 = ui->input1->text().toDouble();
	input2 = ui->input2->text().toDouble();

	if (operation == ui->plus->text())
		result = input1 + input2;
	else if (operation == ui->minus->text())
		result = input1 - input2;
	else if (operation == ui->multiply->text())
		result = input1 * input2;
	else if (operation == ui->division->text())
		result = input1 / input2;
	else if (operation == ui->squareroot->text())
		result = sqrt(input1);
	ui->result->setText(QString::number(result));
}

void QtProgramWin::delClicked()
{
	if (ui->input1->hasFocus())
		ui->input1->backspace();
	else if (ui->input2->hasFocus())
		ui->input2->backspace();
}

void QtProgramWin::clearClicked()
{
	ui->input1->clear();
	ui->input2->clear();
	ui->result->clear();
	input1 = 0.0;
	input2 = 0.0;
	result = 0.0;
	input1decimal = false;
	input2decimal = false;
	operation = "";
	ui->operation->setText("");
	ui->input1->setFocus();
}

void QtProgramWin::decimalClicked()
{
	if (ui->input1->hasFocus() && input1decimal == false)
	{
		ui->input1->setText(ui->input1->text() + ".");
		input1decimal = true;
	}
	else if (ui->input2->hasFocus() && input2decimal == false)
	{
		ui->input2->setText(ui->input2->text() + ".");
		input2decimal = true;
	}
		
}

bool QtProgramWin::eventFilter(QObject *o, QEvent *e)
{
	if (e->type() == QEvent::KeyRelease)
	{
		QKeyEvent* key = static_cast<QKeyEvent *>(e);
		switch (key->key())
		{
			case Qt::Key_Enter:
			case Qt::Key_Return:
			case Qt::Key_Equal:
				equalClicked();
				return true;
			case Qt::Key_Asterisk:
				operatorKeypress('x');
				return true;
			case Qt::Key_Plus:
				operatorKeypress('+');
				return true;
			case Qt::Key_Minus:
				operatorKeypress('-');
				return true;
			case Qt::Key_Slash:
				operatorKeypress('÷');
				return true;
		}
	}
	return false;
}






