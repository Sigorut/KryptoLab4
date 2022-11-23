#include <QCoreApplication>
#include "card.h"
#include "krypto.h"
#include "gaymer.h"
void generation_cd_for_players(QVector<GayMer> &players, qint64 p);
void players_code_deck(QVector<GayMer> players, Card &deck);
void get_cards_to_players(QVector<GayMer> &players, Card deck);
void uncode_card_on_hands(QVector<GayMer> &players);
void print_card_all_players(QVector<GayMer> players, Card deck);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qint64 p = gen_prime_num(10000, 1000000);
    QVector<GayMer> players(7);
    Card deck;
    generation_cd_for_players(players, p);
    deck.print_num_deck();
    players_code_deck(players, deck);
    deck.print_num_deck();
    get_cards_to_players(players, deck);
    uncode_card_on_hands(players);
    print_card_all_players(players, deck);

    return a.exec();
}

void generation_cd_for_players(QVector<GayMer> &players, qint64 p)
{
    for(int i = 0; i < players.size(); i++){
        players[i].gen_cd(p);
    }
}

void players_code_deck(QVector<GayMer> players, Card &deck)
{
    QVector<qint64> num_deck = deck.get_num_deck();
    for(int i = 0; i < players.size(); i++){
        num_deck = deck.get_num_deck();
        for(int card = 0; card < num_deck.size(); card++){
            players[i].code_card(&num_deck[card]);
        }
        deck.set_num_deck(num_deck);
        deck.shuffle();
    }
    deck.set_num_deck(num_deck);

}

void get_cards_to_players(QVector<GayMer> &players, Card deck)
{
    QVector<qint64> num_deck = deck.get_num_deck();
    for(int i = 0, num_card_index = 0; i < players.size(); i++){
        for(int j = 0; j < 2; j++){
            players[i].set_card_on_hands(num_deck[num_card_index]);
            num_card_index++;
        }
        qDebug() << "player #" << i+1 << " " <<players[i].get_cards_on_hands();
    }
}

void uncode_card_on_hands(QVector<GayMer> &players)
{
    QVector<qint64> cards_on_hands;
    for(int i = 0; i < players.size(); i++){
        cards_on_hands = players[i].get_cards_on_hands();
        for(int j = 0; j < players.size(); j++){
            if(i != j){
                for(int k = 0; k < cards_on_hands.size(); k++){
                    players[j].uncode_card(&cards_on_hands[k]);
                }
            }
        }
        for(int k = 0; k < cards_on_hands.size(); k++){
            players[i].uncode_card(&cards_on_hands[k]);
        }
        players[i].set_uncode_cards_on_hands(cards_on_hands);
    }
}

void print_card_all_players(QVector<GayMer> players, Card deck)
{
    QVector<qint64> cards_on_hands;
    for(int i = 0; i < players.size(); i++){
        cards_on_hands = players[i].get_cards_on_hands();
        qDebug() << "player #"<< i + 1 << " have ";
        for(int j = 0; j < cards_on_hands.size(); j++){
            qDebug() << deck.get_card_name_on_hands(cards_on_hands[j]);
        }
    }
}
