#include <QApplication>
#include <QQmlApplicationEngine>

#include <QtQuick/QQuickView>
#include <QGuiApplication>
#include "piechart.h"
#include "pieslice.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  qmlRegisterType<PieChart>("Charts", 1, 0, "PieChart");
  qmlRegisterType<sliceata>("Charts", 1, 0, "PieSlice");

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return app.exec();
}
