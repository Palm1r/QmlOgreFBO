#pragma once

#include <QObject>
#include <QOpenGLContext>
#include <QQuickFramebufferObject>

class FboItemRenderer : public QQuickFramebufferObject::Renderer {
public:
    FboItemRenderer();
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;
    void render() override;
    void synchronize(QQuickFramebufferObject *item) override;

private:
    QQuickWindow *_window;
    QOpenGLContext *_qtContext;
};

class FboItem : public QQuickFramebufferObject
{
    Q_OBJECT
public:
    FboItem();

    Renderer *createRenderer() const;
signals:

public slots:

public:
};
