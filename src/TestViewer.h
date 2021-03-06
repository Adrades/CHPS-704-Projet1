/* Copyright (C) 2019 Stéphanie Prévost et Julien Gerhards- All Rights Reserved
 * This file is part of libQGLShaderViewer
 */


#ifndef TESTVIEWER_H
#define TESTVIEWER_H

#include "QGLShaderViewer.h"
#include "myeffect.h"
#include "myevoluedeffect.h"


/// ==============================================================
///    TestViewer
/// -------------------
///
///   Classe de test pour l'interface public de QGLShaderViewer
///   Demonstrastion basique de l'utilisation de la future lib
///
class TestViewer : public QGLShaderViewer
{
public:
    TestViewer();
    virtual ~TestViewer() override;

    virtual void  init               ()     override;
    virtual void  resizeGL(int width, int height) override;

    virtual void  createSceneEntities()     override;

    virtual void  animate            ()     override;
    virtual void  drawInformation    ()     override;
    virtual void  drawScene          ()     override;

    virtual void  keyPressEvent      (QKeyEvent * event)   override;


protected:
        QList<PointLight> m_lights;

// test pour mon 1er TP et faciliter les tests
        virtual void drawMono  ();

private:
        FBO *fbo;
        Mesh *meshCube;
        MyEffect *myeffect;
        MyEvoluedEffect *myEvoluedEffect;
        bool swapNormal;
};

#endif // TESTVIEWER_H
