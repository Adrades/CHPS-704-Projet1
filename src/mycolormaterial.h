#ifndef MYCOLORMATERIAL_H
#define MYCOLORMATERIAL_H

#include <Material.h>

class myColorMaterial : public Material
{
public:
    /*myColorMaterial(const QColor    & col);*/
    myColorMaterial(const QVector4D & col);
    ~myColorMaterial() override;

    void bindSpecific(const QGLCamera *c) override;

private:
    QVector4D myColor;
};


#endif // MYCOLORMATERIAL_H
