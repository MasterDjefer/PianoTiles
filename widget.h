#ifndef WIDGET_H
#define WIDGET_H
#include "tiles.h"
#include <ctime>
#include <cstdlib>
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QDebug>
#include <QString>
#include <QMediaPlayer>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget();
    ~Widget();
private:
    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

private:
    QVector<QMediaPlayer*> mMelodies;
    QMediaPlayer *mPlayer;
    QTimer *mTimer;
    Tiles *mTiles;
    int t;

private slots:
    void onTimeOut();
};

#endif // WIDGET_H
