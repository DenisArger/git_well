/********************************************************************************
** Form generated from reading UI file 'cardservicewindows.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDSERVICEWINDOWS_H
#define UI_CARDSERVICEWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardServiceWindows
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *clientGroupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_15;
    QLabel *surnameLabel_2;
    QLineEdit *surnameLineEdit_2;
    QHBoxLayout *horizontalLayout_16;
    QLabel *nameLabel_2;
    QLineEdit *nameLineEdit_2;
    QHBoxLayout *horizontalLayout_17;
    QLabel *patronymicLabel_2;
    QLineEdit *patronymicLineEdit_2;
    QHBoxLayout *horizontalLayout_18;
    QLabel *mobPhoneLabel_2;
    QLineEdit *mobilPhoneLineEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *otherPhoneLabel;
    QLineEdit *otherPhoneLineEdit;
    QGroupBox *locationGroupBox_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_19;
    QLabel *regionLabel_2;
    QComboBox *regionCombo_2;
    QHBoxLayout *horizontalLayout_20;
    QLabel *districtLabel_2;
    QComboBox *districtCombo_2;
    QHBoxLayout *horizontalLayout_21;
    QLabel *localityLabel_2;
    QLineEdit *localityLineEdit_2;
    QHBoxLayout *horizontalLayout_22;
    QLabel *streetLabel_2;
    QLineEdit *streetLineEdit_2;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_23;
    QHBoxLayout *horizontalLayout_24;
    QLabel *stateServiceLabel_2;
    QComboBox *stateServiceCombo_2;
    QHBoxLayout *horizontalLayout_25;
    QCheckBox *dataBeginServiceBox_2;
    QDateEdit *dataBeginServiceEdit_2;
    QHBoxLayout *horizontalLayout_26;
    QHBoxLayout *horizontalLayout_27;
    QLabel *statePaymentLabel_2;
    QComboBox *statePaymentCombo_2;
    QHBoxLayout *horizontalLayout_28;
    QLabel *typePumpLabel_2;
    QComboBox *typePumpCombo_2;
    QHBoxLayout *horizontalLayout_29;
    QHBoxLayout *horizontalLayout_30;
    QLabel *statePumpLabel_2;
    QComboBox *statePumpCombo_2;
    QHBoxLayout *horizontalLayout_31;
    QLabel *locationePumpLabel_2;
    QComboBox *locationePumpCombo_2;
    QHBoxLayout *horizontalLayout_32;
    QHBoxLayout *horizontalLayout_33;
    QLabel *seasoneLabel_2;
    QComboBox *seasonaCombo_2;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *nextServiceGroupBox_4;
    QGridLayout *gridLayout_4;
    QTableView *tableView_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QTextEdit *noteEdit_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *saveButton;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CardServiceWindows)
    {
        if (CardServiceWindows->objectName().isEmpty())
            CardServiceWindows->setObjectName(QStringLiteral("CardServiceWindows"));
        CardServiceWindows->setWindowModality(Qt::ApplicationModal);
        CardServiceWindows->resize(800, 1230);
        centralwidget = new QWidget(CardServiceWindows);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 776, 1096));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        clientGroupBox_2 = new QGroupBox(scrollAreaWidgetContents_2);
        clientGroupBox_2->setObjectName(QStringLiteral("clientGroupBox_2"));
        QFont font;
        font.setPointSize(8);
        clientGroupBox_2->setFont(font);
        clientGroupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout = new QVBoxLayout(clientGroupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        surnameLabel_2 = new QLabel(clientGroupBox_2);
        surnameLabel_2->setObjectName(QStringLiteral("surnameLabel_2"));
        surnameLabel_2->setMinimumSize(QSize(125, 0));
        QFont font1;
        font1.setPointSize(11);
        surnameLabel_2->setFont(font1);

        horizontalLayout_15->addWidget(surnameLabel_2);

        surnameLineEdit_2 = new QLineEdit(clientGroupBox_2);
        surnameLineEdit_2->setObjectName(QStringLiteral("surnameLineEdit_2"));
        surnameLineEdit_2->setEnabled(true);
        QFont font2;
        font2.setPointSize(10);
        surnameLineEdit_2->setFont(font2);
        surnameLineEdit_2->setReadOnly(true);

        horizontalLayout_15->addWidget(surnameLineEdit_2);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        nameLabel_2 = new QLabel(clientGroupBox_2);
        nameLabel_2->setObjectName(QStringLiteral("nameLabel_2"));
        nameLabel_2->setMinimumSize(QSize(125, 0));
        nameLabel_2->setFont(font1);

        horizontalLayout_16->addWidget(nameLabel_2);

        nameLineEdit_2 = new QLineEdit(clientGroupBox_2);
        nameLineEdit_2->setObjectName(QStringLiteral("nameLineEdit_2"));
        nameLineEdit_2->setEnabled(true);
        nameLineEdit_2->setFont(font2);
        nameLineEdit_2->setReadOnly(true);

        horizontalLayout_16->addWidget(nameLineEdit_2);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        patronymicLabel_2 = new QLabel(clientGroupBox_2);
        patronymicLabel_2->setObjectName(QStringLiteral("patronymicLabel_2"));
        patronymicLabel_2->setMinimumSize(QSize(125, 0));
        patronymicLabel_2->setFont(font1);

        horizontalLayout_17->addWidget(patronymicLabel_2);

        patronymicLineEdit_2 = new QLineEdit(clientGroupBox_2);
        patronymicLineEdit_2->setObjectName(QStringLiteral("patronymicLineEdit_2"));
        patronymicLineEdit_2->setEnabled(true);
        patronymicLineEdit_2->setFont(font2);
        patronymicLineEdit_2->setReadOnly(true);

        horizontalLayout_17->addWidget(patronymicLineEdit_2);


        verticalLayout->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        mobPhoneLabel_2 = new QLabel(clientGroupBox_2);
        mobPhoneLabel_2->setObjectName(QStringLiteral("mobPhoneLabel_2"));
        mobPhoneLabel_2->setMinimumSize(QSize(125, 0));
        mobPhoneLabel_2->setFont(font1);

        horizontalLayout_18->addWidget(mobPhoneLabel_2);

        mobilPhoneLineEdit_2 = new QLineEdit(clientGroupBox_2);
        mobilPhoneLineEdit_2->setObjectName(QStringLiteral("mobilPhoneLineEdit_2"));
        mobilPhoneLineEdit_2->setEnabled(true);
        mobilPhoneLineEdit_2->setFont(font2);
        mobilPhoneLineEdit_2->setReadOnly(true);

        horizontalLayout_18->addWidget(mobilPhoneLineEdit_2);


        verticalLayout->addLayout(horizontalLayout_18);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        otherPhoneLabel = new QLabel(clientGroupBox_2);
        otherPhoneLabel->setObjectName(QStringLiteral("otherPhoneLabel"));
        otherPhoneLabel->setMinimumSize(QSize(125, 0));
        otherPhoneLabel->setFont(font1);

        horizontalLayout_2->addWidget(otherPhoneLabel);

        otherPhoneLineEdit = new QLineEdit(clientGroupBox_2);
        otherPhoneLineEdit->setObjectName(QStringLiteral("otherPhoneLineEdit"));
        otherPhoneLineEdit->setEnabled(true);
        otherPhoneLineEdit->setFont(font2);
        otherPhoneLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(otherPhoneLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(clientGroupBox_2);

        locationGroupBox_2 = new QGroupBox(scrollAreaWidgetContents_2);
        locationGroupBox_2->setObjectName(QStringLiteral("locationGroupBox_2"));
        locationGroupBox_2->setFont(font);
        verticalLayout_6 = new QVBoxLayout(locationGroupBox_2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        regionLabel_2 = new QLabel(locationGroupBox_2);
        regionLabel_2->setObjectName(QStringLiteral("regionLabel_2"));
        regionLabel_2->setMinimumSize(QSize(155, 0));
        regionLabel_2->setFont(font1);

        horizontalLayout_19->addWidget(regionLabel_2);

        regionCombo_2 = new QComboBox(locationGroupBox_2);
        regionCombo_2->setObjectName(QStringLiteral("regionCombo_2"));
        regionCombo_2->setEnabled(true);
        regionCombo_2->setFont(font1);

        horizontalLayout_19->addWidget(regionCombo_2);


        verticalLayout_6->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        districtLabel_2 = new QLabel(locationGroupBox_2);
        districtLabel_2->setObjectName(QStringLiteral("districtLabel_2"));
        districtLabel_2->setMinimumSize(QSize(155, 0));
        districtLabel_2->setFont(font1);

        horizontalLayout_20->addWidget(districtLabel_2);

        districtCombo_2 = new QComboBox(locationGroupBox_2);
        districtCombo_2->setObjectName(QStringLiteral("districtCombo_2"));
        districtCombo_2->setEnabled(true);
        districtCombo_2->setFont(font1);

        horizontalLayout_20->addWidget(districtCombo_2);


        verticalLayout_6->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        localityLabel_2 = new QLabel(locationGroupBox_2);
        localityLabel_2->setObjectName(QStringLiteral("localityLabel_2"));
        localityLabel_2->setMinimumSize(QSize(155, 0));
        localityLabel_2->setFont(font1);

        horizontalLayout_21->addWidget(localityLabel_2);

        localityLineEdit_2 = new QLineEdit(locationGroupBox_2);
        localityLineEdit_2->setObjectName(QStringLiteral("localityLineEdit_2"));
        localityLineEdit_2->setEnabled(true);
        localityLineEdit_2->setFont(font1);
        localityLineEdit_2->setReadOnly(true);

        horizontalLayout_21->addWidget(localityLineEdit_2);


        verticalLayout_6->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        streetLabel_2 = new QLabel(locationGroupBox_2);
        streetLabel_2->setObjectName(QStringLiteral("streetLabel_2"));
        streetLabel_2->setMinimumSize(QSize(155, 0));
        streetLabel_2->setFont(font1);

        horizontalLayout_22->addWidget(streetLabel_2);

        streetLineEdit_2 = new QLineEdit(locationGroupBox_2);
        streetLineEdit_2->setObjectName(QStringLiteral("streetLineEdit_2"));
        streetLineEdit_2->setEnabled(true);
        streetLineEdit_2->setFont(font1);
        streetLineEdit_2->setReadOnly(true);

        horizontalLayout_22->addWidget(streetLineEdit_2);


        verticalLayout_6->addLayout(horizontalLayout_22);


        verticalLayout_2->addWidget(locationGroupBox_2);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setEnabled(true);
        groupBox_4->setFont(font);
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        stateServiceLabel_2 = new QLabel(groupBox_4);
        stateServiceLabel_2->setObjectName(QStringLiteral("stateServiceLabel_2"));
        stateServiceLabel_2->setFont(font1);

        horizontalLayout_24->addWidget(stateServiceLabel_2);

        stateServiceCombo_2 = new QComboBox(groupBox_4);
        stateServiceCombo_2->setObjectName(QStringLiteral("stateServiceCombo_2"));
        QFont font3;
        font3.setPointSize(12);
        stateServiceCombo_2->setFont(font3);

        horizontalLayout_24->addWidget(stateServiceCombo_2);


        horizontalLayout_23->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        dataBeginServiceBox_2 = new QCheckBox(groupBox_4);
        dataBeginServiceBox_2->setObjectName(QStringLiteral("dataBeginServiceBox_2"));
        dataBeginServiceBox_2->setFont(font3);

        horizontalLayout_25->addWidget(dataBeginServiceBox_2);

        dataBeginServiceEdit_2 = new QDateEdit(groupBox_4);
        dataBeginServiceEdit_2->setObjectName(QStringLiteral("dataBeginServiceEdit_2"));
        dataBeginServiceEdit_2->setFont(font1);

        horizontalLayout_25->addWidget(dataBeginServiceEdit_2);


        horizontalLayout_23->addLayout(horizontalLayout_25);


        gridLayout_5->addLayout(horizontalLayout_23, 0, 0, 1, 1);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        statePaymentLabel_2 = new QLabel(groupBox_4);
        statePaymentLabel_2->setObjectName(QStringLiteral("statePaymentLabel_2"));
        statePaymentLabel_2->setFont(font1);

        horizontalLayout_27->addWidget(statePaymentLabel_2);

        statePaymentCombo_2 = new QComboBox(groupBox_4);
        statePaymentCombo_2->setObjectName(QStringLiteral("statePaymentCombo_2"));
        statePaymentCombo_2->setFont(font3);

        horizontalLayout_27->addWidget(statePaymentCombo_2);


        horizontalLayout_26->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        typePumpLabel_2 = new QLabel(groupBox_4);
        typePumpLabel_2->setObjectName(QStringLiteral("typePumpLabel_2"));
        typePumpLabel_2->setFont(font1);

        horizontalLayout_28->addWidget(typePumpLabel_2);

        typePumpCombo_2 = new QComboBox(groupBox_4);
        typePumpCombo_2->setObjectName(QStringLiteral("typePumpCombo_2"));
        typePumpCombo_2->setFont(font3);

        horizontalLayout_28->addWidget(typePumpCombo_2);


        horizontalLayout_26->addLayout(horizontalLayout_28);


        gridLayout_5->addLayout(horizontalLayout_26, 1, 0, 1, 1);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        statePumpLabel_2 = new QLabel(groupBox_4);
        statePumpLabel_2->setObjectName(QStringLiteral("statePumpLabel_2"));
        statePumpLabel_2->setFont(font1);

        horizontalLayout_30->addWidget(statePumpLabel_2);

        statePumpCombo_2 = new QComboBox(groupBox_4);
        statePumpCombo_2->setObjectName(QStringLiteral("statePumpCombo_2"));
        statePumpCombo_2->setFont(font3);

        horizontalLayout_30->addWidget(statePumpCombo_2);


        horizontalLayout_29->addLayout(horizontalLayout_30);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        locationePumpLabel_2 = new QLabel(groupBox_4);
        locationePumpLabel_2->setObjectName(QStringLiteral("locationePumpLabel_2"));
        locationePumpLabel_2->setFont(font1);

        horizontalLayout_31->addWidget(locationePumpLabel_2);

        locationePumpCombo_2 = new QComboBox(groupBox_4);
        locationePumpCombo_2->setObjectName(QStringLiteral("locationePumpCombo_2"));
        locationePumpCombo_2->setFont(font3);

        horizontalLayout_31->addWidget(locationePumpCombo_2);


        horizontalLayout_29->addLayout(horizontalLayout_31);


        gridLayout_5->addLayout(horizontalLayout_29, 2, 0, 1, 1);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        seasoneLabel_2 = new QLabel(groupBox_4);
        seasoneLabel_2->setObjectName(QStringLiteral("seasoneLabel_2"));
        seasoneLabel_2->setFont(font1);

        horizontalLayout_33->addWidget(seasoneLabel_2);

        seasonaCombo_2 = new QComboBox(groupBox_4);
        seasonaCombo_2->setObjectName(QStringLiteral("seasonaCombo_2"));
        seasonaCombo_2->setFont(font3);

        horizontalLayout_33->addWidget(seasonaCombo_2);


        horizontalLayout_32->addLayout(horizontalLayout_33);

        horizontalSpacer_3 = new QSpacerItem(350, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_3);


        gridLayout_5->addLayout(horizontalLayout_32, 3, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_4);

        nextServiceGroupBox_4 = new QGroupBox(scrollAreaWidgetContents_2);
        nextServiceGroupBox_4->setObjectName(QStringLiteral("nextServiceGroupBox_4"));
        gridLayout_4 = new QGridLayout(nextServiceGroupBox_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        tableView_2 = new QTableView(nextServiceGroupBox_4);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView_2->sizePolicy().hasHeightForWidth());
        tableView_2->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        tableView_2->setFont(font4);
        tableView_2->setFrameShape(QFrame::Panel);

        gridLayout_4->addWidget(tableView_2, 0, 0, 1, 1);


        verticalLayout_2->addWidget(nextServiceGroupBox_4);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_7 = new QVBoxLayout(groupBox_3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        noteEdit_2 = new QTextEdit(groupBox_3);
        noteEdit_2->setObjectName(QStringLiteral("noteEdit_2"));
        sizePolicy.setHeightForWidth(noteEdit_2->sizePolicy().hasHeightForWidth());
        noteEdit_2->setSizePolicy(sizePolicy);
        noteEdit_2->setFont(font2);

        verticalLayout_7->addWidget(noteEdit_2);


        verticalLayout_2->addWidget(groupBox_3);

        scrollArea->setWidget(scrollAreaWidgetContents_2);
        clientGroupBox_2->raise();
        locationGroupBox_2->raise();
        nextServiceGroupBox_4->raise();
        groupBox_3->raise();
        groupBox_4->raise();

        verticalLayout_3->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy1);
        saveButton->setMinimumSize(QSize(120, 50));
        saveButton->setFont(font1);

        horizontalLayout->addWidget(saveButton);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy2);
        closeButton->setMinimumSize(QSize(120, 50));
        closeButton->setFont(font1);

        horizontalLayout->addWidget(closeButton);


        verticalLayout_3->addLayout(horizontalLayout);

        CardServiceWindows->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CardServiceWindows);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        CardServiceWindows->setMenuBar(menubar);
        statusbar = new QStatusBar(CardServiceWindows);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CardServiceWindows->setStatusBar(statusbar);

        retranslateUi(CardServiceWindows);

        QMetaObject::connectSlotsByName(CardServiceWindows);
    } // setupUi

    void retranslateUi(QMainWindow *CardServiceWindows)
    {
        CardServiceWindows->setWindowTitle(QApplication::translate("CardServiceWindows", "MainWindow", Q_NULLPTR));
        clientGroupBox_2->setTitle(QApplication::translate("CardServiceWindows", "\320\233\320\270\321\207\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", Q_NULLPTR));
        surnameLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        nameLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\230\320\274\321\217", Q_NULLPTR));
        patronymicLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        mobPhoneLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", Q_NULLPTR));
        otherPhoneLabel->setText(QApplication::translate("CardServiceWindows", "\320\224\320\276\320\277.\321\202\320\265\320\273\320\265\321\204\320\276\320\275\321\213", Q_NULLPTR));
        otherPhoneLineEdit->setText(QString());
        locationGroupBox_2->setTitle(QApplication::translate("CardServiceWindows", "\320\234\320\265\321\201\321\202\320\276\320\275\320\260\321\205\320\276\320\266\320\264\320\265\320\275\320\270\320\265", Q_NULLPTR));
        regionLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\236\320\261\320\273\320\260\321\201\321\202\321\214", Q_NULLPTR));
        districtLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\240\320\260\320\271\320\276\320\275", Q_NULLPTR));
        localityLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\235\320\260\321\201\320\265\320\273\320\265\320\275\320\275\321\213\320\271 \320\277\321\203\320\275\320\272\321\202", Q_NULLPTR));
        streetLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\243\320\273\320\270\321\206\320\260, \320\264\320\276\320\274", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("CardServiceWindows", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\276\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\321\217", Q_NULLPTR));
        stateServiceLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\241\321\202\320\260\321\202\321\203\321\201 \n"
"\320\276\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\321\217", Q_NULLPTR));
        dataBeginServiceBox_2->setText(QApplication::translate("CardServiceWindows", "\320\224\320\260\321\202\320\260  \n"
"\320\276\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\321\217", Q_NULLPTR));
        statePaymentLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\241\321\202\320\260\321\202\321\203\321\201 \320\276\320\277\320\273\320\260\321\202\321\213", Q_NULLPTR));
        typePumpLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\242\320\270\320\277 \n"
"\320\276\320\261\320\276\321\200\321\203\320\264\320\276\320\262\320\260\320\275\320\270\321\217", Q_NULLPTR));
        statePumpLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\235\320\260\321\201\320\276\321\201", Q_NULLPTR));
        locationePumpLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \n"
"\320\275\320\260\321\201\320\276\321\201\320\260", Q_NULLPTR));
        seasoneLabel_2->setText(QApplication::translate("CardServiceWindows", "\320\241\320\265\320\267\320\276\320\275\320\275\320\276\321\201\321\202\321\214", Q_NULLPTR));
        nextServiceGroupBox_4->setTitle(QApplication::translate("CardServiceWindows", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\265 \320\276\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("CardServiceWindows", "\320\237\321\200\320\270\320\274\320\265\321\207\320\260\320\275\320\270\321\217", Q_NULLPTR));
        saveButton->setText(QApplication::translate("CardServiceWindows", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        closeButton->setText(QApplication::translate("CardServiceWindows", "\320\222\321\213\320\271\321\202\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CardServiceWindows: public Ui_CardServiceWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDSERVICEWINDOWS_H
