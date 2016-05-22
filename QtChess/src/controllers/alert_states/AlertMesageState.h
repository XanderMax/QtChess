#ifndef ALERT_MESSAGE_STATE_H
#define ALERT_MESSAGE_STATE_H

#include "../AlertMessageController.h"

class AlertMessageState
{
private:

    int token;

protected:

    AlertMessageController& controller;


public:
    AlertMessageState(AlertMessageController& _controller, int _token);
    ~AlertMessageState(){}

    int getToken() {return token;}
};





#endif //ALERT_MESSAGE_STATE_H
