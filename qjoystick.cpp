#include "qjoystick.h"
#include <QDebug>
QJoystick::QJoystick(QObject *parent) :
    QObject(parent)
{
        // Sure, we're only using the Joystick, but SDL doesn't work if video isn't initialised
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    m_joystick = NULL;
}
QJoystick::~QJoystick(){
    if (m_joystick != 0)
        SDL_JoystickClose(m_joystick);
}

//Number of avalible joysticks
int QJoystick::availableJoysticks()
{
     return SDL_NumJoysticks();
}

//Opens joystick given by number js, and closes previous one
bool QJoystick::setJoystick(int js)
{
    Q_ASSERT(js < availableJoysticks());
    Q_ASSERT(js >= 0);

    if (m_joystick != NULL){
        SDL_JoystickClose(m_joystick);
        m_joystick = NULL;
    }

    m_joystick = SDL_JoystickOpen(js);

    if(m_joystick== NULL)
        return false;
    else
        return true;
}

int QJoystick::currentJoystick(){
    if(m_joystick==NULL)
        return -1;
    else
        return SDL_JoystickIndex(m_joystick);
}

//Returns number of joystick axes
int QJoystick::joystickNumAxes()
{
    if(m_joystick!=NULL)

        return (SDL_JoystickNumAxes(m_joystick));
    else
        return -1;
}

//Returns number of joystick buttons
int QJoystick::joystickNumButtons()
{

    if(m_joystick!=NULL)
        return (SDL_JoystickNumButtons(m_joystick));
    else
        return -1;
}
//Returns joystick name
QString QJoystick::joystickName(int js)
{
    Q_ASSERT(js < availableJoysticks());
    Q_ASSERT(js >= 0);

        return QString(SDL_JoystickName(js));
}
//Reads data from joystick (needs to be done in some time intervals)
bool QJoystick::getData()
{
    if(m_joystick==NULL)
        return false;
    axis.clear();
    buttons.clear();

    SDL_Event event;
    SDL_PollEvent(&event);
    //Read all axis values
    for(int i=0;i<SDL_JoystickNumAxes(m_joystick);i++)
    {
       axis.append(SDL_JoystickGetAxis(m_joystick,i));
       //qDebug()<<"Axis i: "<<i<<"value: "<<SDL_JoystickGetAxis(m_joystick,i);
    }

    //Read all buttons values
    for(int i=0;i<SDL_JoystickNumButtons(m_joystick);i++)
    {
        buttons.append(SDL_JoystickGetButton(m_joystick,i));
    }
    return true;
}

