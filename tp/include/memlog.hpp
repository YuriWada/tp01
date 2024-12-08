#ifndef MEMLOG_H
#define MEMLOG_H

#include <cstdio>
#include <ctime>

// Estrutura de dados para o memlog
struct MemLog {
    FILE* log;
    clockid_t clk_id;
    struct timespec inittime;
    long count;
    int fase;
    int ativo;
};

// Variável global para o memlog
extern MemLog ml;

// Constantes definindo os estados de registro
#define MLATIVO 1
#define MLINATIVO 0

// Macros para registro de leitura e escrita
#define LEMEMLOG(pos, tam, id) \
    ((void)((ml.ativo == MLATIVO) ? leMemLog(pos, tam, id) : 0))

#define ESCREVEMEMLOG(pos, tam, id) \
    ((void)((ml.ativo == MLATIVO) ? escreveMemLog(pos, tam, id) : 0))

// Funções da biblioteca
int iniciaMemLog(const char* nome);
int ativaMemLog();
int desativaMemLog();
int defineFaseMemLog(int f);
int leMemLog(long pos, long tam, int id);
int escreveMemLog(long pos, long tam, int id);
int finalizaMemLog();

#endif // MEMLOG_H
