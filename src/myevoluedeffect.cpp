#include "myevoluedeffect.h"

MyEvoluedEffect::MyEvoluedEffect(const QString &chemin) : Effect(chemin)
{

}

void MyEvoluedEffect::render(FBO *fbo, bool swapNormal)
{
    //  activation des shaders
    m_program->bind();
    // passage des uniformes, des textures ou texture de FBO.. .
    attachTexture(0, "maTexture", fbo);
    m_program->setUniformValue("swapNormal", swapNormal);
    // affichage du Quadrangle couvrant l’ecran
    m_geometry->bindVertices(attribPos);
    m_geometry->draw();
    // desactivation des shaders
    m_program->release();

}
