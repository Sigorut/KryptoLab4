#ifndef GAYMER_H
#define GAYMER_H
#include "card.h"
#include "krypto.h"
class GayMer
{
public:
    GayMer();
private:
    qint64 c;
    qint64 d;
    qint64 p;
    QVector<qint64> cards_on_hands;
public:
    void gen_cd(qint64 p);
    qint64 get_p(qint64 p);
    qint64 get_c();
    qint64 get_d();
    QVector<qint64> get_cards_on_hands();
    void code_card(qint64 *card);
    void uncode_card(qint64 *card);
    void set_card_on_hands(qint64 card);
    void set_uncode_cards_on_hands(QVector<qint64> uncode_cards);
};

#endif // GAYMER_H
