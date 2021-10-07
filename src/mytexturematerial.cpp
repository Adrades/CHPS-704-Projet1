#include "mytexturematerial.h"

myTextureMaterial::myTextureMaterial(FBO *fbo)
{
    initShader("./data/texture/");
    myfbo = fbo;
}

myTextureMaterial::~myTextureMaterial()
{
    delete m_program;
    delete myfbo;
}

void myTextureMaterial::bindSpecific(const QGLCamera *c)
{
    gl->glBindTexture(GL_TEXTURE_2D, myfbo->getGetexID());
    // bind?
    m_program->setUniformValue("myTexture", 0);
}
