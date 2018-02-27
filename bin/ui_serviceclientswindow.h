/********************************************************************************
** Form generated from reading UI file 'serviceclientswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICECLIENTSWINDOW_H
#define UI_SERVICECLIENTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_ServiceClientsWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *locationGroupBox;
    QVBoxLayout *verticalLayout;
    QLabel *regionLabel;
    QComboBox *regionCombo;
    QLabel *districtLabel;
    QComboBox *districtCombo;
    QLabel *localityLabel;
    QLineEdit *localityLineEdit;
    QLabel *streetLabel;
    QLineEdit *streetLineEdit;
    QGroupBox *clientGroupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *surnameLabel;
    QLineEdit *surnameLineEdit;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *patronymicLabel;
    QLineEdit *patronymicLineEdit;
    QLabel *phoneLabel;
    QLineEdit *phoneLineEdit;
    QLabel *otherPhoneLabel;
    QLineEdit *otherPhoneLineEdit;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *surnameLabel_2;
    QComboBox *stateServiceCombo;
    QLabel *label_3;
    QComboBox *statePaymentCombo;
    QLabel *label_4;
    QComboBox *typePumpCombo;
    QLabel *label_5;
    QComboBox *statePumpCombo;
    QLabel *label;
    QComboBox *locationePumpCombo;
    QLabel *label_2;
    QComboBox *seasonaCombo;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *filterButton;
    QPushButton *clearFilterButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *closeButton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ServiceClientsWindow)
    {
        if (ServiceClientsWindow->objectName().isEmpty())
            ServiceClientsWindow->setObjectName(QStringLiteral("ServiceClientsWindow"));
        ServiceClientsWindow->resize(800, 1045);
        centralwidget = new QWidget(ServiceClientsWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        scrollArea_2 = new QScrollArea(centralwidget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy);
        scrollArea_2->setMinimumSize(QSize(330, 0));
        scrollArea_2->setFrameShape(QFrame::Box);
        scrollArea_2->setFrameShadow(QFrame::Raised);
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 305, 1100));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        locationGroupBox = new QGroupBox(scrollAreaWidgetContents_2);
        locationGroupBox->setObjectName(QStringLiteral("locationGroupBox"));
        QFont font;
        font.setPointSize(10);
        locationGroupBox->setFont(font);
        verticalLayout = new QVBoxLayout(locationGroupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        regionLabel = new QLabel(locationGroupBox);
        regionLabel->setObjectName(QStringLiteral("regionLabel"));
        QFont font1;
        font1.setPointSize(12);
        regionLabel->setFont(font1);

        verticalLayout->addWidget(regionLabel);

        regionCombo = new QComboBox(locationGroupBox);
        regionCombo->setObjectName(QStringLiteral("regionCombo"));
        QFont font2;
        font2.setPointSize(11);
        regionCombo->setFont(font2);

        verticalLayout->addWidget(regionCombo);

        districtLabel = new QLabel(locationGroupBox);
        districtLabel->setObjectName(QStringLiteral("districtLabel"));
        districtLabel->setFont(font1);

        verticalLayout->addWidget(districtLabel);

        districtCombo = new QComboBox(locationGroupBox);
        districtCombo->setObjectName(QStringLiteral("districtCombo"));
        districtCombo->setFont(font2);

        verticalLayout->addWidget(districtCombo);

        localityLabel = new QLabel(locationGroupBox);
        localityLabel->setObjectName(QStringLiteral("localityLabel"));
        localityLabel->setFont(font1);

        verticalLayout->addWidget(localityLabel);

        localityLineEdit = new QLineEdit(locationGroupBox);
        localityLineEdit->setObjectName(QStringLiteral("localityLineEdit"));
        localityLineEdit->setFont(font2);

        verticalLayout->addWidget(localityLineEdit);

        streetLabel = new QLabel(locationGroupBox);
        streetLabel->setObjectName(QStringLiteral("streetLabel"));
        streetLabel->setFont(font1);

        verticalLayout->addWidget(streetLabel);

        streetLineEdit = new QLineEdit(locationGroupBox);
        streetLineEdit->setObjectName(QStringLiteral("streetLineEdit"));
        streetLineEdit->setFont(font2);

        verticalLayout->addWidget(streetLineEdit);


        verticalLayout_4->addWidget(locationGroupBox);

        clientGroupBox = new QGroupBox(scrollAreaWidgetContents_2);
        clientGroupBox->setObjectName(QStringLiteral("clientGroupBox"));
        clientGroupBox->setFont(font);
        verticalLayout_2 = new QVBoxLayout(clientGroupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        surnameLabel = new QLabel(clientGroupBox);
        surnameLabel->setObjectName(QStringLiteral("surnameLabel"));
        surnameLabel->setFont(font1);

        verticalLayout_2->addWidget(surnameLabel);

        surnameLineEdit = new QLineEdit(clientGroupBox);
        surnameLineEdit->setObjectName(QStringLiteral("surnameLineEdit"));

        verticalLayout_2->addWidget(surnameLineEdit);

        nameLabel = new QLabel(clientGroupBox);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setFont(font1);

        verticalLayout_2->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(clientGroupBox);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        verticalLayout_2->addWidget(nameLineEdit);

        patronymicLabel = new QLabel(clientGroupBox);
        patronymicLabel->setObjectName(QStringLiteral("patronymicLabel"));
        patronymicLabel->setFont(font1);

        verticalLayout_2->addWidget(patronymicLabel);

        patronymicLineEdit = new QLineEdit(clientGroupBox);
        patronymicLineEdit->setObjectName(QStringLiteral("patronymicLineEdit"));

        verticalLayout_2->addWidget(patronymicLineEdit);

        phoneLabel = new QLabel(clientGroupBox);
        phoneLabel->setObjectName(QStringLiteral("phoneLabel"));
        phoneLabel->setFont(font1);

        verticalLayout_2->addWidget(phoneLabel);

        phoneLineEdit = new QLineEdit(clientGroupBox);
        phoneLineEdit->setObjectName(QStringLiteral("phoneLineEdit"));

        verticalLayout_2->addWidget(phoneLineEdit);

        otherPhoneLabel = new QLabel(clientGroupBox);
        otherPhoneLabel->setObjectName(QStringLiteral("otherPhoneLabel"));
        otherPhoneLabel->setFont(font1);

        verticalLayout_2->addWidget(otherPhoneLabel);

        otherPhoneLineEdit = new QLineEdit(clientGroupBox);
        otherPhoneLineEdit->setObjectName(QStringLiteral("otherPhoneLineEdit"));

        verticalLayout_2->addWidget(otherPhoneLineEdit);


        verticalLayout_4->addWidget(clientGroupBox);

        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 20, 281, 391));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        surnameLabel_2 = new QLabel(verticalLayoutWidget);
        surnameLabel_2->setObjectName(QStringLiteral("surnameLabel_2"));
        surnameLabel_2->setFont(font1);

        verticalLayout_3->addWidget(surnameLabel_2);

        stateServiceCombo = new QComboBox(verticalLayoutWidget);
        stateServiceCombo->setObjectName(QStringLiteral("stateServiceCombo"));
        stateServiceCombo->setFont(font2);

        verticalLayout_3->addWidget(stateServiceCombo);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout_3->addWidget(label_3);

        statePaymentCombo = new QComboBox(verticalLayoutWidget);
        statePaymentCombo->setObjectName(QStringLiteral("statePaymentCombo"));
        statePaymentCombo->setFont(font2);

        verticalLayout_3->addWidget(statePaymentCombo);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout_3->addWidget(label_4);

        typePumpCombo = new QComboBox(verticalLayoutWidget);
        typePumpCombo->setObjectName(QStringLiteral("typePumpCombo"));
        typePumpCombo->setFont(font2);

        verticalLayout_3->addWidget(typePumpCombo);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        verticalLayout_3->addWidget(label_5);

        statePumpCombo = new QComboBox(verticalLayoutWidget);
        statePumpCombo->setObjectName(QStringLiteral("statePumpCombo"));
        statePumpCombo->setFont(font2);

        verticalLayout_3->addWidget(statePumpCombo);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        verticalLayout_3->addWidget(label);

        locationePumpCombo = new QComboBox(verticalLayoutWidget);
        locationePumpCombo->setObjectName(QStringLiteral("locationePumpCombo"));
        locationePumpCombo->setFont(font2);

        verticalLayout_3->addWidget(locationePumpCombo);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        verticalLayout_3->addWidget(label_2);

        seasonaCombo = new QComboBox(verticalLayoutWidget);
        seasonaCombo->setObjectName(QStringLiteral("seasonaCombo"));
        seasonaCombo->setFont(font2);

        verticalLayout_3->addWidget(seasonaCombo);


        verticalLayout_4->addWidget(groupBox);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_3->addWidget(scrollArea_2);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setFont(font2);

        horizontalLayout_3->addWidget(tableView);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        filterButton = new QPushButton(centralwidget);
        filterButton->setObjectName(QStringLiteral("filterButton"));
        filterButton->setFont(font2);

        horizontalLayout->addWidget(filterButton);

        clearFilterButton = new QPushButton(centralwidget);
        clearFilterButton->setObjectName(QStringLiteral("clearFilterButton"));
        clearFilterButton->setFont(font2);

        horizontalLayout->addWidget(clearFilterButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy1);
        closeButton->setFont(font2);

        horizontalLayout_2->addWidget(closeButton);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer);

        ServiceClientsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ServiceClientsWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        ServiceClientsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ServiceClientsWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ServiceClientsWindow->setStatusBar(statusbar);

        retranslateUi(ServiceClientsWindow);

        QMetaObject::connectSlotsByName(ServiceClientsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ServiceClientsWindow)
    {
        ServiceClientsWindow->setWindowTitle(QApplication::translate("ServiceClientsWindow", "MainWindow", Q_NULLPTR));
        locationGroupBox->setTitle(QApplication::translate("ServiceClientsWindow", "\320\234\320\265\321\201\321\202\320\276\320\275\320\260\321\205\320\276\320\266\320\264\320\265\320\275\320\270\320\265", Q_NULLPTR));
        regionLabel->setText(QApplication::translate("ServiceClientsWindow", "\320\236\320\261\320\273\320\260\321\201\321\202\321\214", Q_NULLPTR));
        districtLabel->setText(QApplication::translate("ServiceClientsWindow", "\320\240\320\260\320\271\320\276\320\275", Q_NULLPTR));
        localityLabel->setText(QApplication::translate("ServiceClientsWindow", "\320\235\320\260\321\201\320\265\320\273\320\265\320\275\320\275\321\213\320\271 \320\277\321\203\320\275\320\272\321\202", Q_NULLPTR));
        streetLabel->setText(QApplication::translate("ServiceClientsWindow", "\320\243\320\273\320\270\321\206\320\260,\320\264\320\276\320\274", Q_NULLPTR));
        clientGroupBox->setTitle(QApplication::translate("ServiceClientsWindow", "\320\232\320\273\320\270\320\265\320\275\321\202", Q_NULLPTR));
        surnameLabel->setText(QApplication::translate("ServiceClientsWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("ServiceClientsWindow", "\320\230\320\274\321\217", Q_NULLPTR));
        patronymicLabel->setText(QApplication::translate("ServiceClientsWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        phoneLabel->setText(QApplication::translate("ServiceClientsWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", Q_NULLPTR));
        otherPhoneLabel->setText(QApplication::translate("ServiceClientsWindow", "\320\224\320\276\320\277.\321\202\320\265\320\273\320\265\321\204\320\276\320\275\321\213", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ServiceClientsWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\276\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\321\217", Q_NULLPTR));
        surnameLabel_2->setText(QApplication::translate("ServiceClientsWindow", "\320\241\321\202\320\260\321\202\321\203\321\201 \320\276\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\321\217", Q_NULLPTR));
        label_3->setText(QApplication::translate("ServiceClientsWindow", "\320\241\321\202\320\260\321\202\321\203\321\201 \320\276\320\277\320\273\320\260\321\202\321\213", Q_NULLPTR));
        label_4->setText(QApplication::translate("ServiceClientsWindow", "\320\242\320\270\320\277 \320\276\320\261\320\276\321\200\321\203\320\264\320\276\320\262\320\260\320\275\320\270\321\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("ServiceClientsWindow", "\320\235\320\260\321\201\320\276\321\201", Q_NULLPTR));
        label->setText(QApplication::translate("ServiceClientsWindow", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\275\320\260\321\201\320\276\321\201\320\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("ServiceClientsWindow", "\320\241\320\265\320\267\320\276\320\275\320\275\320\276\321\201\321\202\321\214", Q_NULLPTR));
        filterButton->setText(QApplication::translate("ServiceClientsWindow", "\320\237\320\276\320\270\321\201\320\272", Q_NULLPTR));
        clearFilterButton->setText(QApplication::translate("ServiceClientsWindow", "\320\241\320\261\321\200\320\276\321\201", Q_NULLPTR));
        closeButton->setText(QApplication::translate("ServiceClientsWindow", "\320\222\321\213\320\271\321\202\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ServiceClientsWindow: public Ui_ServiceClientsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICECLIENTSWINDOW_H
