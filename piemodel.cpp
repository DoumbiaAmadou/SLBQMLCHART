#include "piemodel.h"

PieModel::PieModel(QObject *parent) : QObject(parent)
{
  m_PieData<< new PieData()
}

QQmlListProperty<PieData> PieModel::getPieData()
{
  return QQmlListProperty<PieData>(this,QList<PieData*>());
}

void PieModel::setPieData(QList<QString> list)
{

}
