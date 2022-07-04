#ifndef PLAYERNAMING_H
#define PLAYERNAMING_H

#include <QDialog>

namespace Ui {
class PlayerNaming;
}

class PlayerNaming : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerNaming(QWidget *parent = nullptr);
    ~PlayerNaming();

private:
    Ui::PlayerNaming *ui;
};

#endif // PLAYERNAMING_H
