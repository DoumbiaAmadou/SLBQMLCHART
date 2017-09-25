#ifndef PIEMODEL_H
#define PIEMODEL_H

#include "pieslice.h"

#include <QObject>
class PieData;
class SliceData : public QObject
{
   Q_OBJECT
  Q_PROPERTY(int angle  READ getAngle  NOTIFY angleChanged)
  Q_PROPERTY(QString color READ getColor  NOTIFY colorChanged)
signals:
  void angleChanged();
  void colorChanged();

public:


  PieData *m_parent;

  int m_value ;
  int m_startAngle ;
  QString m_color;


  void setStartangle(int startangle){

    m_startAngle = startangle;
  }

  SliceData(PieData *parent , int value ,QString color) {

    m_value =1;
    m_parent =parent ;
    m_value =value ;
    m_color=color ;
  }

  QString getColor() const;

  void setValue(int value);

public slots :
  int  getAngle();
};
class PieData : public QObject {
  Q_OBJECT
  Q_PROPERTY(QQmlListProperty<SliceData> sliceData READ getSliceData  NOTIFY sliceDataChanged);

signals :

  void sliceDataChanged();
public :
  PieData(){
    m_sliceList= QList<SliceData*>();
  }

 QList<SliceData*> m_sliceList ;
public slots :

  QQmlListProperty<SliceData> getSliceData();
  void addElement(int value ,QString s  );

  void  reset();
  int size();

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
