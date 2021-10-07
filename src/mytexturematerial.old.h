#ifndef MYTEXTUREMATERIAL_H
#define MYTEXTUREMATERIAL_H

#include <Material.h>
#include <glTexture.h>

class myTextureMaterial  : public Material
{
public:
    myTextureMaterial(const QString &texturePath);

    ~myTextureMaterial() override;

    void bindSpecific(const QGLCamera *c) override;

private:
    glTexture *myTexture;
};

#endif // MYTEXTUREMATERIAL_H
