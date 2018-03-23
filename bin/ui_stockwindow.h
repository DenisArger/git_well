/********************************************************************************
** Form generated from reading UI file 'stockwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKWINDOW_H
#define UI_STOCKWINDOW_H

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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StockWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QDateEdit *dataEnddateEdit;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QDateEdit *dataBegindateEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *sumButton;
    QPushButton *clearButtton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addInstrButton;
    QPushButton *editNameInstrButton;
    QPushButton *editBalanceInstrButton;
    QPushButton *deleteInstrButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QTableView *tableView;
    QTextEdit *historyTextEdit;
    QTextEdit *legendTextEdit;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StockWindow)
    {
        if (StockWindow->objectName().isEmpty())
            StockWindow->setObjectName(QStringLiteral("StockWindow"));
        StockWindow->setWindowModality(Qt::ApplicationModal);
        StockWindow->resize(1173, 633);
        centralwidget = new QWidget(StockWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMaximumSize(QSize(339, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 337, 490));
        QFont font;
        font.setPointSize(11);
        scrollAreaWidgetContents->setFont(font);
        verticalLayout_6 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(70, 0));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        dataEnddateEdit = new QDateEdit(groupBox_3);
        dataEnddateEdit->setObjectName(QStringLiteral("dataEnddateEdit"));
        dataEnddateEdit->setFont(font);
        dataEnddateEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dataEnddateEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(70, 0));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        dataBegindateEdit = new QDateEdit(groupBox_3);
        dataBegindateEdit->setObjectName(QStringLiteral("dataBegindateEdit"));
        dataBegindateEdit->setFont(font);
        dataBegindateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dataBegindateEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        sumButton = new QPushButton(groupBox_3);
        sumButton->setObjectName(QStringLiteral("sumButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sumButton->sizePolicy().hasHeightForWidth());
        sumButton->setSizePolicy(sizePolicy);
        sumButton->setMinimumSize(QSize(120, 55));
        sumButton->setFont(font);

        horizontalLayout_7->addWidget(sumButton);

        clearButtton = new QPushButton(groupBox_3);
        clearButtton->setObjectName(QStringLiteral("clearButtton"));
        sizePolicy.setHeightForWidth(clearButtton->sizePolicy().hasHeightForWidth());
        clearButtton->setSizePolicy(sizePolicy);
        clearButtton->setMinimumSize(QSize(120, 55));
        clearButtton->setFont(font);

        horizontalLayout_7->addWidget(clearButtton);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_6->addWidget(groupBox_3);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font1;
        font1.setPointSize(9);
        groupBox->setFont(font1);
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        addInstrButton = new QPushButton(groupBox);
        addInstrButton->setObjectName(QStringLiteral("addInstrButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addInstrButton->sizePolicy().hasHeightForWidth());
        addInstrButton->setSizePolicy(sizePolicy1);
        addInstrButton->setFont(font);

        verticalLayout_3->addWidget(addInstrButton);

        editNameInstrButton = new QPushButton(groupBox);
        editNameInstrButton->setObjectName(QStringLiteral("editNameInstrButton"));
        sizePolicy1.setHeightForWidth(editNameInstrButton->sizePolicy().hasHeightForWidth());
        editNameInstrButton->setSizePolicy(sizePolicy1);
        editNameInstrButton->setFont(font);

        verticalLayout_3->addWidget(editNameInstrButton);

        editBalanceInstrButton = new QPushButton(groupBox);
        editBalanceInstrButton->setObjectName(QStringLiteral("editBalanceInstrButton"));
        sizePolicy1.setHeightForWidth(editBalanceInstrButton->sizePolicy().hasHeightForWidth());
        editBalanceInstrButton->setSizePolicy(sizePolicy1);
        editBalanceInstrButton->setFont(font);

        verticalLayout_3->addWidget(editBalanceInstrButton);

        deleteInstrButton = new QPushButton(groupBox);
        deleteInstrButton->setObjectName(QStringLiteral("deleteInstrButton"));
        sizePolicy1.setHeightForWidth(deleteInstrButton->sizePolicy().hasHeightForWidth());
        deleteInstrButton->setSizePolicy(sizePolicy1);
        deleteInstrButton->setFont(font);

        verticalLayout_3->addWidget(deleteInstrButton);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalSpacer = new QSpacerItem(288, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        verticalLayout_6->addWidget(groupBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font);
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy2);
        tableView->setMinimumSize(QSize(0, 150));
        QFont font2;
        font2.setPointSize(12);
        tableView->setFont(font2);

        verticalLayout_4->addWidget(tableView);

        tabWidget->addTab(tab, QString());

        verticalLayout_2->addWidget(tabWidget);

        historyTextEdit = new QTextEdit(centralwidget);
        historyTextEdit->setObjectName(QStringLiteral("historyTextEdit"));
        sizePolicy2.setHeightForWidth(historyTextEdit->sizePolicy().hasHeightForWidth());
        historyTextEdit->setSizePolicy(sizePolicy2);
        historyTextEdit->setMinimumSize(QSize(0, 150));
        historyTextEdit->setMaximumSize(QSize(16777215, 298));
        historyTextEdit->setFrameShape(QFrame::Box);

        verticalLayout_2->addWidget(historyTextEdit);

        legendTextEdit = new QTextEdit(centralwidget);
        legendTextEdit->setObjectName(QStringLiteral("legendTextEdit"));
        legendTextEdit->setMinimumSize(QSize(0, 40));
        legendTextEdit->setMaximumSize(QSize(16777215, 40));
        legendTextEdit->setFrameShape(QFrame::Box);

        verticalLayout_2->addWidget(legendTextEdit);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy3);
        closeButton->setMinimumSize(QSize(140, 60));
        closeButton->setMaximumSize(QSize(140, 60));
        closeButton->setFont(font);

        horizontalLayout_6->addWidget(closeButton);


        verticalLayout_7->addLayout(horizontalLayout_6);

        StockWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StockWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1173, 26));
        StockWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StockWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        StockWindow->setStatusBar(statusbar);

        retranslateUi(StockWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StockWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StockWindow)
    {
        StockWindow->setWindowTitle(QApplication::translate("StockWindow", "\320\241\320\272\320\273\320\260\320\264", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("StockWindow", "\320\237\320\276\320\264\321\201\321\207\320\265\321\202 \321\200\320\260\321\201\321\205\320\276\320\264\320\260 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("StockWindow", "\320\237\320\276", Q_NULLPTR));
        label->setText(QApplication::translate("StockWindow", "\320\241", Q_NULLPTR));
        sumButton->setText(QApplication::translate("StockWindow", "\320\237\320\276\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \n"
"\320\276\321\201\321\202\320\260\321\202\320\276\320\272", Q_NULLPTR));
        clearButtton->setText(QApplication::translate("StockWindow", "\320\241\320\261\321\200\320\276\321\201 ", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("StockWindow", "\320\236\320\277\320\265\321\200\320\260\321\206\320\270\320\270 \321\201 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\276\320\274", Q_NULLPTR));
        addInstrButton->setText(QApplication::translate("StockWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \n"
" \320\275\320\276\320\262\321\213\320\271 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273", Q_NULLPTR));
        editNameInstrButton->setText(QApplication::translate("StockWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \n"
"\320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\260", Q_NULLPTR));
        editBalanceInstrButton->setText(QApplication::translate("StockWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \n"
"\320\276\321\201\321\202\320\260\321\202\320\276\320\272 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\260", Q_NULLPTR));
        deleteInstrButton->setText(QApplication::translate("StockWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \n"
"\320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("StockWindow", "\320\222\321\201\320\265", Q_NULLPTR));
        closeButton->setText(QApplication::translate("StockWindow", "\320\222\321\213\320\271\321\202\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StockWindow: public Ui_StockWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWINDOW_H
