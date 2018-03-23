#ifndef EDITINSTRUMENTSDIALOG_H
#define EDITINSTRUMENTSDIALOG_H

#include <QDialog>
#include <QMap>

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

    void setIdInstrument(int idInstrument);
    void fillInstrument();

    void setCurrTypeInstruments();

    void setCurrentDate();
    void  setCurrentTab(int currentTab);
    void fillClassInstrument();
    QString getNameInstrument();
    int getIdClassInstrument();
public slots:
    void reCount();
    void fillBalance();
    void showEditBalanseWindow();
    void showEditInstrumentWindow();
    void setBalance();
    void setNameInstrument();
signals:
     void applyClick();
private:
    Ui::EditInstrumentsDialog *ui;
    int idInstrument_;
    double balance_;
    int currentTab_; //хранит выбранную текущую вкладку
    QMap<int,int> mapComboClassInstr_; // хранит соответсвие комбо и ID групп материалов
    QMap<int,int> mapComboInstr_; // хранит соответсвие комбо и ID материалов

    bool stateConnectSetBalance; //статус  соединения  со слотом изменения баланса
    bool stateConnectSetNameClass;//статус  соединения  со слотом изменения имени

    bool stateReCount;//статус пересчета остатка материала

};

#endif // EDITINSTRUMENTSDIALOG_H
