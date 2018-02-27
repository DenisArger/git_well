#ifndef EDITINSTRUMENTSDIALOG_H
#define EDITINSTRUMENTSDIALOG_H

#include <QDialog>

namespace Ui {
class EditInstrumentsDialog;
}

class EditInstrumentsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditInstrumentsDialog(QWidget *parent = 0);
    ~EditInstrumentsDialog();

    void fillTypeOperation();
    void comingOperation();
    void consumptionOperaton();

    void setIdDiameter(int idDiam);
    void fillTypeInstr();

    void setCurrTypeInstruments();

    void setCurrentDate();
public slots:
    void clickApply();
    void clickReCount();
    void fillBalance();
signals:
     void applyClick();
private:
    Ui::EditInstrumentsDialog *ui;
    int idDiameter_;
    double balance_;
};

#endif // EDITINSTRUMENTSDIALOG_H
