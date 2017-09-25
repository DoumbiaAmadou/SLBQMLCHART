#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QtQuick/QQuickView>
#include <QGuiApplication>

#include "piechart.h"
#include "pieslice.h"
#include "piemodel.h"


int main(int argc, char *argv[])
{
    QGuiApplication  app(argc, argv);

    qmlRegisterType<PieChart>("Charts", 1, 0, "PieChart");
    qmlRegisterType<PieSlice>("Charts", 1, 0, "PieSlice");
    qmlRegisterType<PieModel>("Charts", 1, 0, "PieModel");

    PieModel * model =  new PieModel();
    PieData * pmodel =new PieData();
    pmodel->addElement(2 ,"Bleu");
    pmodel->addElement(4 ,"yellow");
    pmodel->addElement(1 ,"White");
    pmodel->addElement(3,"Bleu");
    pmodel->addElement(1 ,"Bleu");
    model->addPieData(pmodel);

//    QQuickView view;

//        view.rootContext()->setContextProperty("model", model);
//        view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
//        view.show();
    QQmlApplicationEngine engine;
    QQmlContext *context  =  new QQmlContext(engine.rootContext());
    context->setContextProperty("model" ,model) ;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
