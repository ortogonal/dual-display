#include <memory>
#include <vector>

#include <QDebug>
#include <QFile>
#include <QGuiApplication>
#include <QScreen>

#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickView>

QQuickView *createViewForScreen(QScreen *screen, const QString &filename)
{
    qInfo().noquote() << "Adding view to screen:" << screen->name();
    qInfo().noquote().nospace() << "   Resolution: " << screen->size().width() << "x"
                                << screen->size().height();
    auto v = new QQuickView;
    v->setScreen(screen);
    v->setResizeMode(QQuickView::SizeRootObjectToView);

    QObject::connect(v->engine(), &QQmlEngine::quit, qGuiApp, &QCoreApplication::quit);

    v->setSource(QUrl(filename));
    v->showFullScreen();
    return v;
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    std::vector<std::unique_ptr<QQuickView>> views;

    for (const auto screen : app.screens()) {
        QString filename = ":/" + screen->name().toLower() + "-main.qml";
        if (QFile::exists(filename)) {
            // This path will be used in QML namespace, must add qrc
            filename = "qrc" + filename;
            views.push_back(std::make_unique<QQuickView>(createViewForScreen(screen, filename)));
        }
    }

    return app.exec();
}
