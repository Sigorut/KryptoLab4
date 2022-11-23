#include "card.h"

Card::Card()
{
    num_deck.resize(52);
    gen_num_deck();
}

void Card::gen_num_deck()
{
    for(int i = 0, rand_num; i < num_deck.size(); i++){
        do{
            rand_num = QRandomGenerator::global()->bounded(100, 10000);
        }while(!check_rand_num(rand_num, i));
        num_deck[i] = rand_num;
        id_deck_map.insert(rand_num, deck[i]);
    }
}

bool Card::check_rand_num(int rand_num, int last_index)
{
    for(int i = 0; i < last_index - 1; i++){
        if(num_deck[i] == rand_num) return false;
    }
    return true;
}

void Card::shuffle()
{
    for(int i = 0; i < QRandomGenerator::global()->bounded(100, 500); i++){
        qSwap(num_deck[QRandomGenerator::global()->bounded(0, 52)], num_deck[QRandomGenerator::global()->bounded(0, 52)]);
    }
}

void Card::print_deck()
{
    qDebug() << id_deck_map;

}

void Card::print_num_deck()
{
    for(int i = 0; i < num_deck.size(); i++){
        qDebug() << num_deck[i];
    }
}

QVector<qint64> Card::get_num_deck()
{
    return num_deck;
}

void Card::set_num_deck(QVector<qint64> num_dec)
{
    this->num_deck = num_dec;
}

QString Card::get_card_name_on_hands(qint64 uncode_num_card)
{
    return id_deck_map.value(uncode_num_card);
}
