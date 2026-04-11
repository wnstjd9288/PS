#include <stdio.h>
class Player
{
    int maxHp = 100;
    int maxMp = 100;
    int hp = 100;
    int mp = 100;

public:
    void Attack()
    {
        printf("Attack!");
    }
    void Hit(int damage)
    {
        printf("Player Hit!");
        hp -= damage;
        if (hp <= 0)
            die();
    }
    void die()
    {
        printf("Player Die!");
    }
};
