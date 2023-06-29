#define _BD_H_

#include <stdio.h>
#include <stdlib.h>
#include "/usr/include/postgresql/libpq-fe.h"
#include <string.h>

void criar_tabela(PGconn *conn);
void inserir_valores(PGconn *conn);
void exibe_tabelas(PGconn *conn);
void remove_dados_tabela(PGconn *conn);
void exibe_dados_tabelas(PGconn *conn);