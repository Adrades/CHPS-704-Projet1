#include "TestViewer.h"

#include "ColorMaterial.h"
#include "TextureMaterial.h"
#include "GridMaterial.h"
#include "PhongMaterial.h"

//TPs
//#include "mycolormaterial.h"
#include "mytexturematerial.h"
//#include "myeffect.h"
//#include "myphongmaterial.h"

//Projet
#include "myevoluedmaterial.h"
#include "myevoluedeffect.h"

TestViewer::TestViewer() : QGLShaderViewer ()
{}
TestViewer::~TestViewer()
{}

void TestViewer::resizeGL(int width, int height)
{
    QGLShaderViewer::resizeGL(width, height);
    fbo->resize(width, height);
}

void  TestViewer::init               ()
{
    getCamera()->setNearAndFar( 0.01, 100 );
    getCamera()->setView(QVector3D(0,0.2,4), QVector3D(0,1,0), QVector3D(0,0,0) );

    swapNormal = false;
    fbo = new FBO(width(), height(), GL_RGBA8);
//    myeffect = new MyEffect("./data/effect/");
    myEvoluedEffect = new MyEvoluedEffect("./data/evolvedEffect/");

    startAnimation();
}

void  TestViewer::createSceneEntities()
{
    addGeometry( "lapin", new Geometry(":/3d/Bunny.obj") );
    addGeometry( "sol",   new Geometry(":/3d/sol.obj") );
    addGeometry( "cube",  new Geometry(":/3d/cube.obj") );
    addGeometry( "quad",  new Geometry(":/3d/quad.obj") );

    addMaterial( "jaune", new ColorMaterial(QVector4D(1.0f,1.f,0.f,1.0f)) );
    addMaterial( "rouge", new ColorMaterial(Qt::red) );
    addMaterial( "sol",   new TextureMaterial(QString(":/textures/sol.jpg")) );
    addMaterial( "phong", new PhongMaterial( QVector4D(0.1f,0.1f,0.1f,1.f),
                                             QVector4D(0.1f,0.9f,0.4f,1.f), 128) );

    addMaterial( "lapinBlanc",    new TextureMaterial(QString(":/textures/bunny2.jpg")) );
    addMaterial( "grid",          new GridMaterial(2, Qt::red, 0.03f ) );


    // mon code
//    addMaterial("bleu", new myColorMaterial(QVector4D(0.1f,0.1f, 1.0f, 1.0f)));
//    addMaterial("sol2", new myTextureMaterial(QString(":/textures/sol.jpg")));
//    addMaterial("myPhong", new myPhongMaterial( QVector4D(0.1f,0.1f,0.1f,1.f),
//                                                QVector4D(0.1f,0.9f,0.4f,1.f), 128));


    addMaterial("myFBO", new myTextureMaterial(fbo));

    // Code qui ajoute mon matériel
    addMaterial("myEvolvedMaterial", new MyEvoluedMaterial(QVector4D(0.1f,0.1f,0.1f,1.f), QVector4D(0.1f,0.9f,0.4f,1.f), 128));

    meshCube = new Mesh(getGeometry("cube"), getMaterial("myFBO"));


    Mesh *  mesh;

    // lapin éclairé
    mesh = new Mesh( getGeometry("lapin"), getMaterial("jaune") );
    addEntityInScene("LapinJaune", mesh );
    //mesh->translate(QVector3D(0,0,-2));
    mesh->translate(QVector3D(0,1,1));



    // Rajout, lapin bleu
//    mesh = new Mesh( getGeometry("lapin"), getMaterial("bleu") );
//    addEntityInScene("LapinBleu", mesh );
//    //mesh->translate(QVector3D(0,0,-2));
//    mesh->translate(QVector3D(1,1,0));

//    mesh = new Mesh( getGeometry("sol"), getMaterial("sol2") );
//    addEntityInScene("mySol", mesh );
//    //mesh->translate(QVector3D(0,0,-2));
//    mesh->translate(QVector3D(0,-1,0));

    // Cube grillé
    //mesh = new Mesh( getGeometry("cube"), getMaterial("grid"), true);
    //addEntityInScene("cubeGrid", mesh );

    // Lapin jaune, ex test
    mesh = new Mesh( getGeometry("lapin"), getMaterial("lapinBlanc"), true);
    addEntityInScene("lapinBlanc", mesh );
    mesh->translate(QVector3D(0,1,0));
    mesh->scale(QVector3D(6.0f,6.0f,6.0f));

    // Lapin Evolved
    mesh = new Mesh(getGeometry("lapin"), getMaterial("myEvolvedMaterial"), true);
      addEntityInScene("lapinEvolvedAkaTheBigOne", mesh );
      mesh->scale(QVector3D(16.f,16.f,16.f));
      mesh->translate(QVector3D(0.5,2,0.5));

      // Cube Evolved
      mesh = new Mesh(getGeometry("cube"), getMaterial("myEvolvedMaterial"), true);
        addEntityInScene("CubeEvolved", mesh );
        mesh->scale(QVector3D(.6f,.6f,.6f));
        mesh->translate(QVector3D(0.,-1.,0.));

//    // Lapin Phong
//    mesh = new Mesh( getGeometry("lapin"), getMaterial("myPhong"), true);
//     addEntityInScene("lapinPhong", mesh );
//     mesh->scale(QVector3D(6.f,6.f,6.f));

     // La lumière spec ajoutée de base dans le tp, possible de la changer pour un meilleur rendu
     m_lights.push_back( PointLight( getCamera()->getPosition() + getCamera()->getRightDir()*4.f, Qt::white));
}


void  TestViewer::animate            ()
{
    foreach (Mesh * entity, getListEntityInScene() )
    {
        entity->rotateOnSelf( 0.05f, QVector3D(1,1,1) );
    }
}

void  TestViewer::drawInformation    ()
{
    glColor4f(1.,1.,0., 1.0);
    QFont font( "Arial", 10);
    font.setLetterSpacing(QFont::AbsoluteSpacing, 1 );
    font.setStretch( 100 );

    // Affichage du texte 2D
    // ----------------------
    //   coord screen
    /// TODO - Ajouter l'affichage du texte 2D.
    ///
    int y = 0, dy = 30;
    drawText(10,  y+=dy, QString("S pour changer la vue"), Qt::white, font);
}



void  TestViewer::drawScene()
{
    glEnable(GL_DEPTH_TEST);
     drawMono();
}


// rendu monoscopic
void TestViewer::drawMono()
{
    // Creation de la vue mono
    fbo->bind();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    foreach( Mesh * entity, getListEntityInScene() )
    {
        entity->render(getCamera(), m_lights);
    }
    fbo->release();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    meshCube->render(getCamera(), m_lights);
//    myeffect->render(fbo);
    myEvoluedEffect->render(fbo, swapNormal);
}


void  TestViewer::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
    case Qt::Key_L : qDebug() << " Vous avez taper la touche L"; break;
    case Qt::Key_S : swapNormal = !swapNormal; break;

        default: QGLShaderViewer::keyPressEvent(event); break;
    }
    qDebug() << " key : " <<  QKeySequence(event->key()).toString();
    update();
}
