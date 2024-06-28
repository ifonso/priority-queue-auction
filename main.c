#include <stdio.h>
#include <string.h>
#include <stddef.h>

#include "pqueue.h"
#include "offer.h"

#define EVENT_LENGTH 7
#define SELL_LENGTH NAME_LENGTH + 10
#define MAX_NUMBER_OF_OFFERS 100

int main() {
  int N;
  scanf("%d", &N);

  PQueue offers;
  pqueue_init(&offers);

  char sells[SELL_LENGTH][MAX_NUMBER_OF_OFFERS] = {0};
  int sells_count = 0;

  for (int i = 0; i < N; i++) {
    char command[EVENT_LENGTH];
    scanf("%6s", command);

    if (strncmp(command, "OFERTA", EVENT_LENGTH) == 0) {
      char name[NAME_LENGTH];
      unsigned int price;

      scanf("%s %u", name, &price);
      add_offer(&offers, name, price);
    } else if (strncmp(command, "VENDA", EVENT_LENGTH) == 0) {
      Offer best_offer = get_best_offer(&offers);

      snprintf(sells[sells_count], SELL_LENGTH, "%s %u", best_offer.buyer_name, best_offer.price);
      sells_count++;
    } else {
      fprintf(stderr, "Invalid command\n");
    }
  }

  printf("\nVendas realizadas em ordem de execução:\n");

  for (int i = 0; i < sells_count; i++) {
    printf("%s\n", sells[i]);
  }
  
  return 0;
}