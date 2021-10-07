#ifndef MYPHONGMATERIAL_H
#define MYPHONGMATERIAL_H

#include <Material.h>

class myPhongMaterial : public Material
{
public:
    myPhongMaterial(const QVector4D &ambient, const QVector4D &diffuse, const float &f);
    ~myPhongMaterial() override;

    void bindSpecific(const QGLCamera *c) override;

    void render(const Mesh *mesh, const QGLCamera *c, const QList<PointLight> &lights) override;

private:
    QVector4D ka;
    QVector4D kd;
    float ks;
};

#endif // MYPHONGMATERIAL_H
