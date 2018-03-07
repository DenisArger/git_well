/********************************************************************************
** Form generated from reading UI file 'primewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMEWINDOW_H
#define UI_PRIMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrimeWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *newOrderButton;
    QPushButton *stockButton;
    QPushButton *clientsBaseButton;
    QPushButton *serviceClientsButtton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PrimeWindow)
    {
        if (PrimeWindow->objectName().isEmpty())
            PrimeWindow->setObjectName(QStringLiteral("PrimeWindow"));
        PrimeWindow->setWindowModality(Qt::ApplicationModal);
        PrimeWindow->resize(1029, 397);
        QFont font;
        font.setPointSize(11);
        PrimeWindow->setFont(font);
        centralwidget = new QWidget(PrimeWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        newOrderButton = new QPushButton(centralwidget);
        newOrderButton->setObjectName(QStringLiteral("newOrderButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newOrderButton->sizePolicy().hasHeightForWidth());
        newOrderButton->setSizePolicy(sizePolicy);
        newOrderButton->setMinimumSize(QSize(190, 55));
        newOrderButton->setFont(font);

        horizontalLayout->addWidget(newOrderButton);

        stockButton = new QPushButton(centralwidget);
        stockButton->setObjectName(QStringLiteral("stockButton"));
        stockButton->setMinimumSize(QSize(190, 55));
        stockButton->setFont(font);

        horizontalLayout->addWidget(stockButton);

        clientsBaseButton = new QPushButton(centralwidget);
        clientsBaseButton->setObjectName(QStringLiteral("clientsBaseButton"));
        clientsBaseButton->setMinimumSize(QSize(190, 55));
        clientsBaseButton->setFont(font);

        horizontalLayout->addWidget(clientsBaseButton);

        serviceClientsButtton = new QPushButton(centralwidget);
        serviceClientsButtton->setObjectName(QStringLiteral("serviceClientsButtton"));
        serviceClientsButtton->setMinimumSize(QSize(190, 55));
        serviceClientsButtton->setFont(font);

        horizontalLayout->addWidget(serviceClientsButtton);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(240, 0));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setUnderline(true);
        font1.setWeight(50);
        label_2->setFont(font1);
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(240, 0));
        label_3->setFont(font1);
        label_3->setFrameShape(QFrame::StyledPanel);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(240, 0));
        label_4->setFont(font1);
        label_4->setFrameShape(QFrame::StyledPanel);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(240, 0));
        label_5->setFont(font1);
        label_5->setFrameShape(QFrame::StyledPanel);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_5);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(groupBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(false);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setFont(font);

        horizontalLayout_2->addWidget(lineEdit);

        horizontalSpacer_6 = new QSpacerItem(44, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        PrimeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PrimeWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1029, 26));
        PrimeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PrimeWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PrimeWindow->setStatusBar(statusbar);

        retranslateUi(PrimeWindow);

        QMetaObject::connectSlotsByName(PrimeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PrimeWindow)
    {
        PrimeWindow->setWindowTitle(QApplication::translate("PrimeWindow", "\320\223\320\273\320\260\320\262\320\275\320\276\320\265 \320\276\320\272\320\275\320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", Q_NULLPTR));
        newOrderButton->setText(QApplication::translate("PrimeWindow", "\320\235\320\276\320\262\321\213\320\271 \320\267\320\260\320\272\320\260\320\267", Q_NULLPTR));
        stockButton->setText(QApplication::translate("PrimeWindow", "\320\241\320\272\320\273\320\260\320\264", Q_NULLPTR));
        clientsBaseButton->setText(QApplication::translate("PrimeWindow", "\320\232\320\273\320\270\320\265\320\275\321\202\321\201\320\272\320\260\321\217 \320\261\320\260\320\267\320\260", Q_NULLPTR));
        serviceClientsButtton->setText(QApplication::translate("PrimeWindow", "\320\236\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\320\265 \n"
"\320\272\320\273\320\270\320\265\320\275\321\202\320\276\320\262", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("PrimeWindow", "\320\223\320\276\321\200\321\217\321\207\320\270\320\265 \320\272\320\273\320\260\320\262\320\270\321\210\320\270", Q_NULLPTR));
        label_2->setText(QApplication::translate("PrimeWindow", "F5 ", Q_NULLPTR));
        label_3->setText(QApplication::translate("PrimeWindow", "F6 ", Q_NULLPTR));
        label_4->setText(QApplication::translate("PrimeWindow", "F7 ", Q_NULLPTR));
        label_5->setText(QApplication::translate("PrimeWindow", "F8 ", Q_NULLPTR));
        label->setText(QApplication::translate("PrimeWindow", "\320\237\321\203\321\202\321\214 \320\272 \320\221\320\224", Q_NULLPTR));
        pushButton->setText(QApplication::translate("PrimeWindow", "\320\236\320\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PrimeWindow: public Ui_PrimeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMEWINDOW_H
