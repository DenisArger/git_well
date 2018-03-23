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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditInstrumentsDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *typeInstrLabel_2;
    QComboBox *classInstrumentCombo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *typeInstrLabel;
    QLineEdit *instrumentLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *typeOperLabel;
    QComboBox *typeOperationCombo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *dateLabel;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *countInstrLabel;
    QLineEdit *countInstrEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *countInstrLabel_2;
    QLineEdit *sourseLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *noteLabel;
    QTextEdit *noteTextEdit;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *balanceLabel;
    QLineEdit *balanceLineEdit;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *reCountButton;
    QPushButton *resetButton;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *applyButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *EditInstrumentsDialog)
    {
        if (EditInstrumentsDialog->objectName().isEmpty())
            EditInstrumentsDialog->setObjectName(QStringLiteral("EditInstrumentsDialog"));
        EditInstrumentsDialog->setWindowModality(Qt::ApplicationModal);
        EditInstrumentsDialog->resize(412, 475);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EditInstrumentsDialog->sizePolicy().hasHeightForWidth());
        EditInstrumentsDialog->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        EditInstrumentsDialog->setFont(font);
        verticalLayout_4 = new QVBoxLayout(EditInstrumentsDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(EditInstrumentsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        typeInstrLabel_2 = new QLabel(groupBox);
        typeInstrLabel_2->setObjectName(QStringLiteral("typeInstrLabel_2"));
        typeInstrLabel_2->setMinimumSize(QSize(120, 0));
        typeInstrLabel_2->setFont(font);

        horizontalLayout->addWidget(typeInstrLabel_2);

        classInstrumentCombo = new QComboBox(groupBox);
        classInstrumentCombo->setObjectName(QStringLiteral("classInstrumentCombo"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(classInstrumentCombo->sizePolicy().hasHeightForWidth());
        classInstrumentCombo->setSizePolicy(sizePolicy1);
        classInstrumentCombo->setMinimumSize(QSize(189, 0));

        horizontalLayout->addWidget(classInstrumentCombo);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        typeInstrLabel = new QLabel(groupBox);
        typeInstrLabel->setObjectName(QStringLiteral("typeInstrLabel"));
        typeInstrLabel->setMinimumSize(QSize(120, 0));
        typeInstrLabel->setFont(font);

        horizontalLayout_2->addWidget(typeInstrLabel);

        instrumentLineEdit = new QLineEdit(groupBox);
        instrumentLineEdit->setObjectName(QStringLiteral("instrumentLineEdit"));
        sizePolicy1.setHeightForWidth(instrumentLineEdit->sizePolicy().hasHeightForWidth());
        instrumentLineEdit->setSizePolicy(sizePolicy1);
        instrumentLineEdit->setMinimumSize(QSize(120, 0));

        horizontalLayout_2->addWidget(instrumentLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        typeOperLabel = new QLabel(groupBox);
        typeOperLabel->setObjectName(QStringLiteral("typeOperLabel"));
        typeOperLabel->setMinimumSize(QSize(120, 0));
        typeOperLabel->setFont(font);

        horizontalLayout_3->addWidget(typeOperLabel);

        typeOperationCombo = new QComboBox(groupBox);
        typeOperationCombo->setObjectName(QStringLiteral("typeOperationCombo"));
        sizePolicy1.setHeightForWidth(typeOperationCombo->sizePolicy().hasHeightForWidth());
        typeOperationCombo->setSizePolicy(sizePolicy1);
        typeOperationCombo->setMinimumSize(QSize(190, 0));

        horizontalLayout_3->addWidget(typeOperationCombo);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        dateLabel = new QLabel(groupBox);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        dateLabel->setMinimumSize(QSize(120, 0));

        horizontalLayout_4->addWidget(dateLabel);

        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setMinimumSize(QSize(189, 0));

        horizontalLayout_4->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        countInstrLabel = new QLabel(groupBox);
        countInstrLabel->setObjectName(QStringLiteral("countInstrLabel"));
        countInstrLabel->setMinimumSize(QSize(120, 0));

        horizontalLayout_5->addWidget(countInstrLabel);

        countInstrEdit = new QLineEdit(groupBox);
        countInstrEdit->setObjectName(QStringLiteral("countInstrEdit"));
        sizePolicy1.setHeightForWidth(countInstrEdit->sizePolicy().hasHeightForWidth());
        countInstrEdit->setSizePolicy(sizePolicy1);
        countInstrEdit->setMinimumSize(QSize(120, 0));

        horizontalLayout_5->addWidget(countInstrEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        countInstrLabel_2 = new QLabel(groupBox);
        countInstrLabel_2->setObjectName(QStringLiteral("countInstrLabel_2"));
        countInstrLabel_2->setMinimumSize(QSize(120, 0));

        horizontalLayout_6->addWidget(countInstrLabel_2);

        sourseLineEdit = new QLineEdit(groupBox);
        sourseLineEdit->setObjectName(QStringLiteral("sourseLineEdit"));
        sizePolicy1.setHeightForWidth(sourseLineEdit->sizePolicy().hasHeightForWidth());
        sourseLineEdit->setSizePolicy(sizePolicy1);
        sourseLineEdit->setMinimumSize(QSize(120, 0));

        horizontalLayout_6->addWidget(sourseLineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        noteLabel = new QLabel(groupBox);
        noteLabel->setObjectName(QStringLiteral("noteLabel"));
        noteLabel->setMaximumSize(QSize(16777215, 55));
        noteLabel->setSizeIncrement(QSize(0, 0));
        noteLabel->setFont(font);

        horizontalLayout_7->addWidget(noteLabel);

        noteTextEdit = new QTextEdit(groupBox);
        noteTextEdit->setObjectName(QStringLiteral("noteTextEdit"));
        sizePolicy1.setHeightForWidth(noteTextEdit->sizePolicy().hasHeightForWidth());
        noteTextEdit->setSizePolicy(sizePolicy1);
        noteTextEdit->setMaximumSize(QSize(16777215, 55));
        noteTextEdit->setFont(font);

        horizontalLayout_7->addWidget(noteTextEdit);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_4->addWidget(groupBox);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_2 = new QGroupBox(EditInstrumentsDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        balanceLabel = new QLabel(groupBox_2);
        balanceLabel->setObjectName(QStringLiteral("balanceLabel"));

        horizontalLayout_8->addWidget(balanceLabel);

        balanceLineEdit = new QLineEdit(groupBox_2);
        balanceLineEdit->setObjectName(QStringLiteral("balanceLineEdit"));
        sizePolicy1.setHeightForWidth(balanceLineEdit->sizePolicy().hasHeightForWidth());
        balanceLineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(balanceLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        reCountButton = new QPushButton(groupBox_2);
        reCountButton->setObjectName(QStringLiteral("reCountButton"));
        reCountButton->setFont(font);

        horizontalLayout_9->addWidget(reCountButton);

        resetButton = new QPushButton(groupBox_2);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setFont(font);

        horizontalLayout_9->addWidget(resetButton);


        verticalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        applyButton = new QPushButton(EditInstrumentsDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setFont(font);

        horizontalLayout_10->addWidget(applyButton);

        cancelButton = new QPushButton(EditInstrumentsDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout_10->addWidget(cancelButton);


        verticalLayout_3->addLayout(horizontalLayout_10);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(EditInstrumentsDialog);

        QMetaObject::connectSlotsByName(EditInstrumentsDialog);
    } // setupUi

    void retranslateUi(QDialog *EditInstrumentsDialog)
    {
        EditInstrumentsDialog->setWindowTitle(QApplication::translate("EditInstrumentsDialog", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\276\321\201\321\202\320\260\321\202\320\272\320\260", Q_NULLPTR));
        groupBox->setTitle(QString());
        typeInstrLabel_2->setText(QApplication::translate("EditInstrumentsDialog", "\320\232\320\273\320\260\321\201\321\201", Q_NULLPTR));
        typeInstrLabel->setText(QApplication::translate("EditInstrumentsDialog", "\320\234\320\260\321\202\320\265\321\200\320\270\320\260\320\273", Q_NULLPTR));
        typeOperLabel->setText(QApplication::translate("EditInstrumentsDialog", "\320\242\320\270\320\277 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270", Q_NULLPTR));
        dateLabel->setText(QApplication::translate("EditInstrumentsDialog", "\320\224\320\260\321\202\320\260 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270", Q_NULLPTR));
        countInstrLabel->setText(QApplication::translate("EditInstrumentsDialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        countInstrLabel_2->setText(QApplication::translate("EditInstrumentsDialog", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272", Q_NULLPTR));
        noteLabel->setText(QApplication::translate("EditInstrumentsDialog", "\320\237\321\200\320\270\320\274\320\265\321\207\320\260\320\275\320\270\320\265", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        balanceLabel->setText(QApplication::translate("EditInstrumentsDialog", "\320\236\321\201\321\202\320\260\321\202\320\276\320\272", Q_NULLPTR));
        reCountButton->setText(QApplication::translate("EditInstrumentsDialog", "\320\237\320\265\321\200\320\265\321\201\321\207\320\270\321\202\320\260\321\202\321\214", Q_NULLPTR));
        resetButton->setText(QApplication::translate("EditInstrumentsDialog", "\320\241\320\261\321\200\320\276\321\201", Q_NULLPTR));
        applyButton->setText(QApplication::translate("EditInstrumentsDialog", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("EditInstrumentsDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditInstrumentsDialog: public Ui_EditInstrumentsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITINSTRUMENTSDIALOG_H
