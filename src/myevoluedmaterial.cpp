#include "myevoluedmaterial.h"
#include "Mesh.h"

MyEvoluedMaterial::MyEvoluedMaterial(const QVector4D &ambient, const QVector4D &diffuse, const float &f)
{
    // Initialisation des attributs et chargement des shaders
    initShader("./data/evolved/");
    diffuseTexture = new glTexture("./data/evolved/diffuse.jpg");
    specexTexture = new glTexture("./data/evolved/specexponent.jpg");
    specstrTexture = new glTexture("./data/evolved/specstrength.jpg");
    ka = ambient;
    kd = diffuse;
    ks = f;
}


MyEvoluedMaterial::~MyEvoluedMaterial(){
    // Nettoyer, Balayer, Astiquer...
    delete m_program;
    delete diffuseTexture;
    delete specexTexture;
    delete specstrTexture;
}

void MyEvoluedMaterial::bindSpecific(const QGLCamera *c){
    // Zou j'envoie les Textures au shader
    gl->glActiveTexture(GL_TEXTURE0);
    diffuseTexture->bind();
    gl->glActiveTexture(GL_TEXTURE1);
    specexTexture->bind();
    gl->glActiveTexture(GL_TEXTURE2);
    specstrTexture->bind();
}


void MyEvoluedMaterial::render(const Mesh *mesh, const QGLCamera *c, const QList<PointLight> &lights)
{
    // J'envoie les attibuts, et je rend le shader à l'écran.
    glEnable(GL_DEPTH_TEST);
    m_program->bind();
        bindSpecific(c);
        bindMatrix(c, mesh->getModelMatrix()) ;

        // Informations passées au fragment shader
        m_program->setUniformValue("ka", ka);
        //m_program->setUniformValue("kd", kd);
        m_program->setUniformValue("camPos", c->getPosition());
        m_program->setUniformValue("ks", ks);
        m_program->setUniformValue("lc", lights[0].getColor());
        m_program->setUniformValue("lightPos", lights[0].getPosition());

        mesh->getGeometry()->binds(attribPos, attribNorm, attribUvs, attribTangents) ;
        mesh->getGeometry()->draw();
    m_program->release();
}
