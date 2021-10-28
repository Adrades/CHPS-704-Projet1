#include "myphongmaterial.h"
#include "Mesh.h"
#include <glTexture.h>

myPhongMaterial::myPhongMaterial(const QVector4D &ambient, const QVector4D &diffuse, const float &f)
{
    initShader("./data/phong/");
    ka = ambient;
    kd = diffuse;
    ks = f;
}

myPhongMaterial::~myPhongMaterial()
{
    delete m_program;
}

void myPhongMaterial::bindSpecific(const QGLCamera *c)
{

}

void myPhongMaterial::render(const Mesh *mesh, const QGLCamera *c, const QList<PointLight> &lights)
{
    glEnable(GL_DEPTH_TEST);
    m_program->bind();
        bindSpecific(c);
        bindMatrix(c, mesh->getModelMatrix()) ;

        // Informations passées au fragment shader
        m_program->setUniformValue("ka", ka);
        m_program->setUniformValue("kd", kd);
        m_program->setUniformValue("camPos", c->getPosition());
        m_program->setUniformValue("ks", ks);
        m_program->setUniformValue("lc", lights[0].getColor());
        m_program->setUniformValue("lightPos", lights[0].getPosition());

        mesh->getGeometry()->binds(attribPos, attribNorm, attribUvs, attribTangents) ;
        mesh->getGeometry()->draw();
    m_program->release();
}

