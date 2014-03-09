#ifndef QJOYSTICK_H
#define QJOYSTICK_H

#include <QObject>
#include <SDL/SDL.h>

class QJoystick : public QObject
{
    Q_OBJECT
public:
    explicit QJoystick(QObject *parent = 0);
    ~QJoystick();

    //Returns number of available joysticks
    int availableJoysticks();

    //Returns index of joystick
    int currentJoystick();

    //Returns name of joystick
    QString joystickName(int id);

    //Return number of joystick axes and buttons
    int joystickNumAxes();
    int joystickNumButtons();

    //Holds info about axix and buttons
    QList<int> axis;
    QList<bool> buttons;

    bool setJoystick(int jsNumber);

public slots:
    //Reads data from joystick (needs to be done in some time intervals)
    bool getData();

private:
    SDL_Joystick* m_joystick;

};

#endif // QJOYSTICK_H
