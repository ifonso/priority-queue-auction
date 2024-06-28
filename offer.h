#ifndef OFFER_H_
#define OFFER_H_

#define NAME_LENGTH 120

struct offer {
  char buyer_name[NAME_LENGTH];
  unsigned int price;
};

typedef struct offer Offer;

#endif // OFFER_H_
