#ifndef MYEVOLUEDEFFECT_H
#define MYEVOLUEDEFFECT_H

#include <Effect.h>

class MyEvoluedEffect : Effect
{

public:
    MyEvoluedEffect(const QString &chemin);
    void render(FBO *fbo, bool swapNormal);
private:
    QString myChemin;
};

#endif // MYEVOLUEDEFFECT_H
