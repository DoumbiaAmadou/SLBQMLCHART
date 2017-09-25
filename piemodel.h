#ifndef PIEMODEL_H
#define PIEMODEL_H

#include "pieslice.h"

#include <QObject>

class SliceData
{
  Q_PROPERTY(int angle  READ getAngle WRITE setAngle NOTIFY angleChanged)
  Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)


public:

  PieData * m_parent;

  int m_value =1;
  SliceData(PieData *parent , int value ,QString color) {
    m_parent =parent ;
    m_value =value ;
    m_color=color ;
  }

public slots :
  int  getAngle(){
    return (360 *m_value)/m_parent->size();
  }
};
class PieData{
  Q_OBJECT
  Q_PROPERTY(QQmlListProperty<SliceData> sliceData READ getSliceData  NOTIFY sliceDataChanged);

signals :

  void sliceDataChanged();


public slots :


  QList<SliceData*> m_sliceList ;

  PieData(){
    m_sliceList= QList();
  }

  QQmlListProperty<SliceData> getSliceData(){
    return QQmlProperty<SliceData>(this,m_sliceList);
  }
  void addElement(int value ,QString s  ){
    m_sliceList<<new PieData(this,value,s);
    int prevSize = size();
    int cptsize=0;
    foreach (SliceData * slice, m_sliceList) {
        slice->setStartangle(cptsize);
        cptsize+=(360 *m_value)/prevSize;
      }
    emit sliceDataChanged();
  }

  void  reset(){
    m_sliceList.clear();
  }
  int size(){
    int cpt =0;
    foreach (SliceData slice, m_sliceList) {
        cpt+=slice->value;
      }
    return cpt;
  }
};

class PieModel : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QQmlListProperty<PieData> pieData READ getPieData  NOTIFY PieDataChanged) ;

  QList<PieData*> m_PieData ;
public:
  explicit PieModel(QObject *parent = 0);

  QQmlListProperty<PieData> getPieData();
  void setPieData(QList<QString> list );
signals:

  void PieDataChanged() ;

public slots:

};

#endif // PIEMODEL_H
