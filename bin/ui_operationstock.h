/********************************************************************************
** Form generated from reading UI file 'operationstock.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATIONSTOCK_H
#define UI_OPERATIONSTOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OperationStock
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameInstrLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *balanceInstrLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *OperationStock)
    {
        if (OperationStock->objectName().isEmpty())
            OperationStock->setObjectName(QStringLiteral("OperationStock"));
        OperationStock->resize(400, 300);
        verticalLayout = new QVBoxLayout(OperationStock);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(OperationStock);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        nameInstrLineEdit = new QLineEdit(OperationStock);
        nameInstrLineEdit->setObjectName(QStringLiteral("nameInstrLineEdit"));

        horizontalLayout->addWidget(nameInstrLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(OperationStock);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        balanceInstrLineEdit = new QLineEdit(OperationStock);
        balanceInstrLineEdit->setObjectName(QStringLiteral("balanceInstrLineEdit"));

        horizontalLayout_2->addWidget(balanceInstrLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        saveButton = new QPushButton(OperationStock);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setFont(font);

        horizontalLayout_3->addWidget(saveButton);

        cancelButton = new QPushButton(OperationStock);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(OperationStock);

        QMetaObject::connectSlotsByName(OperationStock);
    } // setupUi

    void retranslateUi(QWidget *OperationStock)
    {
        OperationStock->setWindowTitle(QApplication::translate("OperationStock", "\320\236\320\277\320\265\321\200\320\260\321\206\320\270\320\270 \321\201\320\276 \321\201\320\272\320\273\320\260\320\264\320\276\320\274", Q_NULLPTR));
        label->setText(QApplication::translate("OperationStock", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        label_2->setText(QApplication::translate("OperationStock", "\320\236\321\202\321\201\321\202\320\260\321\202\320\276\320\272", Q_NULLPTR));
        saveButton->setText(QApplication::translate("OperationStock", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("OperationStock", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OperationStock: public Ui_OperationStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATIONSTOCK_H
