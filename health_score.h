#ifndef HEALTH_SCORE_H
#define HEALTH_SCORE_H

#include <QGraphicsTextItem>

class health: public QGraphicsTextItem{
public:
    health(QGraphicsItem * parent=0);
    void decrease();
private:
    int Health;
};

#endif // HEALTH_SCORE_H
