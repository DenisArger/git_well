/********************************************************************************
** Form generated from reading UI file 'diameter.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAMETER_H
#define UI_DIAMETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_diameter
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *dataBegindateEdit;
    QLabel *label_2;
    QDateEdit *dataEnddateEdit;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QPushButton *clearButtton;
    QPushButton *editInstrumentsButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addInstrButton;
    QPushButton *EditInstrButton;
    QPushButton *DeleteInstrButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *historyTextEdit;
    QTextEdit *legendTextEdit;
    QSpacerItem *verticalSpacer_3;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *diameter)
    {
        if (diameter->objectName().isEmpty())
            diameter->setObjectName(QStringLiteral("diameter"));
        diameter->resize(1124, 770);
        QFont font;
        font.setPointSize(11);
        diameter->setFont(font);
        centralwidget = new QWidget(diameter);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, -1, 9);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        dataBegindateEdit = new QDateEdit(centralwidget);
        dataBegindateEdit->setObjectName(QStringLiteral("dataBegindateEdit"));
        dataBegindateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dataBegindateEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        dataEnddateEdit = new QDateEdit(centralwidget);
        dataEnddateEdit->setObjectName(QStringLiteral("dataEnddateEdit"));
        dataEnddateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dataEnddateEdit);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(389, 80));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 383, 62));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(120, 60));

        horizontalLayout_3->addWidget(pushButton);

        clearButtton = new QPushButton(layoutWidget);
        clearButtton->setObjectName(QStringLiteral("clearButtton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(clearButtton->sizePolicy().hasHeightForWidth());
        clearButtton->setSizePolicy(sizePolicy1);
        clearButtton->setMinimumSize(QSize(120, 60));

        horizontalLayout_3->addWidget(clearButtton);

        editInstrumentsButton = new QPushButton(layoutWidget);
        editInstrumentsButton->setObjectName(QStringLiteral("editInstrumentsButton"));
        sizePolicy1.setHeightForWidth(editInstrumentsButton->sizePolicy().hasHeightForWidth());
        editInstrumentsButton->setSizePolicy(sizePolicy1);
        editInstrumentsButton->setMinimumSize(QSize(120, 60));
        editInstrumentsButton->setMaximumSize(QSize(120, 120));

        horizontalLayout_3->addWidget(editInstrumentsButton);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(400, 80));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        addInstrButton = new QPushButton(groupBox_2);
        addInstrButton->setObjectName(QStringLiteral("addInstrButton"));
        addInstrButton->setMinimumSize(QSize(120, 60));

        horizontalLayout_4->addWidget(addInstrButton);

        EditInstrButton = new QPushButton(groupBox_2);
        EditInstrButton->setObjectName(QStringLiteral("EditInstrButton"));
        EditInstrButton->setMinimumSize(QSize(120, 60));

        horizontalLayout_4->addWidget(EditInstrButton);

        DeleteInstrButton = new QPushButton(groupBox_2);
        DeleteInstrButton->setObjectName(QStringLiteral("DeleteInstrButton"));
        DeleteInstrButton->setMinimumSize(QSize(120, 60));

        horizontalLayout_4->addWidget(DeleteInstrButton);


        horizontalLayout->addWidget(groupBox_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy2);
        tableView->setMinimumSize(QSize(0, 150));
        QFont font1;
        font1.setPointSize(12);
        tableView->setFont(font1);

        verticalLayout_2->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        historyTextEdit = new QTextEdit(centralwidget);
        historyTextEdit->setObjectName(QStringLiteral("historyTextEdit"));
        sizePolicy2.setHeightForWidth(historyTextEdit->sizePolicy().hasHeightForWidth());
        historyTextEdit->setSizePolicy(sizePolicy2);
        historyTextEdit->setMinimumSize(QSize(0, 150));
        historyTextEdit->setMaximumSize(QSize(16777215, 298));
        historyTextEdit->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(historyTextEdit);

        legendTextEdit = new QTextEdit(centralwidget);
        legendTextEdit->setObjectName(QStringLiteral("legendTextEdit"));
        legendTextEdit->setMinimumSize(QSize(0, 40));
        legendTextEdit->setMaximumSize(QSize(16777215, 40));
        legendTextEdit->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(legendTextEdit);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        verticalLayout_2->addLayout(verticalLayout);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy3);
        closeButton->setMinimumSize(QSize(140, 60));
        closeButton->setMaximumSize(QSize(140, 60));

        verticalLayout_2->addWidget(closeButton, 0, Qt::AlignRight|Qt::AlignBottom);

        diameter->setCentralWidget(centralwidget);
        tableView->raise();
        closeButton->raise();
        menubar = new QMenuBar(diameter);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1124, 26));
        diameter->setMenuBar(menubar);
        statusbar = new QStatusBar(diameter);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        diameter->setStatusBar(statusbar);

        retranslateUi(diameter);

        QMetaObject::connectSlotsByName(diameter);
    } // setupUi

    void retranslateUi(QMainWindow *diameter)
    {
        diameter->setWindowTitle(QApplication::translate("diameter", "\320\243\321\207\320\265\321\202 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\276\320\262", Q_NULLPTR));
        label->setText(QApplication::translate("diameter", "\320\241", Q_NULLPTR));
        label_2->setText(QApplication::translate("diameter", "\320\237\320\276", Q_NULLPTR));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("diameter", "\320\237\320\276\321\201\321\207\320\270\321\202\320\260\321\202\321\214", Q_NULLPTR));
        clearButtton->setText(QApplication::translate("diameter", "\320\241\320\261\321\200\320\276\321\201 ", Q_NULLPTR));
        editInstrumentsButton->setText(QApplication::translate("diameter", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \n"
"\320\276\321\201\321\202\320\260\321\202\320\276\320\272", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        addInstrButton->setText(QApplication::translate("diameter", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        EditInstrButton->setText(QApplication::translate("diameter", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
        DeleteInstrButton->setText(QApplication::translate("diameter", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        closeButton->setText(QApplication::translate("diameter", "\320\222\321\213\320\271\321\202\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class diameter: public Ui_diameter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAMETER_H
