#include "piemodel.h"

PieModel::PieModel(QObject *parent) : QObject(parent)
{
  m_PieData<< new PieData();
}

QQmlListProperty<PieData> PieModel::getPieData()
{
  return QQmlListProperty<PieData>(this,m_PieData);
}

void PieModel::setPieData(QList<QString> list)
{

}



void PieData::addElement(int value, QString s){
  m_sliceList<<new SliceData(this,value,s);
  int prevSize = size();
  int cptsize=0;
  foreach (SliceData * slice, m_sliceList) {
      slice->setStartangle(cptsize);
      cptsize+=(360 *slice->m_value)/prevSize;
    }
  emit sliceDataChanged();
}

void PieData::reset(){
  m_sliceList.clear();
}

int PieData::size(){
  int cpt =0;
  foreach (SliceData* slice, m_sliceList) {
      cpt+=slice->m_value;
    }
  return cpt;
}

void SliceData::setValue(int value)
{
  m_value = value;
}

QString SliceData::getColor() const
{
  return m_color;
}

int SliceData::getAngle(){
  return (360 *m_value)/m_parent->size();
}
 QQmlListProperty<SliceData> PieData::getSliceData(){

    return QQmlListProperty<SliceData>(this,m_sliceList);
 }
