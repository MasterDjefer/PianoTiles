#ifndef TILES_H
#define TILES_H
#include <QLine>
#include <QPoint>
#include <QVector>


class Tiles
{
private:
    const int mWindowWidth;
    const int mWindowHeight;
    const int mTileWidth;
    const int mTileHeight;
    QVector<QLine> mVectorLines;
    QVector<QPoint*> mVectorTiles;

public:
    Tiles(int windowWidth, int windowHeight);
    ~Tiles();
    QVector<QLine> getLines();
    QVector<QPoint*> &getTiles();
    int tileWidth() const;
    int tileHeight() const;
    int windowHeight() const;
    int windowWidth() const;
    void addTile();
    int findTile(int x, int y);

private:
    void setLines();
};

#endif // TILES_H
