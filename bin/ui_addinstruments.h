/********************************************************************************
** Form generated from reading UI file 'addinstruments.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINSTRUMENTS_H
#define UI_ADDINSTRUMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddInstruments
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameInstrLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *classInstrComboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *balanceLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *applyButton;
    QPushButton *cancelPushButton;

    void setupUi(QWidget *AddInstruments)
    {
        if (AddInstruments->objectName().isEmpty())
            AddInstruments->setObjectName(QStringLiteral("AddInstruments"));
        AddInstruments->setWindowModality(Qt::ApplicationModal);
        AddInstruments->resize(400, 272);
        verticalLayout = new QVBoxLayout(AddInstruments);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AddInstruments);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(155, 0));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        nameInstrLineEdit = new QLineEdit(AddInstruments);
        nameInstrLineEdit->setObjectName(QStringLiteral("nameInstrLineEdit"));
        nameInstrLineEdit->setMinimumSize(QSize(150, 0));
        nameInstrLineEdit->setFont(font);

        horizontalLayout->addWidget(nameInstrLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(AddInstruments);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(155, 0));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        classInstrComboBox = new QComboBox(AddInstruments);
        classInstrComboBox->setObjectName(QStringLiteral("classInstrComboBox"));
        classInstrComboBox->setMinimumSize(QSize(150, 0));
        classInstrComboBox->setFont(font);

        horizontalLayout_2->addWidget(classInstrComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(AddInstruments);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(155, 0));
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        balanceLineEdit = new QLineEdit(AddInstruments);
        balanceLineEdit->setObjectName(QStringLiteral("balanceLineEdit"));
        balanceLineEdit->setMinimumSize(QSize(155, 0));
        balanceLineEdit->setFont(font);

        horizontalLayout_4->addWidget(balanceLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        applyButton = new QPushButton(AddInstruments);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setFont(font);

        horizontalLayout_3->addWidget(applyButton);

        cancelPushButton = new QPushButton(AddInstruments);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        cancelPushButton->setFont(font);

        horizontalLayout_3->addWidget(cancelPushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(AddInstruments);

        QMetaObject::connectSlotsByName(AddInstruments);
    } // setupUi

    void retranslateUi(QWidget *AddInstruments)
    {
        AddInstruments->setWindowTitle(QApplication::translate("AddInstruments", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\260", Q_NULLPTR));
        label->setText(QApplication::translate("AddInstruments", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddInstruments", "\320\232\320\273\320\260\321\201\321\201 \320\270\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\320\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddInstruments", "\320\236\321\201\321\202\320\260\321\202\320\276\320\272", Q_NULLPTR));
        applyButton->setText(QApplication::translate("AddInstruments", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
        cancelPushButton->setText(QApplication::translate("AddInstruments", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddInstruments: public Ui_AddInstruments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINSTRUMENTS_H
