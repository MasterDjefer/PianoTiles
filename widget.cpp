#include "widget.h"

Widget::Widget() : t(0)
{
    srand(time(0));
    this->setFixedSize(400, 700);
    mTiles = new Tiles(this->width(), this->height());
    mTimer = new QTimer(this);
    QObject::connect(mTimer, &QTimer::timeout, this, &Widget::onTimeOut);
    mTimer->start(20);
}

Widget::~Widget()
{
    while (mMelodies.size())
    {
        QMediaPlayer *m = mMelodies.back();
        delete m;
        mMelodies.pop_back();
    }
    delete mTiles;
    delete mTimer;
    delete mPlayer;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setPen(QPen(Qt::black, 2));
    painter.drawLines(mTiles->getLines());

    painter.setBrush(QBrush(Qt::black));
    for (int i = 0; i < mTiles->getTiles().size(); ++i)
    {
        painter.drawRect(mTiles->getTiles().at(i)->x(), mTiles->getTiles().at(i)->y(),
                         mTiles->tileWidth(), mTiles->tileHeight());
    }

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        if (mTimer->isActive())
            mTimer->stop();
        else
            mTimer->start(10);
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    int index = mTiles->findTile(event->x(), event->y());
    if (index != -1)
    {
        mMelodies.push_back(new QMediaPlayer(this));
        mMelodies.back()->setMedia(QUrl::fromLocalFile("swings\\" + QString::number(rand() % 7) + ".wav"));
        mMelodies.back()->setVolume(50);
        mMelodies.back()->play();

        QPoint *p = mTiles->getTiles().at(index);
        delete p;
        mTiles->getTiles().erase(mTiles->getTiles().begin() + index);
    }
    else
        this->close();
}

void Widget::onTimeOut()
{
    t++;
    if (t % 39 == 0)
    {
        mTiles->addTile();
    }

    for (int i = 0; i < mTiles->getTiles().size(); ++i)
    {
        mTiles->getTiles().at(i)->setY(mTiles->getTiles().at(i)->y() + 3);
        if (mTiles->getTiles().at(i)->y() >= mTiles->windowHeight())
        {
            /*QPoint *p = mTiles->getTiles().at(i);
            delete p;
            mTiles->getTiles().erase(mTiles->getTiles().begin() + i);*/
            this->close();
        }
    }
    this->update();
}
