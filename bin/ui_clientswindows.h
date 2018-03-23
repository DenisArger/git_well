/********************************************************************************
** Form generated from reading UI file 'clientswindows.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTSWINDOWS_H
#define UI_CLIENTSWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientsWindows
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *locationGroupBox;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QLabel *regionLabel_2;
    QComboBox *regionCombo_2;
    QLabel *districtLabel_2;
    QComboBox *districtCombo_2;
    QLabel *localityLabel_2;
    QLineEdit *localityLineEdit_2;
    QLabel *streetLabel_2;
    QLineEdit *streetLineEdit_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *diameterLabel;
    QComboBox *diameterCombo;
    QHBoxLayout *horizontalLayout;
    QCheckBox *pumpCheckBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *serviseCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *clientGroupBox;
    QVBoxLayout *verticalLayout;
    QLabel *surnameLabel;
    QLineEdit *surnameLineEdit;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *patronymicLabel;
    QLineEdit *patronymicLineEdit;
    QLabel *phoneLabel;
    QLineEdit *phoneLineEdit;
    QLabel *otherLabel;
    QLineEdit *otherLineEdit;
    QTableView *tableView;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *filterButton;
    QPushButton *clearFilterButton;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClientsWindows)
    {
        if (ClientsWindows->objectName().isEmpty())
            ClientsWindows->setObjectName(QStringLiteral("ClientsWindows"));
        ClientsWindows->setWindowModality(Qt::ApplicationModal);
        ClientsWindows->resize(991, 937);
        centralwidget = new QWidget(ClientsWindows);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMaximumSize(QSize(340, 16777215));
        scrollArea->setLayoutDirection(Qt::LeftToRight);
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setFrameShadow(QFrame::Raised);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 318, 787));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        locationGroupBox = new QGroupBox(scrollAreaWidgetContents);
        locationGroupBox->setObjectName(QStringLiteral("locationGroupBox"));
        locationGroupBox->setMaximumSize(QSize(400, 16777215));
        QFont font;
        font.setPointSize(8);
        locationGroupBox->setFont(font);
        verticalLayout_7 = new QVBoxLayout(locationGroupBox);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        regionLabel_2 = new QLabel(locationGroupBox);
        regionLabel_2->setObjectName(QStringLiteral("regionLabel_2"));
        QFont font1;
        font1.setPointSize(11);
        regionLabel_2->setFont(font1);

        verticalLayout_2->addWidget(regionLabel_2);

        regionCombo_2 = new QComboBox(locationGroupBox);
        regionCombo_2->setObjectName(QStringLiteral("regionCombo_2"));
        regionCombo_2->setFont(font1);

        verticalLayout_2->addWidget(regionCombo_2);

        districtLabel_2 = new QLabel(locationGroupBox);
        districtLabel_2->setObjectName(QStringLiteral("districtLabel_2"));
        districtLabel_2->setFont(font1);

        verticalLayout_2->addWidget(districtLabel_2);

        districtCombo_2 = new QComboBox(locationGroupBox);
        districtCombo_2->setObjectName(QStringLiteral("districtCombo_2"));
        districtCombo_2->setFont(font1);

        verticalLayout_2->addWidget(districtCombo_2);

        localityLabel_2 = new QLabel(locationGroupBox);
        localityLabel_2->setObjectName(QStringLiteral("localityLabel_2"));
        localityLabel_2->setFont(font1);

        verticalLayout_2->addWidget(localityLabel_2);

        localityLineEdit_2 = new QLineEdit(locationGroupBox);
        localityLineEdit_2->setObjectName(QStringLiteral("localityLineEdit_2"));
        localityLineEdit_2->setFont(font1);

        verticalLayout_2->addWidget(localityLineEdit_2);

        streetLabel_2 = new QLabel(locationGroupBox);
        streetLabel_2->setObjectName(QStringLiteral("streetLabel_2"));
        streetLabel_2->setFont(font1);

        verticalLayout_2->addWidget(streetLabel_2);

        streetLineEdit_3 = new QLineEdit(locationGroupBox);
        streetLineEdit_3->setObjectName(QStringLiteral("streetLineEdit_3"));
        streetLineEdit_3->setFont(font1);

        verticalLayout_2->addWidget(streetLineEdit_3);


        verticalLayout_7->addLayout(verticalLayout_2);


        verticalLayout_4->addWidget(locationGroupBox);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        diameterLabel = new QLabel(groupBox);
        diameterLabel->setObjectName(QStringLiteral("diameterLabel"));
        diameterLabel->setMaximumSize(QSize(80, 25));
        diameterLabel->setFont(font1);

        verticalLayout_3->addWidget(diameterLabel);

        diameterCombo = new QComboBox(groupBox);
        diameterCombo->setObjectName(QStringLiteral("diameterCombo"));
        diameterCombo->setFont(font1);

        verticalLayout_3->addWidget(diameterCombo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pumpCheckBox = new QCheckBox(groupBox);
        pumpCheckBox->setObjectName(QStringLiteral("pumpCheckBox"));
        pumpCheckBox->setFont(font1);
        pumpCheckBox->setLayoutDirection(Qt::RightToLeft);
        pumpCheckBox->setCheckable(true);
        pumpCheckBox->setTristate(false);

        horizontalLayout->addWidget(pumpCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        serviseCheckBox = new QCheckBox(groupBox);
        serviseCheckBox->setObjectName(QStringLiteral("serviseCheckBox"));
        serviseCheckBox->setFont(font1);
        serviseCheckBox->setLayoutDirection(Qt::RightToLeft);
        serviseCheckBox->setAutoFillBackground(false);
        serviseCheckBox->setIconSize(QSize(20, 20));
        serviseCheckBox->setCheckable(true);
        serviseCheckBox->setChecked(false);
        serviseCheckBox->setAutoRepeat(false);
        serviseCheckBox->setTristate(false);

        horizontalLayout_2->addWidget(serviseCheckBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addWidget(groupBox);

        clientGroupBox = new QGroupBox(scrollAreaWidgetContents);
        clientGroupBox->setObjectName(QStringLiteral("clientGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(clientGroupBox->sizePolicy().hasHeightForWidth());
        clientGroupBox->setSizePolicy(sizePolicy);
        clientGroupBox->setMaximumSize(QSize(400, 16777215));
        clientGroupBox->setFont(font);
        verticalLayout = new QVBoxLayout(clientGroupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        surnameLabel = new QLabel(clientGroupBox);
        surnameLabel->setObjectName(QStringLiteral("surnameLabel"));
        surnameLabel->setFont(font1);

        verticalLayout->addWidget(surnameLabel);

        surnameLineEdit = new QLineEdit(clientGroupBox);
        surnameLineEdit->setObjectName(QStringLiteral("surnameLineEdit"));
        surnameLineEdit->setFont(font1);

        verticalLayout->addWidget(surnameLineEdit);

        nameLabel = new QLabel(clientGroupBox);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setFont(font1);

        verticalLayout->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(clientGroupBox);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setFont(font1);

        verticalLayout->addWidget(nameLineEdit);

        patronymicLabel = new QLabel(clientGroupBox);
        patronymicLabel->setObjectName(QStringLiteral("patronymicLabel"));
        patronymicLabel->setFont(font1);

        verticalLayout->addWidget(patronymicLabel);

        patronymicLineEdit = new QLineEdit(clientGroupBox);
        patronymicLineEdit->setObjectName(QStringLiteral("patronymicLineEdit"));
        patronymicLineEdit->setFont(font1);

        verticalLayout->addWidget(patronymicLineEdit);

        phoneLabel = new QLabel(clientGroupBox);
        phoneLabel->setObjectName(QStringLiteral("phoneLabel"));
        phoneLabel->setFont(font1);

        verticalLayout->addWidget(phoneLabel);

        phoneLineEdit = new QLineEdit(clientGroupBox);
        phoneLineEdit->setObjectName(QStringLiteral("phoneLineEdit"));
        phoneLineEdit->setFont(font1);

        verticalLayout->addWidget(phoneLineEdit);

        otherLabel = new QLabel(clientGroupBox);
        otherLabel->setObjectName(QStringLiteral("otherLabel"));
        otherLabel->setFont(font1);

        verticalLayout->addWidget(otherLabel);

        otherLineEdit = new QLineEdit(clientGroupBox);
        otherLineEdit->setObjectName(QStringLiteral("otherLineEdit"));
        otherLineEdit->setFont(font1);

        verticalLayout->addWidget(otherLineEdit);


        verticalLayout_4->addWidget(clientGroupBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_4->addWidget(scrollArea);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setFont(font1);
        tableView->verticalHeader()->setHighlightSections(true);

        horizontalLayout_4->addWidget(tableView);


        verticalLayout_5->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        filterButton = new QPushButton(centralwidget);
        filterButton->setObjectName(QStringLiteral("filterButton"));
        filterButton->setMinimumSize(QSize(100, 40));
        filterButton->setFont(font1);

        horizontalLayout_3->addWidget(filterButton);

        clearFilterButton = new QPushButton(centralwidget);
        clearFilterButton->setObjectName(QStringLiteral("clearFilterButton"));
        clearFilterButton->setMinimumSize(QSize(100, 40));
        clearFilterButton->setFont(font1);

        horizontalLayout_3->addWidget(clearFilterButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy1);
        closeButton->setMinimumSize(QSize(100, 40));
        closeButton->setMaximumSize(QSize(100, 40));
        closeButton->setFont(font1);

        horizontalLayout_5->addWidget(closeButton);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(horizontalLayout_6);

        ClientsWindows->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClientsWindows);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 991, 26));
        ClientsWindows->setMenuBar(menubar);
        statusbar = new QStatusBar(ClientsWindows);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ClientsWindows->setStatusBar(statusbar);

        retranslateUi(ClientsWindows);

        QMetaObject::connectSlotsByName(ClientsWindows);
    } // setupUi

    void retranslateUi(QMainWindow *ClientsWindows)
    {
        ClientsWindows->setWindowTitle(QApplication::translate("ClientsWindows", "\320\232\320\273\320\270\320\265\320\275\321\202\321\201\320\272\320\260\321\217 \320\261\320\260\320\267\320\260", Q_NULLPTR));
        locationGroupBox->setTitle(QApplication::translate("ClientsWindows", "\320\234\320\265\321\201\321\202\320\276\320\275\320\260\321\205\320\276\320\266\320\264\320\265\320\275\320\270\320\265", Q_NULLPTR));
        regionLabel_2->setText(QApplication::translate("ClientsWindows", "\320\236\320\261\320\273\320\260\321\201\321\202\321\214", Q_NULLPTR));
        districtLabel_2->setText(QApplication::translate("ClientsWindows", "\320\240\320\260\320\271\320\276\320\275", Q_NULLPTR));
        localityLabel_2->setText(QApplication::translate("ClientsWindows", "\320\235\320\260\321\201\320\265\320\273\320\265\320\275\320\275\321\213\320\271 \320\277\321\203\320\275\320\272\321\202", Q_NULLPTR));
        streetLabel_2->setText(QApplication::translate("ClientsWindows", "\320\243\320\273\320\270\321\206\320\260,\320\264\320\276\320\274", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ClientsWindows", "\320\227\320\260\320\272\320\260\320\267", Q_NULLPTR));
        diameterLabel->setText(QApplication::translate("ClientsWindows", "\320\224\320\270\320\260\320\274\320\265\321\202\321\200", Q_NULLPTR));
        pumpCheckBox->setText(QApplication::translate("ClientsWindows", "\320\235\320\260\321\201\320\276\321\201", Q_NULLPTR));
        serviseCheckBox->setText(QApplication::translate("ClientsWindows", "\320\237\321\200\320\265\320\264\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\276\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\321\217", Q_NULLPTR));
        clientGroupBox->setTitle(QApplication::translate("ClientsWindows", "\320\232\320\273\320\270\320\265\320\275\321\202", Q_NULLPTR));
        surnameLabel->setText(QApplication::translate("ClientsWindows", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("ClientsWindows", "\320\230\320\274\321\217", Q_NULLPTR));
        patronymicLabel->setText(QApplication::translate("ClientsWindows", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        phoneLabel->setText(QApplication::translate("ClientsWindows", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", Q_NULLPTR));
        otherLabel->setText(QApplication::translate("ClientsWindows", "\320\224\320\276\320\277.\321\202\320\265\320\273\320\265\321\204\320\276\320\275\321\213", Q_NULLPTR));
        otherLineEdit->setText(QString());
        filterButton->setText(QApplication::translate("ClientsWindows", "\320\237\320\276\320\270\321\201\320\272", Q_NULLPTR));
        clearFilterButton->setText(QApplication::translate("ClientsWindows", "\320\241\320\261\321\200\320\276\321\201", Q_NULLPTR));
        closeButton->setText(QApplication::translate("ClientsWindows", "\320\222\321\213\320\271\321\202\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientsWindows: public Ui_ClientsWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTSWINDOWS_H
