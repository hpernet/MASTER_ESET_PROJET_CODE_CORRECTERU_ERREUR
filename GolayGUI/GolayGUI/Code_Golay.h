#pragma once

#define N_NB_BIT_MOT_CODE 19
#define K_NB_BIT_INFO     8

// functions prototypes
void initialization(void);

void encode(int* i_msg, int* o_encoded_msg);

void add_error(int* io_msg, int* i_error);

void decode(int* msg_recu, int* msg_decode);

