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
    void  setCurrentTab(int currentTab);
public slots:
    void clickApply();
    void clickReCount();
    void fillBalance();
    void showWindow();
signals:
     void applyClick();
private:
    Ui::EditInstrumentsDialog *ui;
    int idDiameter_;
    double balance_;
    int currentTab_; //хранит выбранную текущую вкладку
};

#endif // EDITINSTRUMENTSDIALOG_H
