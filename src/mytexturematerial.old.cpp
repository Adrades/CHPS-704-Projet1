#include "mytexturematerial.h"

myTextureMaterial::myTextureMaterial(const QString &texturePath)
{
    initShader("./data/texture/");
    myTexture = new glTexture(texturePath);
}

myTextureMaterial::~myTextureMaterial()
{
    delete m_program;
    delete myTexture;
}

void myTextureMaterial::bindSpecific(const QGLCamera *c)
{
    gl->glActiveTexture(GL_TEXTURE0);
    myTexture->bind();
    m_program->setUniformValue("myTexture", 0);
}
