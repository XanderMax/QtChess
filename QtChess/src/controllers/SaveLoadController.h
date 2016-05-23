#ifndef SAVE_LOAD_CONTROLLER_H
#define SAVE_LOAD_CONTROLLER_H

#include "Controller.h"

class SaveLoadController : public Controller
{
    Q_OBJECT

private:
    bool writeToFile(std::ofstream& out);
protected:
    void _start();
    void _stop();

public:

    SaveLoadController(Game &game);
    ~SaveLoadController();

    Q_INVOKABLE bool readFromFile(const QUrl& fileName);

    Q_INVOKABLE bool writeToFile(const QUrl& fileName);


};


#endif //SAVE_LOAD_CONTROLLER_H
