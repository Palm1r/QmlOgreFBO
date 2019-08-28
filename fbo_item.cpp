#include "fbo_item.h"

#include <QOpenGLFunctions>
#include <QtGui/QOpenGLFramebufferObject>
#include <QtQuick/QQuickWindow>

FboItemRenderer::FboItemRenderer() {}

QOpenGLFramebufferObject *FboItemRenderer::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    format.setSamples(4);
    return new QOpenGLFramebufferObject(size, format);
}

void FboItemRenderer::render()
{
    _qtContext = QOpenGLContext::currentContext();
    //    _qtContext->makeCurrent(_window);
    QOpenGLFunctions *f = _qtContext->functions();
    f->glViewport(0, 0, 320, 240);
    f->glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    f->glClear(GL_COLOR_BUFFER_BIT);
    f->glFlush();

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
