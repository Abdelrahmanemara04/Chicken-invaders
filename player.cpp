#include "player.h"

Player::Player(QGraphicsScene* scene) {
    score = new health_score;
    health = new health_score;
    this->scene = scene;
}


health_score* Player :: get_score (){
    return (this-> score);
}

health_score* Player :: get_health (){
    return (this-> health);
}
void Player::keyPressEvent(QKeyEvent *event)
{
    // bulletsound = new QMediaPlayer();
    // bullet->setMedia(":/sounds/laser sound.mp3");

    // *  Event Handling for the Player **

    if(event->key()== Qt::Key_Left)
    {
        if(pos().x()>0) // to prevent the player from getting out of the screen
        {
            setPos(x()-70,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(pos().x()+100<800) // to prevent the player from getting out of the screen
            setPos(x()+70,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet(this);


        this->scene->addItem(bullet);
        bullet->setPos(x()+40, y());
        //sound
        // if (bulletsound-> state()==QMediaPlayer :: PlayingState){
        //     bulletsound->setPos(0);
        // }
        // else  bulletsound -> play();
    }



}
void Player::decrease_health()
{
    health->decrease();
}
void Player::increase_score()
{
    score->increase();
}
// CreateEnemy function used to create the eneimes
void Player::createEnemy()
{ Enemy* enemy = new Enemy(this);
    scene->addItem(enemy);

}

//  function used to handle the collision of the player with the enemies  and display the game over message
