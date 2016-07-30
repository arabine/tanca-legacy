#ifndef TEAMWINDOW_H
#define TEAMWINDOW_H

#include <QDialog>
#include "ui_TeamWindow.h"
#include "DbManager.h"

class TeamWindow : public QDialog
{
    Q_OBJECT

public:
    TeamWindow(QWidget *parent);

    void SetTeam(const Player &p1, const Player &p2);
    void GetTeam(Team &team);

    void Initialize(const QList<Player> &players, const QList<int> &inTeams);


private slots:
    void slotAccept();

    void slotClicked();
    void slotPlayerItemActivated();
    void slotTeamItemActivated(QListWidgetItem *item);
private:
    Ui::TeamWindow ui;

    QList<Player> mList;
    QList<Player> mSelection;
    void Update();
    int mTeamSize;
};

#endif // TEAMWINDOW_H