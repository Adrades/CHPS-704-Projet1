#include "myeffect.h"

MyEffect::MyEffect(const QString &chemin) : Effect(chemin)
{

}

void MyEffect::render(FBO *fbo)
{
    //  activation des shaders
    m_program->bind();
    // passage des uniformes, des textures ou texture de FBO.. .
    attachTexture(0, "maTexture", fbo);
    // affichage du Quadrangle couvrant l’ecran
    m_geometry->bindVertices(attribPos);
    m_geometry->draw();
    // desactivation des shaders
    m_program->release();

}
