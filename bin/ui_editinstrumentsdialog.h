/********************************************************************************
** Form generated from reading UI file 'editinstrumentsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITINSTRUMENTSDIALOG_H
#define UI_EDITINSTRUMENTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_EditInstrumentsDialog
{
public:
    QPushButton *applyButton;
    QPushButton *cancelButton;
    QGroupBox *groupBox;
    QLabel *noteLabel;
    QTextEdit *sourceTextEdit;
    QLabel *typeOperLabel;
    QComboBox *typeOperCombo;
    QLabel *sourceLabel;
    QTextEdit *noteTextEdit;
    QLineEdit *countInstrEdit;
    QLabel *countInstrLabel;
    QComboBox *typeInstrCombo;
    QLabel *typeInstrLabel;
    QLabel *dateLabel;
    QDateEdit *dateEdit;
    QGroupBox *groupBox_2;
    QLineEdit *balanceLineEdit;
    QLabel *balanceLabel;
    QPushButton *reCountButton;
    QPushButton *resetButton;

    void setupUi(QDialog *EditInstrumentsDialog)
    {
        if (EditInstrumentsDialog->objectName().isEmpty())
            EditInstrumentsDialog->setObjectName(QStringLiteral("EditInstrumentsDialog"));
        EditInstrumentsDialog->resize(400, 558);
        QFont font;
        font.setPointSize(11);
        EditInstrumentsDialog->setFont(font);
        applyButton = new QPushButton(EditInstrumentsDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setGeometry(QRect(130, 500, 111, 41));
        applyButton->setFont(font);
        cancelButton = new QPushButton(EditInstrumentsDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(270, 500, 111, 40));
        cancelButton->setFont(font);
        groupBox = new QGroupBox(EditInstrumentsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 381, 331));
        noteLabel = new QLabel(groupBox);
        noteLabel->setObjectName(QStringLiteral("noteLabel"));
        noteLabel->setGeometry(QRect(10, 280, 111, 31));
        noteLabel->setFont(font);
        sourceTextEdit = new QTextEdit(groupBox);
        sourceTextEdit->setObjectName(QStringLiteral("sourceTextEdit"));
        sourceTextEdit->setGeometry(QRect(140, 210, 230, 41));
        typeOperLabel = new QLabel(groupBox);
        typeOperLabel->setObjectName(QStringLiteral("typeOperLabel"));
        typeOperLabel->setGeometry(QRect(10, 55, 121, 31));
        typeOperLabel->setFont(font);
        typeOperCombo = new QComboBox(groupBox);
        typeOperCombo->setObjectName(QStringLiteral("typeOperCombo"));
        typeOperCombo->setGeometry(QRect(140, 60, 230, 25));
        sourceLabel = new QLabel(groupBox);
        sourceLabel->setObjectName(QStringLiteral("sourceLabel"));
        sourceLabel->setGeometry(QRect(10, 220, 111, 16));
        sourceLabel->setFont(font);
        noteTextEdit = new QTextEdit(groupBox);
        noteTextEdit->setObjectName(QStringLiteral("noteTextEdit"));
        noteTextEdit->setGeometry(QRect(140, 270, 230, 51));
        noteTextEdit->setFont(font);
        countInstrEdit = new QLineEdit(groupBox);
        countInstrEdit->setObjectName(QStringLiteral("countInstrEdit"));
        countInstrEdit->setGeometry(QRect(140, 160, 230, 31));
        countInstrLabel = new QLabel(groupBox);
        countInstrLabel->setObjectName(QStringLiteral("countInstrLabel"));
        countInstrLabel->setGeometry(QRect(10, 160, 111, 31));
        typeInstrCombo = new QComboBox(groupBox);
        typeInstrCombo->setObjectName(QStringLiteral("typeInstrCombo"));
        typeInstrCombo->setGeometry(QRect(140, 15, 230, 25));
        typeInstrLabel = new QLabel(groupBox);
        typeInstrLabel->setObjectName(QStringLiteral("typeInstrLabel"));
        typeInstrLabel->setGeometry(QRect(10, 10, 121, 31));
        typeInstrLabel->setFont(font);
        dateLabel = new QLabel(groupBox);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        dateLabel->setGeometry(QRect(10, 110, 121, 31));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(140, 110, 231, 31));
        groupBox_2 = new QGroupBox(EditInstrumentsDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 360, 381, 121));
        balanceLineEdit = new QLineEdit(groupBox_2);
        balanceLineEdit->setObjectName(QStringLiteral("balanceLineEdit"));
        balanceLineEdit->setGeometry(QRect(140, 20, 230, 31));
        balanceLabel = new QLabel(groupBox_2);
        balanceLabel->setObjectName(QStringLiteral("balanceLabel"));
        balanceLabel->setGeometry(QRect(10, 20, 111, 31));
        reCountButton = new QPushButton(groupBox_2);
        reCountButton->setObjectName(QStringLiteral("reCountButton"));
        reCountButton->setGeometry(QRect(120, 60, 121, 40));
        reCountButton->setFont(font);
        resetButton = new QPushButton(groupBox_2);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setGeometry(QRect(250, 60, 121, 40));
        resetButton->setFont(font);

        retranslateUi(EditInstrumentsDialog);

        QMetaObject::connectSlotsByName(EditInstrumentsDialog);
    } // setupUi

    void retranslateUi(QDialog *EditInstrumentsDialog)
    {
        EditInstrumentsDialog->setWindowTitle(QApplication::translate("EditInstrumentsDialog", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\276\321\201\321\202\320\260\321\202\320\272\320\260", Q_NULLPTR));
        applyButton->setText(QApplication::translate("EditInstrumentsDialog", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("EditInstrumentsDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
        groupBox->setTitle(QString());
        noteLabel->setText(QApplication::translate("EditInstrumentsDialog", "\320\237\321\200\320\270\320\274\320\265\321\207\320\260\320\275\320\270\320\265", Q_NULLPTR));
        typeOperLabel->setText(QApplication::translate("EditInstrumentsDialog", "\320\242\320\270\320\277 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270", Q_NULLPTR));
        sourceLabel->setText(QApplication::translate("EditInstrumentsDialog", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272", Q_NULLPTR));
        countInstrLabel->setText(QApplication::translate("EditInstrumentsDialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        typeInstrLabel->setText(QApplication::translate("EditInstrumentsDialog", "\320\234\320\260\321\202\320\265\321\200\320\270\320\260\320\273", Q_NULLPTR));
        dateLabel->setText(QApplication::translate("EditInstrumentsDialog", "\320\224\320\260\321\202\320\260 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        balanceLabel->setText(QApplication::translate("EditInstrumentsDialog", "\320\236\321\201\321\202\320\260\321\202\320\276\320\272", Q_NULLPTR));
        reCountButton->setText(QApplication::translate("EditInstrumentsDialog", "\320\237\320\265\321\200\320\265\321\201\321\207\320\270\321\202\320\260\321\202\321\214", Q_NULLPTR));
        resetButton->setText(QApplication::translate("EditInstrumentsDialog", "\320\241\320\261\321\200\320\276\321\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditInstrumentsDialog: public Ui_EditInstrumentsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITINSTRUMENTSDIALOG_H
