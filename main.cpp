#include <QApplication>
#include <QQmlApplicationEngine>

#include <QtQuick/QQuickView>
#include <QGuiApplication>
#include "piechart.h"
#include "pieslice.h"
#include "piemodel.h"


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  qmlRegisterType<PieChart>("Charts", 1, 0, "PieChart");
  qmlRegisterType<sliceata>("Charts", 1, 0, "PieSlice");
  PieModel * model =  new PieModel();
  PieModel * pmodel =new PieModel();
  pmodel->addElement(2 ,);
  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return app.exec();
}
