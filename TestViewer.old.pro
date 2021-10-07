CONFIG *=  app


TARGET = TestViewer
DESTDIR = ./



# ---- Config Qt
# ------------------------
QT     += core gui widgets
QT     += opengl xml
CONFIG += console


DEPENDPATH += . src/glm
OBJECTS_DIR = ./obj
MOC_DIR     = ./obj
UI_DIR      = ./obj

INCLUDEPATH += $$PWD/src


# --- sources
    SOURCES += \
        src/TestViewer.cc \
        src/main.cpp \
    src/mycolormaterial.cpp \
    src/myphongmaterial.cpp \
    src/mytexturematerial.cpp

    HEADERS += \
        src/TestViewer.h \
    src/mycolormaterial.h \
    src/myphongmaterial.h \
    src/mytexturematerial.h



# --- Ajout des Lib
# -----------------------

  # --- libQGLShaderViewer
        QGLShaderViewerPATH = $${PWD}/./libQGLShaderViewer
        INCLUDEPATH *= $${QGLShaderViewerPATH}/include
        INCLUDEPATH *= $${QGLShaderViewerPATH}/include/Material
        INCLUDEPATH *= $${QGLShaderViewerPATH}/include/Effect

    message( QGLShaderViewerPATH  -> $${QGLShaderViewerPATH} )
    DEFINES += APP_QGLShaderViewerLibPath=\"\\\"$${QGLShaderViewerPATH}\\\"\"

    LIBS        += -L$${QGLShaderViewerPATH}/lib  -lQGLShaderViewer



  # --- OpenGL Glu

            LIBS += -lopengl32 -lglu32

win32 {
  DEFINES += "_WIN32_WINNT=0x0600"
  LIBS += -lws2_32
}

DISTFILES += \
    data/color/fragment.txt \
    data/color/vertex.txt \
    data/texture/fragment.txt \
    data/texture/vertex.txt \
    data/phong/fragment.txt \
    data/phong/vertex.txt

