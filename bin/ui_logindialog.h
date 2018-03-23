/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *loginLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *passLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *enterButton;
    QPushButton *cancelPushButton;

    void setupUi(QWidget *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->setWindowModality(Qt::ApplicationModal);
        LoginDialog->resize(270, 197);
        QIcon icon;
        icon.addFile(QStringLiteral("../bin/icon/key.png"), QSize(), QIcon::Disabled, QIcon::Off);
        LoginDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(130, 0));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        loginLineEdit = new QLineEdit(LoginDialog);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));
        loginLineEdit->setFont(font);

        horizontalLayout->addWidget(loginLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(130, 0));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        passLineEdit = new QLineEdit(LoginDialog);
        passLineEdit->setObjectName(QStringLiteral("passLineEdit"));
        passLineEdit->setFont(font);
        passLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        enterButton = new QPushButton(LoginDialog);
        enterButton->setObjectName(QStringLiteral("enterButton"));
        enterButton->setFont(font);

        horizontalLayout_3->addWidget(enterButton);

        cancelPushButton = new QPushButton(LoginDialog);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        cancelPushButton->setFont(font);

        horizontalLayout_3->addWidget(cancelPushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(LoginDialog);

        enterButton->setDefault(false);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QWidget *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\320\222\321\205\320\276\320\264 \320\262 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203", Q_NULLPTR));
        label->setText(QApplication::translate("LoginDialog", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginDialog", "\320\237\320\260\321\200\320\276\320\273\321\214", Q_NULLPTR));
        enterButton->setText(QApplication::translate("LoginDialog", "\320\222\320\276\320\271\321\202\320\270", Q_NULLPTR));
        enterButton->setShortcut(QApplication::translate("LoginDialog", "Return, Enter", Q_NULLPTR));
        cancelPushButton->setText(QApplication::translate("LoginDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
