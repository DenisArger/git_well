/********************************************************************************
** Form generated from reading UI file 'stockwindow_Antony.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKWINDOW_ANTONY_H
#define UI_STOCKWINDOW_ANTONY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_StockWindow_Antony
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
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
    QLabel *label;
    QTextEdit *historyTextEdit;
    QTextEdit *legendTextEdit;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StockWindow_Antony)
    {
        if (StockWindow_Antony->objectName().isEmpty())
            StockWindow_Antony->setObjectName(QStringLiteral("StockWindow_Antony"));
        StockWindow_Antony->setWindowModality(Qt::ApplicationModal);
        StockWindow_Antony->resize(1173, 633);
        centralwidget = new QWidget(StockWindow_Antony);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMaximumSize(QSize(250, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 248, 487));
        QFont font;
        font.setPointSize(11);
        scrollAreaWidgetContents->setFont(font);
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font1;
        font1.setPointSize(9);
        groupBox->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addInstrButton = new QPushButton(groupBox);
        addInstrButton->setObjectName(QStringLiteral("addInstrButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addInstrButton->sizePolicy().hasHeightForWidth());
        addInstrButton->setSizePolicy(sizePolicy);
        addInstrButton->setMinimumSize(QSize(200, 55));
        addInstrButton->setFont(font);

        verticalLayout->addWidget(addInstrButton);

        editNameInstrButton = new QPushButton(groupBox);
        editNameInstrButton->setObjectName(QStringLiteral("editNameInstrButton"));
        sizePolicy.setHeightForWidth(editNameInstrButton->sizePolicy().hasHeightForWidth());
        editNameInstrButton->setSizePolicy(sizePolicy);
        editNameInstrButton->setMinimumSize(QSize(200, 55));
        editNameInstrButton->setFont(font);

        verticalLayout->addWidget(editNameInstrButton);

        editBalanceInstrButton = new QPushButton(groupBox);
        editBalanceInstrButton->setObjectName(QStringLiteral("editBalanceInstrButton"));
        sizePolicy.setHeightForWidth(editBalanceInstrButton->sizePolicy().hasHeightForWidth());
        editBalanceInstrButton->setSizePolicy(sizePolicy);
        editBalanceInstrButton->setMinimumSize(QSize(200, 55));
        editBalanceInstrButton->setFont(font);

        verticalLayout->addWidget(editBalanceInstrButton);

        deleteInstrButton = new QPushButton(groupBox);
        deleteInstrButton->setObjectName(QStringLiteral("deleteInstrButton"));
        sizePolicy.setHeightForWidth(deleteInstrButton->sizePolicy().hasHeightForWidth());
        deleteInstrButton->setSizePolicy(sizePolicy);
        deleteInstrButton->setMinimumSize(QSize(200, 55));
        deleteInstrButton->setFont(font);

        verticalLayout->addWidget(deleteInstrButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addWidget(groupBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_5->addWidget(scrollArea);

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
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);
        tableView->setMinimumSize(QSize(0, 150));
        QFont font2;
        font2.setPointSize(12);
        tableView->setFont(font2);

        verticalLayout_4->addWidget(tableView);

        tabWidget->addTab(tab, QString());

        verticalLayout_2->addWidget(tabWidget);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        historyTextEdit = new QTextEdit(centralwidget);
        historyTextEdit->setObjectName(QStringLiteral("historyTextEdit"));
        sizePolicy1.setHeightForWidth(historyTextEdit->sizePolicy().hasHeightForWidth());
        historyTextEdit->setSizePolicy(sizePolicy1);
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


        horizontalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy2);
        closeButton->setMinimumSize(QSize(140, 60));
        closeButton->setMaximumSize(QSize(140, 60));
        closeButton->setFont(font);

        horizontalLayout_6->addWidget(closeButton);


        verticalLayout_3->addLayout(horizontalLayout_6);

        StockWindow_Antony->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StockWindow_Antony);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1173, 26));
        StockWindow_Antony->setMenuBar(menubar);
        statusbar = new QStatusBar(StockWindow_Antony);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        StockWindow_Antony->setStatusBar(statusbar);

        retranslateUi(StockWindow_Antony);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StockWindow_Antony);
    } // setupUi

    void retranslateUi(QMainWindow *StockWindow_Antony)
    {
        StockWindow_Antony->setWindowTitle(QApplication::translate("StockWindow_Antony", "\320\241\320\272\320\273\320\260\320\264", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("StockWindow_Antony", "\320\236\320\277\320\265\321\200\320\260\321\206\320\270\320\270 \321\201 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\276\320\274", Q_NULLPTR));
        addInstrButton->setText(QApplication::translate("StockWindow_Antony", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \n"
" \320\275\320\276\320\262\321\213\320\271 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273", Q_NULLPTR));
        editNameInstrButton->setText(QApplication::translate("StockWindow_Antony", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \n"
"\320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\260", Q_NULLPTR));
        editBalanceInstrButton->setText(QApplication::translate("StockWindow_Antony", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \n"
"\320\276\321\201\321\202\320\260\321\202\320\276\320\272 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\260", Q_NULLPTR));
        deleteInstrButton->setText(QApplication::translate("StockWindow_Antony", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \n"
"\320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("StockWindow_Antony", "\320\222\321\201\320\265", Q_NULLPTR));
        label->setText(QApplication::translate("StockWindow_Antony", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \321\201\320\272\320\273\320\260\320\264\320\260", Q_NULLPTR));
        closeButton->setText(QApplication::translate("StockWindow_Antony", "\320\222\321\213\320\271\321\202\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StockWindow_Antony: public Ui_StockWindow_Antony {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWINDOW_ANTONY_H
