#include <QtWidgets>

#include <cmath>

#include "button.h"
#include "calculator.h"

//! [0]
Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    sumInMemory = 0.0;
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    waitingForOperand = true;

    flag=1;
    flag2=1;
    zhuan=1;
    zhuan2=1;
//! [0]

//! [1]
    display = new QLineEdit("0");
//! [1] //! [2]
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);
//! [2]

//! [4]
    for (int i = 0; i < NumDigitButtons; ++i) {
        digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));
    }

    Button *pointButton = createButton(tr("."), SLOT(pointClicked()));
    Button *changeSignButton = createButton(tr("\302\261"), SLOT(changeSignClicked()));

    Button *backspaceButton = createButton(tr("Backspace"), SLOT(backspaceClicked()));
    Button *clearButton = createButton(tr("Clear"), SLOT(clear()));
    Button *clearAllButton = createButton(tr("Clear All"), SLOT(clearAll()));

    Button *clearMemoryButton = createButton(tr("MC"), SLOT(clearMemory()));
    Button *readMemoryButton = createButton(tr("MR"), SLOT(readMemory()));
    Button *setMemoryButton = createButton(tr("MS"), SLOT(setMemory()));
    Button *addToMemoryButton = createButton(tr("M+"), SLOT(addToMemory()));

    Button *divisionButton = createButton(tr("\303\267"), SLOT(multiplicativeOperatorClicked()));
    Button *timesButton = createButton(tr("\303\227"), SLOT(multiplicativeOperatorClicked()));
    Button *minusButton = createButton(tr("-"), SLOT(additiveOperatorClicked()));
    Button *plusButton = createButton(tr("+"), SLOT(additiveOperatorClicked()));

    Button *squareRootButton = createButton(tr("Sqrt"), SLOT(unaryOperatorClicked()));
    Button *powerButton = createButton(tr("x\302\262"), SLOT(unaryOperatorClicked()));
    Button *reciprocalButton = createButton(tr("1/x"), SLOT(unaryOperatorClicked()));
    Button *equalButton = createButton(tr("="), SLOT(equalClicked()));

    Button *twochangeButton=createButton(tr("(2)运算"),SLOT(twoClicked()));
    Button *sixteenchangeButton=createButton(tr("(16)运算"),SLOT(sixteenClicked()));
    Button *aButton=createButton(tr("A"),SLOT(digitClicked()));
    Button *bButton=createButton(tr("B"),SLOT(digitClicked()));
    Button *cButton=createButton(tr("C"),SLOT(digitClicked()));
    Button *dButton=createButton(tr("D"),SLOT(digitClicked()));
    Button *eButton=createButton(tr("E"),SLOT(digitClicked()));
    Button *fButton=createButton(tr("F"),SLOT(digitClicked()));
    Button *twoButton=createButton(tr("(10)转(2)"),SLOT(jzzhClicked()));
    Button *sixteenButton=createButton(tr("(10)转(16)"),SLOT(jzzhClicked()));
    Button *sinButton = createButton(tr("sin"), SLOT(unaryOperatorClicked()));
    Button *cosButton = createButton(tr("cos"), SLOT(unaryOperatorClicked()));
    Button *tanButton = createButton(tr("tan"), SLOT(unaryOperatorClicked()));
    Button *arcsinButton = createButton(tr("arcsin"), SLOT(unaryOperatorClicked()));
    Button *arccosButton = createButton(tr("arccos"), SLOT(unaryOperatorClicked()));
    Button *arctanButton = createButton(tr("arctan"), SLOT(unaryOperatorClicked()));
    Button *lnButton = createButton(tr("ln"), SLOT(unaryOperatorClicked()));
    Button *lgButton = createButton(tr("lg"), SLOT(unaryOperatorClicked()));
//! [4]

//! [5]
    QGridLayout *mainLayout = new QGridLayout;
//! [5] //! [6]
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(display, 0, 0, 1, 6);
    mainLayout->addWidget(backspaceButton, 1, 0, 1, 2);
    mainLayout->addWidget(clearButton, 1, 2, 1, 2);
    mainLayout->addWidget(clearAllButton, 1, 4, 1, 2);

    mainLayout->addWidget(clearMemoryButton, 2, 0);
    mainLayout->addWidget(readMemoryButton, 3, 0);
    mainLayout->addWidget(setMemoryButton, 4, 0);
    mainLayout->addWidget(addToMemoryButton, 5, 0);

    for (int i = 1; i < NumDigitButtons; ++i) {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(digitButtons[i], row, column);
    }

    mainLayout->addWidget(digitButtons[0], 5, 1);
    mainLayout->addWidget(pointButton, 5, 2);
    mainLayout->addWidget(changeSignButton, 5, 3);

    mainLayout->addWidget(divisionButton, 2, 4);
    mainLayout->addWidget(timesButton, 3, 4);
    mainLayout->addWidget(minusButton, 4, 4);
    mainLayout->addWidget(plusButton, 5, 4);

    mainLayout->addWidget(squareRootButton, 2, 5);
    mainLayout->addWidget(powerButton, 3, 5);
    mainLayout->addWidget(reciprocalButton, 4, 5);
    mainLayout->addWidget(equalButton, 5, 5);

    mainLayout->addWidget(twochangeButton,0,7);
    mainLayout->addWidget(sixteenchangeButton,1,7);
    mainLayout->addWidget(aButton,0,6);
    mainLayout->addWidget(bButton,1,6);
    mainLayout->addWidget(cButton,2,6);
    mainLayout->addWidget(dButton,3,6);
    mainLayout->addWidget(eButton,4,6);
    mainLayout->addWidget(fButton,5,6);
    mainLayout->addWidget(twoButton,2,7);
    mainLayout->addWidget(sixteenButton,3,7);
    mainLayout->addWidget(sinButton,0,8);
    mainLayout->addWidget(cosButton,1,8);
    mainLayout->addWidget(tanButton,2,8);
    mainLayout->addWidget(arcsinButton,3,8);
    mainLayout->addWidget(arccosButton,4,8);
    mainLayout->addWidget(arctanButton,5,8);
    mainLayout->addWidget(lnButton,4,7);
    mainLayout->addWidget(lgButton,5,7);
    setLayout(mainLayout);

    setWindowTitle(tr("宇宙第一美少女的计算器"));
}
//! [6]

void Calculator::twoClicked(){
    if(flag) flag=0;
    else flag=1;
}
void Calculator::sixteenClicked(){
    if(flag2) flag2=0;
    else flag2=1;
}
void Calculator::jzzhClicked(){
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
    if (clickedOperator == tr("(10)转(2)")) {
        if(zhuan==1){
            zhuan=0;
            int a[16]={0},c[14]={0},b[16]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
            int t=0,m=operand,x=0;
            double n=operand-m;
            if(n==0.0){
                for(int i=15;i>0;i--){
                    if(operand>=b[i]){
                        a[i]=operand/b[i];
                        operand=operand-b[i];
                    }
                    else if(operand<b[i]) a[i] =0;
                    if(a[i]!=0&&t==0) t=i;
                }
                if(t==0) display->setText(QString::number(0));
                if(t!=0){
                    display->setText(QString::number(1));
                for(int i=t-1;i>0;i--){
                    display->setText(display->text()+QString::number(a[i]));
                }
            }}
            if(n!=0.0){
                for(int i=15;i>0;i--){
                    if(m>=b[i]){
                        a[i]=m/b[i];
                        m=m-b[i];
                    }
                    else if(m<b[i]) a[i]=0;
                    if(a[i]!=0&&t==0) t=i;
                }
                if(t==0) display->setText(QString::number(0));
                if(t!=0){
                    display->setText(QString::number(1));
                for(int i=t-1;i>0;i--){
                    display->setText(display->text()+QString::number(a[i]));
                }
            }
                display->setText(display->text()+tr("."));
                for(int i=1;i<14;i++){
                    if(n>=pow(1.0/2,i)){
                        c[i]=1;
                        n=n-pow(1.0/2,i);
                    }
                    else if(n<pow(1.0/2,i)) c[i]=0;
                    if(c[i]!=0) x=i;
                    if(n==0) break;
                }
                if(x==0) display->setText(display->text()+QString::number(0));
                if(x!=0){
                    for(int i=1;i<=x;i++){
                        display->setText(display->text()+QString::number(c[i]));
                    }
                }
        }
        }
        else{
            zhuan=1;
            operand=0;
            int t=0;
            double a[16]={0},b[16]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
            QString zfc=display->text();
            int len=zfc.length();
            char *str;
            QByteArray middle=zfc.toLatin1();
            str = middle.data();
            for(int i=len;i>0;i--){
                a[i]=str[i-1]-'0';
                if(str[i-1]=='.') t=i;
            }
            if(t==0){
            for(int i=15;i>0;i--){
                operand=operand+a[i]*b[len-i+1];
            }}
            if(t!=0){
                for(int i=1;i<t;i++){
                    operand=operand+a[i]*b[t-i];
                }
                for(int i=t+1,j=1;i<=len;i++,j++){
                    operand=operand+a[i]*pow(1.0/2,j);
                }
            }
            display->setText(QString::number(operand));
        }
    }
    if (clickedOperator == tr("(10)转(16)")){
        if(zhuan2==1){
            zhuan2=0;
            int a[14]={0},c[11]={0};
            int t=0,m=operand,x=0;
            double n=operand-m;
            if(n==0.0){
                for(int i=13;i>0;i--){
                    if(operand>=pow(16,i-1)){
                        a[i]=operand/pow(16,i-1);
                        operand=operand-a[i]*pow(16,i-1);
                    }
                    else if(operand<pow(16,i-1)) a[i]=0;
                    if(a[i]!=0&&t==0) t=i;
                }
                if(t==0) display->setText(QString::number(0));
                if(t!=0){
                    if(a[t]<10) display->setText(QString::number(a[t]));
                    else if(a[t]==10) display->setText(tr("A"));
                    else if(a[t]==11) display->setText(tr("B"));
                    else if(a[t]==12) display->setText(tr("C"));
                    else if(a[t]==13) display->setText(tr("D"));
                    else if(a[t]==14) display->setText(tr("E"));
                    else if(a[t]==15) display->setText(tr("F"));
                    for(int i=t-1;i>0;i--){
                        if(a[i]<10) display->setText(display->text()+QString::number(a[i]));
                        else if(a[i]==10) display->setText(display->text()+tr("A"));
                        else if(a[i]==11) display->setText(display->text()+tr("B"));
                        else if(a[i]==12) display->setText(display->text()+tr("C"));
                        else if(a[i]==13) display->setText(display->text()+tr("D"));
                        else if(a[i]==14) display->setText(display->text()+tr("E"));
                        else if(a[i]==15) display->setText(display->text()+tr("F"));
                    }
                }
            }
            if(n!=0.0){
                for(int i=13;i>0;i--){
                    if(m>=pow(16,i-1)){
                        a[i]=m/pow(16,i-1);
                        m=m-a[i]*pow(16,i-1);
                    }
                    else if(m<pow(16,i-1)) a[i]=0;
                    if(a[i]!=0&&t==0) t=i;
                }
                if(t==0) display->setText(QString::number(0));
                if(t!=0){
                    if(a[t]<10) display->setText(QString::number(a[t]));
                    else if(a[t]==10) display->setText(tr("A"));
                    else if(a[t]==11) display->setText(tr("B"));
                    else if(a[t]==12) display->setText(tr("C"));
                    else if(a[t]==13) display->setText(tr("D"));
                    else if(a[t]==14) display->setText(tr("E"));
                    else if(a[t]==15) display->setText(tr("F"));
                    for(int i=t-1;i>0;i--){
                        if(a[i]<10) display->setText(display->text()+QString::number(a[i]));
                        else if(a[i]==10) display->setText(display->text()+tr("A"));
                        else if(a[i]==11) display->setText(display->text()+tr("B"));
                        else if(a[i]==12) display->setText(display->text()+tr("C"));
                        else if(a[i]==13) display->setText(display->text()+tr("D"));
                        else if(a[i]==14) display->setText(display->text()+tr("E"));
                        else if(a[i]==15) display->setText(display->text()+tr("F"));
                    }
                }
                display->setText(display->text()+tr("."));
                for(int i=1;i<11;i++){
                    if(n>=pow(1.0/16,i)){
                        c[i]=n/pow(1.0/16,i);
                        n=n-c[i]*pow(1.0/16,i);
                    }
                    else if(n<pow(1.0/16,i)) c[i]=0;
                    if(c[i]!=0) x=i;
                    if(n==0) break;
                }
                if(x==0) display->setText(display->text()+QString::number(0));
                if(x!=0){
                    for(int i=1;i<=x;i++){
                        if(c[i]<10) display->setText(display->text()+QString::number(c[i]));
                        else if(c[i]==10) display->setText(display->text()+tr("A"));
                        else if(c[i]==11) display->setText(display->text()+tr("B"));
                        else if(c[i]==12) display->setText(display->text()+tr("C"));
                        else if(c[i]==13) display->setText(display->text()+tr("D"));
                        else if(c[i]==14) display->setText(display->text()+tr("E"));
                        else if(c[i]==15) display->setText(display->text()+tr("F"));
                    }
                }
            }

        }
        else{
            zhuan2=1;
                operand=0;
                int t=0;
                int a[16]={0};
                QString zfc=display->text();
                int len=zfc.length();
                char *str;
                QByteArray middle=zfc.toLatin1();
                str = middle.data();
                for(int i=len;i>0;i--){
                    if(str[i-1]>='A'&&str[i-1]<='F') a[i]=str[i-1]-'A'+10;
                    else a[i]=str[i-1]-'0';
                    if(str[i-1]=='.') t=i;
                }
                if(t==0){
                    for(int i=1;i<=len;i++){
                        operand=operand+a[i]*pow(16,len-i);
                    }
                }
                if(t!=0){
                    for(int i=1;i<t;i++){
                        operand=operand+a[i]*pow(16,t-i-1);
                    }
                    for(int i=t+1,j=1;i<=len;i++,j++){
                        operand=operand+a[i]*pow(1.0/16,j);
                    }
                }
                display->setText(QString::number(operand));
        }
    }
}
//! [7]
void Calculator::digitClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    int digitValue;
    if(clickedButton->text()=="A") digitValue=10;
    else if(clickedButton->text()=="B") digitValue=11;
    else if(clickedButton->text()=="C") digitValue=12;
    else if(clickedButton->text()=="D") digitValue=13;
    else if(clickedButton->text()=="E") digitValue=14;
    else if(clickedButton->text()=="F") digitValue=15;
    else digitValue = clickedButton->text().toInt();
    if (display->text() == "0" && digitValue == 0.0)
        return;

    if (waitingForOperand) {
        display->clear();
        waitingForOperand = false;
    }

    if(flag==0){
        if(digitValue>1){
            abortOperation();
            return;
        }
    }
    if(flag2==1){
        if(digitValue>9){
            abortOperation();
            return;
        }
    }

    if(digitValue==10) display->setText(display->text()+tr("A"));
    else if(digitValue==11) display->setText(display->text()+tr("B"));
    else if(digitValue==12) display->setText(display->text()+tr("C"));
    else if(digitValue==13) display->setText(display->text()+tr("D"));
    else if(digitValue==14) display->setText(display->text()+tr("E"));
    else if(digitValue==15) display->setText(display->text()+tr("F"));
    else display->setText(display->text()+QString::number(digitValue));
}
//! [7]

//! [8]
void Calculator::unaryOperatorClicked()
//! [8] //! [9]
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
    double result = 0.0;

    if(flag==0){
        abortOperation();
        return;
    }
    if(flag2==0){
        abortOperation();
        return;
    }

    if (clickedOperator == tr("Sqrt")) {
        if (operand < 0.0) {
            abortOperation();
            return;
        }
        result = std::sqrt(operand);
    } else if (clickedOperator == tr("x\302\262")) {
        result = std::pow(operand, 2.0);
    } else if (clickedOperator == tr("1/x")) {
        if (operand == 0.0) {
            abortOperation();
            return;
        }
        result = 1.0 / operand;
    }

    else if(clickedOperator == tr("sin")){//zi~
        result=sin(operand);
    }
    else if(clickedOperator == tr("cos")){
        result=cos(operand);
    }
    else if(clickedOperator == tr("tan")){
        if(operand==1.0){
            abortOperation();
            return;
        }
        result=tan(operand);
    }
    else if(clickedOperator == tr("arcsin")){
        result=asin(operand);
    }
    else if(clickedOperator == tr("arccos")){
        result=acos(operand);
    }
    else if(clickedOperator == tr("arctan")){
        result=atan(operand);
    }
    else if(clickedOperator == tr("ln")){
        if(operand<0){
            abortOperation();
            return;
        }
        result=qLn(operand);
    }
    else if(clickedOperator == tr("lg")){
        if(operand<0){
            abortOperation();
            return;
        }
        result=qLn(operand)/qLn(10);
    }
    display->setText(QString::number(result));
    waitingForOperand = true;
}
//! [9]

//! [10]
void Calculator::additiveOperatorClicked()
//! [10] //! [11]
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    if(flag==0){
        operand=0;
        int t=0;
        double a[16]={0},b[16]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
        QString zfc=display->text();
        int len=zfc.length();
        char *str;
        QByteArray middle=zfc.toLatin1();
        str = middle.data();
        for(int i=len;i>0;i--){
            a[i]=str[i-1]-'0';
            if(str[i-1]=='.') t=i;
        }
        if(t==0){
        for(int i=15;i>0;i--){
            operand=operand+a[i]*b[len-i+1];
        }}
        if(t!=0){
            for(int i=1;i<t;i++){
                operand=operand+a[i]*b[t-i];
            }
            for(int i=t+1,j=1;i<=len;i++,j++){
                operand=operand+a[i]*pow(1.0/2,j);
            }
        }
    }
    if(flag2==0){
        operand=0;
        int t=0;
        int a[16]={0};
        QString zfc=display->text();
        int len=zfc.length();
        char *str;
        QByteArray middle=zfc.toLatin1();
        str = middle.data();
        for(int i=len;i>0;i--){
            if(str[i-1]>='A'&&str[i-1]<='F') a[i]=str[i-1]-'A'+10;
            else a[i]=str[i-1]-'0';
            if(str[i-1]=='.') t=i;
        }
        if(t==0){
            for(int i=1;i<=len;i++){
                operand=operand+a[i]*pow(16,len-i);
            }
        }
        if(t!=0){
            for(int i=1;i<t;i++){
                operand=operand+a[i]*pow(16,t-i-1);
            }
            for(int i=t+1,j=1;i<=len;i++,j++){
                operand=operand+a[i]*pow(1.0/16,j);
            }
        }
    }

//! [11] //! [12]
    if (!pendingMultiplicativeOperator.isEmpty()) {
//! [12] //! [13]
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(factorSoFar));
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }

//! [13] //! [14]
    if (!pendingAdditiveOperator.isEmpty()) {
//! [14] //! [15]
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(sumSoFar));
    } else {
        sumSoFar = operand;
    }

//! [15] //! [16]
    pendingAdditiveOperator = clickedOperator;
//! [16] //! [17]
    waitingForOperand = true;
}
//! [17]

//! [18]
void Calculator::multiplicativeOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    if(flag==0){
        operand=0;
        int t=0;
        double a[16]={0},b[16]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
        QString zfc=display->text();
        int len=zfc.length();
        char *str;
        QByteArray middle=zfc.toLatin1();
        str = middle.data();
        for(int i=len;i>0;i--){
            a[i]=str[i-1]-'0';
            if(str[i-1]=='.') t=i;
        }
        if(t==0){
        for(int i=15;i>0;i--){
            operand=operand+a[i]*b[len-i+1];
        }}
        if(t!=0){
            for(int i=1;i<t;i++){
                operand=operand+a[i]*b[t-i];
            }
            for(int i=t+1,j=1;i<=len;i++,j++){
                operand=operand+a[i]*pow(1.0/2,j);
            }
        }
    }
    if(flag2==0){
        operand=0;
        int t=0;
        int a[16]={0};
        QString zfc=display->text();
        int len=zfc.length();
        char *str;
        QByteArray middle=zfc.toLatin1();
        str = middle.data();
        for(int i=len;i>0;i--){
            if(str[i-1]>='A'&&str[i-1]<='F') a[i]=str[i-1]-'A'+10;
            else a[i]=str[i-1]-'0';
            if(str[i-1]=='.') t=i;
        }
        if(t==0){
            for(int i=1;i<=len;i++){
                operand=operand+a[i]*pow(16,len-i);
            }
        }
        if(t!=0){
            for(int i=1;i<t;i++){
                operand=operand+a[i]*pow(16,t-i-1);
            }
            for(int i=t+1,j=1;i<=len;i++,j++){
                operand=operand+a[i]*pow(1.0/16,j);
            }
        }
    }

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicativeOperator = clickedOperator;
    waitingForOperand = true;
}
//! [18]

//! [20]
void Calculator::equalClicked()
{
    double operand = display->text().toDouble();

    if(flag==0){
        operand=0;
        int t=0;
        double a[16]={0},b[16]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
        QString zfc=display->text();
        int len=zfc.length();
        char *str;
        QByteArray middle=zfc.toLatin1();
        str = middle.data();
        for(int i=len;i>0;i--){
            a[i]=str[i-1]-'0';
            if(str[i-1]=='.') t=i;
        }
        if(t==0){
        for(int i=15;i>0;i--){
            operand=operand+a[i]*b[len-i+1];
        }}
        if(t!=0){
            for(int i=1;i<t;i++){
                operand=operand+a[i]*b[t-i];
            }
            for(int i=t+1,j=1;i<=len;i++,j++){
                operand=operand+a[i]*pow(1.0/2,j);
            }
        }
    }
    if(flag2==0){
        operand=0;
        int t=0;
        int a[16]={0};
        QString zfc=display->text();
        int len=zfc.length();
        char *str;
        QByteArray middle=zfc.toLatin1();
        str = middle.data();
        for(int i=len;i>0;i--){
            if(str[i-1]>='A'&&str[i-1]<='F') a[i]=str[i-1]-'A'+10;
            else a[i]=str[i-1]-'0';
            if(str[i-1]=='.') t=i;
        }
        if(t==0){
            for(int i=1;i<=len;i++){
                operand=operand+a[i]*pow(16,len-i);
            }
        }
        if(t!=0){
            for(int i=1;i<t;i++){
                operand=operand+a[i]*pow(16,t-i-1);
            }
            for(int i=t+1,j=1;i<=len;i++,j++){
                operand=operand+a[i]*pow(1.0/16,j);
            }
        }
    }

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        pendingAdditiveOperator.clear();
    } else {
        sumSoFar = operand;
    }

    if(flag==0){
            int a[16]={0},c[14]={0},b[16]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
            int t=0,m=sumSoFar,x=0;
            double n=sumSoFar-m;
            if(n==0.0){
                for(int i=15;i>0;i--){
                    if(sumSoFar>=b[i]){
                        a[i]=sumSoFar/b[i];
                        sumSoFar=sumSoFar-b[i];
                    }
                    else if(sumSoFar<b[i]) a[i] =0;
                    if(a[i]!=0&&t==0) t=i;
                }
                if(t==0) display->setText(QString::number(0));
                if(t!=0){
                    display->setText(QString::number(1));
                for(int i=t-1;i>0;i--){
                    display->setText(display->text()+QString::number(a[i]));
                }
            }}
            if(n!=0.0){
                for(int i=15;i>0;i--){
                    if(m>=b[i]){
                        a[i]=m/b[i];
                        m=m-b[i];
                    }
                    else if(m<b[i]) a[i]=0;
                    if(a[i]!=0&&t==0) t=i;
                }
                if(t==0) display->setText(QString::number(0));
                if(t!=0){
                    display->setText(QString::number(1));
                for(int i=t-1;i>0;i--){
                    display->setText(display->text()+QString::number(a[i]));
                }
            }
                display->setText(display->text()+tr("."));
                for(int i=1;i<14;i++){
                    if(n>=pow(1.0/2,i)){
                        c[i]=1;
                        n=n-pow(1.0/2,i);
                    }
                    else if(n<pow(1.0/2,i)) c[i]=0;
                    if(c[i]!=0) x=i;
                    if(n==0) break;
                }
                if(x==0) display->setText(QString::number(0));
                if(x!=0){
                    for(int i=1;i<=x;i++){
                        display->setText(display->text()+QString::number(c[i]));
                    }
                }
        }}

   else if(flag2==0){
        int a[14]={0},c[11]={0};
        int t=0,m=sumSoFar,x=0;
        double n=sumSoFar-m;
        if(n==0.0){
            for(int i=13;i>0;i--){
                if(sumSoFar>=pow(16,i-1)){
                    a[i]=sumSoFar/pow(16,i-1);
                    sumSoFar=sumSoFar-a[i]*pow(16,i-1);
                }
                else if(sumSoFar<pow(16,i-1)) a[i]=0;
                if(a[i]!=0&&t==0) t=i;
            }
            if(t==0) display->setText(QString::number(0));
            if(t!=0){
                if(a[t]<10) display->setText(QString::number(a[t]));
                else if(a[t]==10) display->setText(tr("A"));
                else if(a[t]==11) display->setText(tr("B"));
                else if(a[t]==12) display->setText(tr("C"));
                else if(a[t]==13) display->setText(tr("D"));
                else if(a[t]==14) display->setText(tr("E"));
                else if(a[t]==15) display->setText(tr("F"));
                for(int i=t-1;i>0;i--){
                    if(a[i]<10) display->setText(display->text()+QString::number(a[i]));
                    else if(a[i]==10) display->setText(display->text()+tr("A"));
                    else if(a[i]==11) display->setText(display->text()+tr("B"));
                    else if(a[i]==12) display->setText(display->text()+tr("C"));
                    else if(a[i]==13) display->setText(display->text()+tr("D"));
                    else if(a[i]==14) display->setText(display->text()+tr("E"));
                    else if(a[i]==15) display->setText(display->text()+tr("F"));
                }
            }
        }
        if(n!=0.0){
            for(int i=13;i>0;i--){
                if(m>=pow(16,i-1)){
                    a[i]=m/pow(16,i-1);
                    m=m-a[i]*pow(16,i-1);
                }
                else if(m<pow(16,i-1)) a[i]=0;
                if(a[i]!=0&&t==0) t=i;
            }
            if(t==0) display->setText(QString::number(0));
            if(t!=0){
                if(a[t]<10) display->setText(QString::number(a[t]));
                else if(a[t]==10) display->setText(tr("A"));
                else if(a[t]==11) display->setText(tr("B"));
                else if(a[t]==12) display->setText(tr("C"));
                else if(a[t]==13) display->setText(tr("D"));
                else if(a[t]==14) display->setText(tr("E"));
                else if(a[t]==15) display->setText(tr("F"));
                for(int i=t-1;i>0;i--){
                    if(a[i]<10) display->setText(display->text()+QString::number(a[i]));
                    else if(a[i]==10) display->setText(display->text()+tr("A"));
                    else if(a[i]==11) display->setText(display->text()+tr("B"));
                    else if(a[i]==12) display->setText(display->text()+tr("C"));
                    else if(a[i]==13) display->setText(display->text()+tr("D"));
                    else if(a[i]==14) display->setText(display->text()+tr("E"));
                    else if(a[i]==15) display->setText(display->text()+tr("F"));
                }
            }
            display->setText(display->text()+tr("."));
            for(int i=1;i<11;i++){
                if(n>=pow(1.0/16,i)){
                    c[i]=n/pow(1.0/16,i);
                    n=n-c[i]*pow(1.0/16,i);
                }
                else if(n<pow(1.0/16,i)) c[i]=0;
                if(c[i]!=0) x=i;
                if(n==0) break;
            }
            if(x==0) display->setText(display->text()+QString::number(0));
            if(x!=0){
                for(int i=1;i<=x;i++){
                    if(c[i]<10) display->setText(display->text()+QString::number(c[i]));
                    else if(c[i]==10) display->setText(display->text()+tr("A"));
                    else if(c[i]==11) display->setText(display->text()+tr("B"));
                    else if(c[i]==12) display->setText(display->text()+tr("C"));
                    else if(c[i]==13) display->setText(display->text()+tr("D"));
                    else if(c[i]==14) display->setText(display->text()+tr("E"));
                    else if(c[i]==15) display->setText(display->text()+tr("F"));
                }
            }
        }
    }

    else display->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    waitingForOperand = true;
}
//! [20]

//! [22]
void Calculator::pointClicked()
{
    if (waitingForOperand)
        display->setText("0");
    if (!display->text().contains('.'))
        display->setText(display->text() + tr("."));
    waitingForOperand = false;
}
//! [22]

//! [24]
void Calculator::changeSignClicked()
{
    QString text = display->text();
    double value = text.toDouble();

    if(flag==0){
        abortOperation();
        return;
    }
    if(flag2==0){
        abortOperation();
        return;
    }

    if (value > 0.0) {
        text.prepend(tr("-"));
    } else if (value < 0.0) {
        text.remove(0, 1);
    }
    display->setText(text);
}
//! [24]

//! [26]
void Calculator::backspaceClicked()
{
    if (waitingForOperand)
        return;

    QString text = display->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    display->setText(text);
}
//! [26]

//! [28]
void Calculator::clear()
{
    if (waitingForOperand)
        return;

    display->setText("0");
    waitingForOperand = true;
}
//! [28]

//! [30]
void Calculator::clearAll()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    display->setText("0");
    waitingForOperand = true;
}
//! [30]

//! [32]
void Calculator::clearMemory()
{
    sumInMemory = 0.0;
}

void Calculator::readMemory()
{
    display->setText(QString::number(sumInMemory));
    waitingForOperand = true;
}

void Calculator::setMemory()
{
    equalClicked();
    sumInMemory = display->text().toDouble();
}

void Calculator::addToMemory()
{
    equalClicked();
    sumInMemory += display->text().toDouble();
}
//! [32]
//! [34]
Button *Calculator::createButton(const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}
//! [34]

//! [36]
void Calculator::abortOperation()
{
    clearAll();
    display->setText(tr("####"));
}
//! [36]

//! [38]
bool Calculator::calculate(double rightOperand, const QString &pendingOperator)
{
    if (pendingOperator == tr("+")) {
        sumSoFar += rightOperand;
    } else if (pendingOperator == tr("-")) {
        sumSoFar -= rightOperand;
    } else if (pendingOperator == tr("\303\227")) {
        factorSoFar *= rightOperand;
    } else if (pendingOperator == tr("\303\267")) {
        if (rightOperand == 0.0)
            return false;
        factorSoFar /= rightOperand;
    }
    return true;
}
//! [38]
