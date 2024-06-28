#include "pqueue.h"
#include "offer.h"

#include <stddef.h>
#include <string.h>
#include <stdio.h>

#define SWAP(x, y) { Offer t = x; x = y; y = t; }

static void __heapfy_up(PQueue *q, int index) {
  int parent = (index - 1)/2;

  while (index > 0 && q->offers[parent].price < q->offers[index].price) {
    SWAP(q->offers[parent], q->offers[index]);

    index = parent;
    parent = (index - 1)/2;
  }
}

static void __heapfy_down(PQueue *q, int index) {
  int left = 2*index + 1;
  int right = 2*index + 2;
  int largest = index;

  if (left < q->size && q->offers[left].price > q->offers[largest].price) {
    largest = left;
  }

  if (right < q->size && q->offers[right].price > q->offers[largest].price) {
    largest = right;
  }

  if (largest != index) {
    SWAP(q->offers[index], q->offers[largest]);
    __heapfy_down(q, largest);
  }
}

static Offer __extract_max(PQueue *q) {
  if (q->size == 0) {
    fprintf(stderr, "Queue is empty\n");
    Offer o;
    o.price = 0;
    return o;
  }

  Offer max = {
    .price = q->offers[0].price,
    .buyer_name = {0}
  };

  strncpy(max.buyer_name, q->offers[0].buyer_name, NAME_LENGTH);

  q->offers[0] = q->offers[q->size - 1];
  q->size--;

  if (q->size > 0) {
    __heapfy_down(q, 0);
  }

  return max;
}

static void __queue_insert(PQueue *p, Offer o) {
  if (p->size == p->capacity) {
    fprintf(stderr, "Queue is already full\n");
    return;
  }

  p->offers[p->size] = o;
  p->size++;

  __heapfy_up(p, p->size - 1);
}

// ------------------------------------------------------

void pqueue_init(PQueue *p) {
  p->capacity = MAX_OFFERS;
  p->size = 0;
}

void add_offer(PQueue *p, char buyer[NAME_LENGTH], unsigned int price) {
  if (price < 0) {
    fprintf(stderr, "Price must be greater than 0\n");
    return;
  }

  Offer o;
  o.price = price;
  strncpy(o.buyer_name, buyer, NAME_LENGTH);

  __queue_insert(p, o);
}

Offer get_best_offer(PQueue *p) {
  return __extract_max(p);
}