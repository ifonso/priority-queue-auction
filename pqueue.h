#ifndef PQUEUE_H_
#define PQUEUE_H_

#define MAX_OFFERS 1000

#include <stddef.h>
#include "offer.h"

struct p_queue {
  Offer offers[MAX_OFFERS];
  size_t size;
  size_t capacity;
};

typedef struct p_queue PQueue;

void pqueue_init(PQueue *q);
void add_offer(PQueue *q, char buyer[NAME_LENGTH], unsigned int price);

Offer get_best_offer(PQueue *q);

#endif // PQUEUE_H_
