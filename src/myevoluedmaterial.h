#ifndef MYEVOLUEDMATERIAL_H
#define MYEVOLUEDMATERIAL_H

#include <Material.h>
#include <glTexture.h>

class MyEvoluedMaterial : public Material
{
public:
    MyEvoluedMaterial(const QVector4D &ambient, const QVector4D &diffuse, const float &f);

    ~MyEvoluedMaterial() override;

    void bindSpecific(const QGLCamera *c) override;

    void render(const Mesh *mesh, const QGLCamera *c, const QList<PointLight> &lights) override;

private:
    glTexture *diffuseTexture;
    glTexture *specexTexture;
    glTexture *specstrTexture;
    QVector4D ka;
    QVector4D kd;
    float ks;
};

#endif // MYEVOLUEDMATERIAL_H
