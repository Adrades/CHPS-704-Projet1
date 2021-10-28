#include "mytexturematerial.h"

myTextureMaterial::myTextureMaterial(FBO *fbo)
{
    initShader("./data/texture/");
    myfbo = fbo;
    is_fbo = true;
}

myTextureMaterial::myTextureMaterial(const QString &texturePath)
{
    initShader("./data/texture/");
    myTexture = new glTexture(texturePath);
}

myTextureMaterial::~myTextureMaterial()
{
    delete m_program;
    delete myfbo;
    delete myTexture;
}

void myTextureMaterial::bindSpecific(const QGLCamera *c)
{
    if (!is_fbo){
        gl->glActiveTexture(GL_TEXTURE0);
        myTexture->bind();
    } else {
        gl->glBindTexture(GL_TEXTURE_2D, myfbo->getGetexID());
    }
    m_program->setUniformValue("myTexture", 0);
}
