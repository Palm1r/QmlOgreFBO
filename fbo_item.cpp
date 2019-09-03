#include "fbo_item.h"

#include <QOpenGLFunctions>
#include <QtGui/QOpenGLFramebufferObject>
#include <QtQuick/QQuickWindow>

FboItemRenderer::FboItemRenderer()
{
    _qtContext = QOpenGLContext::currentContext();
    _glFuncs = _qtContext->versionFunctions<QOpenGLFunctions_3_3_Core>();
}

QOpenGLFramebufferObject *FboItemRenderer::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    format.setSamples(4);
    return new QOpenGLFramebufferObject(size, format);
}

void FboItemRenderer::render()
{
    //    _qtContext->makeCurrent(_window);
    _glFuncs->glViewport(0, 0, 320, 240);
    _glFuncs->glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    _glFuncs->glClear(GL_COLOR_BUFFER_BIT);
    _glFuncs->glFlush();
    //    _qtContext->doneCurrent();

    //    if (_window)
    //        _window->resetOpenGLState();
}

void FboItemRenderer::synchronize(QQuickFramebufferObject *item)
{
    FboItem *fboItem = static_cast<FboItem *>(item);
    _window = fboItem->window();
}

FboItem::FboItem() {}

QQuickFramebufferObject::Renderer *FboItem::createRenderer() const
{
    return new FboItemRenderer();
}
