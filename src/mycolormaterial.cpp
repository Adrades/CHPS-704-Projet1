#include "mycolormaterial.h"

myColorMaterial::myColorMaterial(const QVector4D &col)
{
    initShader("./data/");
    myColor = col;
}

myColorMaterial::~myColorMaterial(){
    delete m_program;
}

void myColorMaterial::bindSpecific(const QGLCamera *c){
    m_program->setUniformValue("myColor", myColor);
}

