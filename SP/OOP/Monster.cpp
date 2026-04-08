#include <stdio.h>

class Monster
{
protected:
    int maxHp;
    int maxMp;
    int hp;
    int mp;

public:
    Monster(int maxHp = 100, int maxMp = 100) : maxHp(maxHp), maxMp(maxMp), hp(maxHp), mp(maxMp) {}

    // 순수 가상 함수: 자식 클래스에서 반드시 구현해야 함
    virtual void Attack() = 0;

    void Hit(int damage)
    {
        printf("Monster Hit! Damage: %d\n", damage);
        hp -= damage;
        if (hp <= 0)
            Die();
    }

    void Die()
    {
        printf("Monster Die!\n");
    }

    virtual ~Monster() {} // 가상 소멸자
};
