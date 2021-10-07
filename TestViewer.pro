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
    myeffect.cpp \
        src/TestViewer.cc \
        src/main.cpp \
        src/mytexturematerial.cpp

    HEADERS += \
    myeffect.h \
        src/TestViewer.h \
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
    data/effect/fragment.txt \
    data/effect/vertex.txt

