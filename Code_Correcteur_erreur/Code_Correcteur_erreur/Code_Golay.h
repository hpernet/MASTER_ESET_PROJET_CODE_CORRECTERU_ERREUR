#pragma once
#include "Code_Correcteur_erreur.h"

// functions prototypes
void initialization(void);

void encode(int* i_msg, int* o_encoded_msg);

void add_error(int* io_msg, int* i_error);

void decode(int* msg_recu, int* msg_decode);

