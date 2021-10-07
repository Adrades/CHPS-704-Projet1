#ifndef MYEFFECT_H
#define MYEFFECT_H

#include <Effect.h>

class MyEffect : Effect
{

public:
    MyEffect(const QString &chemin);
    void render(FBO *fbo);
private:
    QString myChemin;
};

#endif // MYEFFECT_H
