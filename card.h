#ifndef CARD_H
#define CARD_H
#include<QStringList>
#include<QString>
#include<QRandomGenerator>
#include<QMultiMap>
#include<QVector>
#include<QDebug>
class Card
{
public:
    Card();
    void shuffle();
    void print_deck();
    void print_num_deck();
    QVector<qint64> get_num_deck();
    void set_num_deck(QVector<qint64> num_dec);
    QString get_card_name_on_hands(qint64 uncode_num_card);
private:
    QVector<qint64> num_deck;
    QMultiMap<int, QString> id_deck_map;
    QString deck[52] = {
        "clubs Ace", "clubs Two", "clubs Three", "clubs Four",
        "clubs Five", "clubs Six", "clubs Seven", "clubs Eight",
        "clubs Nine", "clubs Ten", "clubs Jack", "clubs Queen" , "clubs King",

        "diamonds Ace", "diamonds Two", "diamonds Three", "diamonds Four",
        "diamonds Five", "diamonds Six", "diamonds Seven", "diamonds Eight",
        "diamonds Nine", "diamonds Ten", "diamonds Jack", "diamonds Queen", "diamonds King",

        "hearts Ace", "hearts Two", "hearts Three", "hearts Four",
        "hearts Five", "hearts Six", "hearts Seven", "hearts Eight",
        "hearts Nine", "hearts Ten", "hearts Jack", "hearts Queen", "hearts King",

        "spades Ace", "spades Two", "spades Three", "spades Four",
        "spades Five", "spades Six", "spades Seven", "spades Eight",
        "spades Nine", "spades Ten", "spades Jack", "spades Queen", "spades King"
    };
private:
    void gen_num_deck();
    bool check_rand_num(int rand_num, int last_index);
};

#endif // CARD_H
