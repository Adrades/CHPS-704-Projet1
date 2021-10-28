#ifndef MYTEXTUREMATERIAL_H
#define MYTEXTUREMATERIAL_H

#include <Material.h>
#include <glTexture.h>
#include <FBO.h>

class myTextureMaterial  : public Material
{
public:
    myTextureMaterial(FBO *fbo);
    myTextureMaterial(const QString &texturePath);

    ~myTextureMaterial() override;

    void bindSpecific(const QGLCamera *c) override;

private:
    FBO *myfbo;
    glTexture *myTexture;
    bool is_fbo = false;
};

#endif // MYTEXTUREMATERIAL_H
