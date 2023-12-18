#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * add_array_to_deck - convert count array to linked list
 * @deck_array: pointer to the array of deck_node_t linked lists
 * @deck: pointer to deck linked list
 */
void add_array_to_deck(deck_node_t *deck_array[], deck_node_t **deck)
{
	int i;
	deck_node_t *node, *current, *next;

	for (i = 0; i < 14; i++)
	{
		node = deck_array[i];
		if (node == NULL)
			continue;
		if (*deck == NULL)
		{
			*deck = current = node;
			current->next = NULL;
			current->prev = NULL;
			deck_array[i] = NULL;
			continue;
		}
		else
		{
			current = *deck;
			while (current->next)
				current = current->next;
		}

		while (node)
		{
			next = node->next;
			current->next = node;
			node->prev = current;
			node->next = NULL;
			current = node;
			node = next;
		}
		deck_array[i] = NULL;
	}
}

/**
 * add_to_deck_array - perform counting sort
 * @deck_array: pointer to counting list
 * @pos: index in counting list
 * @card: card to add
 */
void add_to_deck_array(deck_node_t *deck_array[], int pos, card_t *card)
{
	deck_node_t *new, *node;

	new = malloc(sizeof(deck_node_t));
	if (new)
	{
		new->card = card;
		new->prev = NULL;
		new->next = NULL;
	}

	if (deck_array[pos] == NULL)
	{
		deck_array[pos] = new;
	}
	else
	{
		node = deck_array[pos];
		while (node->next)
			node = node->next;
		node->next = new;
		new->prev = node;
	}
}

/**
 * get_order_index - returns the ordered index of the card value
 * @value: value of the card
 * Return: 1 - 13 (Success) | -1 (Fail)
 */
int get_order_index(char *value)
{
	if (!value)
		return (-1);

	if (strcmp(value, "Ace") == 0)
		return (1);
	else if (strcmp(value, "Jack") == 0)
		return (11);
	else if (strcmp(value, "Queen") == 0)
		return (12);
	else if (strcmp(value, "King") == 0)
		return (13);
	else
		return (atoi(value));
}

/**
 * sort_deck - sort a deck of cards
 * @deck: pointer to a deck linked list
 *
 * Description:
 * Uses counting sort for kinds first, then performs counting sort on each
 * kind while rebuilding the deck linked list
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *deck_array[14] = {NULL};
	deck_node_t *kind_array[4] = {NULL};
	deck_node_t *node, *next;
	card_t *card;
	int idx, i;

	if (!deck || !*deck)
		return;
	node = *deck;
	/* SPADES - DIAMONDS */
	while (node)
	{
		card = (card_t *)node->card;
		idx = (int)card->kind;
		add_to_deck_array(kind_array, idx, card);
		node = node->next;
	}

	/* Ace - King for each kind */
	*deck = NULL;
	for (i = 0; i < 4; i++)
	{
		node = kind_array[i];
		if (node == NULL)
			continue;
		while (node)
		{
			next = node->next;
			card = (card_t *)node->card;
			idx = get_order_index((char *)card->value);
			add_to_deck_array(deck_array, idx, card);
			node = next;
		}
		add_array_to_deck(deck_array, deck);
	}
}
