#include "gaymer.h"

GayMer::GayMer()
{

}

void GayMer::gen_cd(qint64 p)
{
    qint64 gcd_mass[3];
    do{
        c = QRandomGenerator::global()->bounded(1, p);
    }while(GCD_two(c, p-1) != 1);
    gcd(p-1,c,gcd_mass);
    d = gcd_mass[2];
    this->p = p;
}

qint64 GayMer::get_p(qint64 p)
{
    return p;
}

qint64 GayMer::get_c()
{
    return c;
}

qint64 GayMer::get_d()
{
    return d;
}

QVector<qint64> GayMer::get_cards_on_hands()
{
    return cards_on_hands;
}

void GayMer::code_card(qint64 *card)
{
    *card = exp_mod(*card, c, p);
}

void GayMer::uncode_card(qint64 *card)
{
    *card = exp_mod(*card, d, p);
}

void GayMer::set_card_on_hands(qint64 card)
{
    cards_on_hands.push_back(card);
}

void GayMer::set_uncode_cards_on_hands(QVector<qint64> uncode_cards)
{
    cards_on_hands = uncode_cards;
}
