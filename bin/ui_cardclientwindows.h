/********************************************************************************
** Form generated from reading UI file 'cardclientwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDCLIENTWINDOWS_H
#define UI_CARDCLIENTWINDOWS_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardClientWindows
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *clientGroupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *surnameLabel;
    QLineEdit *surnameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *patronymicLabel;
    QLineEdit *patronymicLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *mobPhoneLabel;
    QLineEdit *mobilPhoneLineEdit;
    QHBoxLayout *horizontalLayout_13;
    QLabel *otherPhoneLabel;
    QLineEdit *otherPhoneLineEdit;
    QGroupBox *locationGroupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *regionLabel;
    QComboBox *regionCombo;
    QHBoxLayout *horizontalLayout_6;
    QLabel *districtLabel;
    QComboBox *districtCombo;
    QHBoxLayout *horizontalLayout_7;
    QLabel *localityLabel;
    QLineEdit *localityLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *streetLabel;
    QLineEdit *streetLineEdit;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *dataBeginCheckBox;
    QDateEdit *dataBegindateEdit;
    QCheckBox *dataEndCheckBox;
    QDateEdit *dataEndDateEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *deptLabel;
    QLineEdit *depthLineEdit;
    QLabel *diameterLabel;
    QComboBox *diameterCombo;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *pumpCheckBox;
    QCheckBox *serviseCheckBox;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QTextEdit *noteEdit;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *saveButton;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CardClientWindows)
    {
        if (CardClientWindows->objectName().isEmpty())
            CardClientWindows->setObjectName(QStringLiteral("CardClientWindows"));
        CardClientWindows->setWindowModality(Qt::ApplicationModal);
        CardClientWindows->resize(645, 865);
        centralwidget = new QWidget(CardClientWindows);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        clientGroupBox = new QGroupBox(centralwidget);
        clientGroupBox->setObjectName(QStringLiteral("clientGroupBox"));
        QFont font;
        font.setPointSize(8);
        clientGroupBox->setFont(font);
        verticalLayout = new QVBoxLayout(clientGroupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        surnameLabel = new QLabel(clientGroupBox);
        surnameLabel->setObjectName(QStringLiteral("surnameLabel"));
        surnameLabel->setMinimumSize(QSize(125, 0));
        QFont font1;
        font1.setPointSize(11);
        surnameLabel->setFont(font1);

        horizontalLayout->addWidget(surnameLabel);

        surnameLineEdit = new QLineEdit(clientGroupBox);
        surnameLineEdit->setObjectName(QStringLiteral("surnameLineEdit"));
        QFont font2;
        font2.setPointSize(10);
        surnameLineEdit->setFont(font2);

        horizontalLayout->addWidget(surnameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        nameLabel = new QLabel(clientGroupBox);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setMinimumSize(QSize(125, 0));
        nameLabel->setFont(font1);

        horizontalLayout_2->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(clientGroupBox);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setFont(font2);

        horizontalLayout_2->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        patronymicLabel = new QLabel(clientGroupBox);
        patronymicLabel->setObjectName(QStringLiteral("patronymicLabel"));
        patronymicLabel->setMinimumSize(QSize(125, 0));
        patronymicLabel->setFont(font1);

        horizontalLayout_3->addWidget(patronymicLabel);

        patronymicLineEdit = new QLineEdit(clientGroupBox);
        patronymicLineEdit->setObjectName(QStringLiteral("patronymicLineEdit"));
        patronymicLineEdit->setFont(font2);

        horizontalLayout_3->addWidget(patronymicLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        mobPhoneLabel = new QLabel(clientGroupBox);
        mobPhoneLabel->setObjectName(QStringLiteral("mobPhoneLabel"));
        mobPhoneLabel->setMinimumSize(QSize(125, 0));
        mobPhoneLabel->setFont(font1);

        horizontalLayout_4->addWidget(mobPhoneLabel);

        mobilPhoneLineEdit = new QLineEdit(clientGroupBox);
        mobilPhoneLineEdit->setObjectName(QStringLiteral("mobilPhoneLineEdit"));
        mobilPhoneLineEdit->setFont(font2);

        horizontalLayout_4->addWidget(mobilPhoneLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        otherPhoneLabel = new QLabel(clientGroupBox);
        otherPhoneLabel->setObjectName(QStringLiteral("otherPhoneLabel"));
        otherPhoneLabel->setMinimumSize(QSize(125, 0));
        otherPhoneLabel->setFont(font1);

        horizontalLayout_13->addWidget(otherPhoneLabel);

        otherPhoneLineEdit = new QLineEdit(clientGroupBox);
        otherPhoneLineEdit->setObjectName(QStringLiteral("otherPhoneLineEdit"));
        otherPhoneLineEdit->setFont(font2);

        horizontalLayout_13->addWidget(otherPhoneLineEdit);


        verticalLayout->addLayout(horizontalLayout_13);


        verticalLayout_4->addWidget(clientGroupBox);

        locationGroupBox = new QGroupBox(centralwidget);
        locationGroupBox->setObjectName(QStringLiteral("locationGroupBox"));
        locationGroupBox->setFont(font);
        verticalLayout_2 = new QVBoxLayout(locationGroupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        regionLabel = new QLabel(locationGroupBox);
        regionLabel->setObjectName(QStringLiteral("regionLabel"));
        regionLabel->setMinimumSize(QSize(151, 0));
        regionLabel->setFont(font1);

        horizontalLayout_5->addWidget(regionLabel);

        regionCombo = new QComboBox(locationGroupBox);
        regionCombo->setObjectName(QStringLiteral("regionCombo"));
        regionCombo->setFont(font1);

        horizontalLayout_5->addWidget(regionCombo);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        districtLabel = new QLabel(locationGroupBox);
        districtLabel->setObjectName(QStringLiteral("districtLabel"));
        districtLabel->setMinimumSize(QSize(151, 0));
        districtLabel->setFont(font1);

        horizontalLayout_6->addWidget(districtLabel);

        districtCombo = new QComboBox(locationGroupBox);
        districtCombo->setObjectName(QStringLiteral("districtCombo"));
        districtCombo->setFont(font1);

        horizontalLayout_6->addWidget(districtCombo);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        localityLabel = new QLabel(locationGroupBox);
        localityLabel->setObjectName(QStringLiteral("localityLabel"));
        localityLabel->setMinimumSize(QSize(151, 0));
        localityLabel->setFont(font1);

        horizontalLayout_7->addWidget(localityLabel);

        localityLineEdit = new QLineEdit(locationGroupBox);
        localityLineEdit->setObjectName(QStringLiteral("localityLineEdit"));
        localityLineEdit->setFont(font2);

        horizontalLayout_7->addWidget(localityLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        streetLabel = new QLabel(locationGroupBox);
        streetLabel->setObjectName(QStringLiteral("streetLabel"));
        streetLabel->setMinimumSize(QSize(151, 0));
        streetLabel->setFont(font1);

        horizontalLayout_8->addWidget(streetLabel);

        streetLineEdit = new QLineEdit(locationGroupBox);
        streetLineEdit->setObjectName(QStringLiteral("streetLineEdit"));
        streetLineEdit->setFont(font2);

        horizontalLayout_8->addWidget(streetLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_8);


        verticalLayout_4->addWidget(locationGroupBox);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        dataBeginCheckBox = new QCheckBox(groupBox);
        dataBeginCheckBox->setObjectName(QStringLiteral("dataBeginCheckBox"));
        QFont font3;
        font3.setPointSize(12);
        dataBeginCheckBox->setFont(font3);
        dataBeginCheckBox->setChecked(false);

        horizontalLayout_11->addWidget(dataBeginCheckBox);

        dataBegindateEdit = new QDateEdit(groupBox);
        dataBegindateEdit->setObjectName(QStringLiteral("dataBegindateEdit"));
        dataBegindateEdit->setFont(font1);

        horizontalLayout_11->addWidget(dataBegindateEdit);

        dataEndCheckBox = new QCheckBox(groupBox);
        dataEndCheckBox->setObjectName(QStringLiteral("dataEndCheckBox"));
        dataEndCheckBox->setFont(font3);

        horizontalLayout_11->addWidget(dataEndCheckBox);

        dataEndDateEdit = new QDateEdit(groupBox);
        dataEndDateEdit->setObjectName(QStringLiteral("dataEndDateEdit"));
        dataEndDateEdit->setFont(font1);

        horizontalLayout_11->addWidget(dataEndDateEdit);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        deptLabel = new QLabel(groupBox);
        deptLabel->setObjectName(QStringLiteral("deptLabel"));
        deptLabel->setFont(font3);

        horizontalLayout_10->addWidget(deptLabel);

        depthLineEdit = new QLineEdit(groupBox);
        depthLineEdit->setObjectName(QStringLiteral("depthLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(depthLineEdit->sizePolicy().hasHeightForWidth());
        depthLineEdit->setSizePolicy(sizePolicy);
        depthLineEdit->setFont(font2);

        horizontalLayout_10->addWidget(depthLineEdit);

        diameterLabel = new QLabel(groupBox);
        diameterLabel->setObjectName(QStringLiteral("diameterLabel"));
        diameterLabel->setFont(font1);

        horizontalLayout_10->addWidget(diameterLabel);

        diameterCombo = new QComboBox(groupBox);
        diameterCombo->setObjectName(QStringLiteral("diameterCombo"));
        diameterCombo->setFont(font3);

        horizontalLayout_10->addWidget(diameterCombo);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pumpCheckBox = new QCheckBox(groupBox);
        pumpCheckBox->setObjectName(QStringLiteral("pumpCheckBox"));
        pumpCheckBox->setFont(font3);
        pumpCheckBox->setLayoutDirection(Qt::RightToLeft);
        pumpCheckBox->setCheckable(true);
        pumpCheckBox->setTristate(false);

        horizontalLayout_9->addWidget(pumpCheckBox);

        serviseCheckBox = new QCheckBox(groupBox);
        serviseCheckBox->setObjectName(QStringLiteral("serviseCheckBox"));
        serviseCheckBox->setFont(font1);
        serviseCheckBox->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_9->addWidget(serviseCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_9);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        noteEdit = new QTextEdit(groupBox_2);
        noteEdit->setObjectName(QStringLiteral("noteEdit"));
        noteEdit->setFont(font2);

        gridLayout_4->addWidget(noteEdit, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox_2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_2 = new QSpacerItem(390, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setFont(font1);

        horizontalLayout_12->addWidget(saveButton);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setFont(font1);

        horizontalLayout_12->addWidget(closeButton);


        verticalLayout_4->addLayout(horizontalLayout_12);

        CardClientWindows->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CardClientWindows);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 645, 26));
        CardClientWindows->setMenuBar(menubar);
        statusbar = new QStatusBar(CardClientWindows);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CardClientWindows->setStatusBar(statusbar);

        retranslateUi(CardClientWindows);

        QMetaObject::connectSlotsByName(CardClientWindows);
    } // setupUi

    void retranslateUi(QMainWindow *CardClientWindows)
    {
        CardClientWindows->setWindowTitle(QApplication::translate("CardClientWindows", "MainWindow", Q_NULLPTR));
        clientGroupBox->setTitle(QApplication::translate("CardClientWindows", "\320\233\320\270\321\207\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", Q_NULLPTR));
        surnameLabel->setText(QApplication::translate("CardClientWindows", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("CardClientWindows", "\320\230\320\274\321\217", Q_NULLPTR));
        patronymicLabel->setText(QApplication::translate("CardClientWindows", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        mobPhoneLabel->setText(QApplication::translate("CardClientWindows", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", Q_NULLPTR));
        otherPhoneLabel->setText(QApplication::translate("CardClientWindows", "\320\224\320\276\320\277.\321\202\320\265\320\273\320\265\321\204\320\276\320\275\321\213", Q_NULLPTR));
        locationGroupBox->setTitle(QApplication::translate("CardClientWindows", "\320\234\320\265\321\201\321\202\320\276\320\275\320\260\321\205\320\276\320\266\320\264\320\265\320\275\320\270\320\265", Q_NULLPTR));
        regionLabel->setText(QApplication::translate("CardClientWindows", "\320\236\320\261\320\273\320\260\321\201\321\202\321\214", Q_NULLPTR));
        districtLabel->setText(QApplication::translate("CardClientWindows", "\320\240\320\260\320\271\320\276\320\275", Q_NULLPTR));
        localityLabel->setText(QApplication::translate("CardClientWindows", "\320\235\320\260\321\201\320\265\320\273\320\265\320\275\320\275\321\213\320\271 \320\277\321\203\320\275\320\272\321\202", Q_NULLPTR));
        streetLabel->setText(QApplication::translate("CardClientWindows", "\320\243\320\273\320\270\321\206\320\260, \320\264\320\276\320\274", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("CardClientWindows", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\267\320\260\320\272\320\260\320\267\320\260", Q_NULLPTR));
        dataBeginCheckBox->setText(QApplication::translate("CardClientWindows", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\270\320\275\321\217\321\202\320\270\321\217 \n"
"\320\267\320\260\320\272\320\260\320\267\320\260", Q_NULLPTR));
        dataEndCheckBox->setText(QApplication::translate("CardClientWindows", "\320\224\320\260\321\202\320\260 \320\276\320\272\320\276\320\275\321\207\320\260\320\275\320\270\321\217 \n"
"\321\200\320\260\320\261\320\276\321\202", Q_NULLPTR));
        deptLabel->setText(QApplication::translate("CardClientWindows", "\320\223\320\273\321\203\320\261\320\270\320\275\320\260", Q_NULLPTR));
        diameterLabel->setText(QApplication::translate("CardClientWindows", "\320\224\320\270\320\260\320\274\320\265\321\202\321\200", Q_NULLPTR));
        pumpCheckBox->setText(QApplication::translate("CardClientWindows", "\320\235\320\260\321\201\320\276\321\201", Q_NULLPTR));
        serviseCheckBox->setText(QApplication::translate("CardClientWindows", "\320\237\321\200\320\265\320\264\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\276\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\321\217", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("CardClientWindows", "\320\237\321\200\320\270\320\274\320\265\321\207\320\260\320\275\320\270\321\217", Q_NULLPTR));
        saveButton->setText(QApplication::translate("CardClientWindows", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        closeButton->setText(QApplication::translate("CardClientWindows", "\320\222\321\213\320\271\321\202\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CardClientWindows: public Ui_CardClientWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDCLIENTWINDOWS_H
