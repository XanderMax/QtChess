#ifndef SAVE_LOAD_CONTROLLER_H
#define SAVE_LOAD_CONTROLLER_H

#include "Controller.h"

class SaveLoadController : public Controller
{
    Q_OBJECT

private:

    bool readFromFile(std::ifstream& in);
    bool writeToFile(std::ofstream& out);
protected:
    void _start();
    void _stop();

public:

    SaveLoadController(Game &game);
    ~SaveLoadController();

    Q_INVOKABLE bool readFromFile(const QString& fileName);

    Q_INVOKABLE bool writeToFile(const QString& fileName);


};


#endif //SAVE_LOAD_CONTROLLER_H
