#ifndef ALERT_MESSAGE_CONTROLLER_H
#define ALERT_MESSAGE_CONTROLLER_H

#include <QString>

#include "Controller.h"


class AlertMessageController : public Controller
{
private:
protected:

    void _start();
    void _stop();

public:

    AlertMessageController(Game& game);
    ~AlertMessageController();

    void pushStandardOkAlert(const QString& title, const QString& body);

};





#endif //ALERT_MESSAGE_CONTROLLER_H
