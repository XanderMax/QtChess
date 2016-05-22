#ifndef STATUS_BAR_CONTROLLER_H
#define STATUS_BAR_CONTROLLER_H

#include "Controller.h"


class StatusBarController : public Controller
{
private:

    QObject* statusBar;

protected:



    void _start();
    void _stop();
public:

    StatusBarController(Game &game);
    ~StatusBarController();

    void setStatusBarText(const QString& text);
};



#endif //STATUS_BAR_CONTROLLER_H
