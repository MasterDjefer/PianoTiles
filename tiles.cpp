#include "tiles.h"

Tiles::Tiles(int windowWidth, int windowHeight) : mWindowWidth(windowWidth), mWindowHeight(windowHeight),
                                                  mTileWidth(windowWidth / 4),
                                                  mTileHeight(windowHeight / 6)
{
    setLines();

    int x = (rand() % 4) * mTileWidth;
    mVectorTiles.push_back(new QPoint(x, -mTileHeight));
}

Tiles::~Tiles()
{
    while (mVectorTiles.size() > 0)
    {
        QPoint *p = mVectorTiles.back();
        delete p;
        mVectorTiles.pop_back();
    }
}

QVector<QLine> Tiles::getLines()
{
    return mVectorLines;
}

QVector<QPoint *> &Tiles::getTiles()
{
    return mVectorTiles;
}

int Tiles::tileWidth() const
{
    return mTileWidth;
}

int Tiles::tileHeight() const
{
    return mTileHeight;
}

int Tiles::windowHeight() const
{
    return mWindowHeight;
}

int Tiles::windowWidth() const
{
    return mWindowWidth;
}

void Tiles::addTile()
{
    int x = (rand() % 4) * mTileWidth;
    while (true)
    {
        if (mVectorTiles.size())
        {
            if (mVectorTiles.back()->x() == x)
            {
                x = (rand() % 4) * mTileWidth;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    mVectorTiles.push_back(new QPoint(x, -mTileHeight));

}

int Tiles::findTile(int x, int y)
{
    for (int i = 0; i < mVectorTiles.size(); ++i)
    {
        if (mVectorTiles.at(i)->x() <= x && x <= mVectorTiles.at(i)->x() + mTileWidth &&
            mVectorTiles.at(i)->y() <= y && y <= mVectorTiles.at(i)->y() + mTileHeight)
            return i;
    }
    return -1;
}

void Tiles::setLines()
{
    int incX = mWindowWidth / 4;
    for (int i = 1; i < 4; ++i)
    {
        mVectorLines.push_back(QLine(incX * i, 0, incX * i, mWindowHeight));
    }
}
