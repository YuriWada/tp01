#include "../include/memlog.hpp"
#include <cassert>
#include <cerrno>
#include <cstring>

// Variável global
MemLog ml = {nullptr, CLOCK_REALTIME, {}, 0, 0, MLINATIVO};

// Função para calcular a diferença entre tempos
void clkDifMemLog(struct timespec t1, struct timespec t2, struct timespec* res) {
    if (t2.tv_nsec < t1.tv_nsec) {
        res->tv_nsec = 1000000000 + t2.tv_nsec - t1.tv_nsec;
        res->tv_sec = t2.tv_sec - t1.tv_sec - 1;
    } else {
        res->tv_nsec = t2.tv_nsec - t1.tv_nsec;
        res->tv_sec = t2.tv_sec - t1.tv_sec;
    }
}

int iniciaMemLog(const char* nome) {
    ml.log = fopen(nome, "w");
    if (!ml.log) {
        fprintf(stderr, "Erro ao abrir o arquivo %s: %s\n", nome, strerror(errno));
        return -1;
    }
    ml.clk_id = CLOCK_REALTIME;
    ml.count = 0;
    ml.fase = 0;
    ml.ativo = MLINATIVO;

    if (clock_gettime(ml.clk_id, &ml.inittime) != 0) {
        fprintf(stderr, "Erro ao capturar o tempo inicial.\n");
        fclose(ml.log);
        return -1;
    }

    return 0;
}

int ativaMemLog() {
    ml.ativo = MLATIVO;
    return MLATIVO;
}

int desativaMemLog() {
    ml.ativo = MLINATIVO;
    return MLINATIVO;
}

int defineFaseMemLog(int f) {
    ml.fase = f;
    return f;
}

int leMemLog(long pos, long tam, int id) {
    if (ml.ativo == MLINATIVO) return 0;

    struct timespec tp, tdif;
    if (clock_gettime(ml.clk_id, &tp) != 0) return -1;

    clkDifMemLog(ml.inittime, tp, &tdif);
    ml.count++;

    int retprint = fprintf(ml.log, "L %d %ld %d %ld.%.9ld %ld %ld\n",
                           ml.fase, ml.count, id, tdif.tv_sec, tdif.tv_nsec, pos, tam);
    assert(retprint >= 0);
    return 0;
}

int escreveMemLog(long pos, long tam, int id) {
    if (ml.ativo == MLINATIVO) return 0;

    struct timespec tp, tdif;
    if (clock_gettime(ml.clk_id, &tp) != 0) return -1;

    clkDifMemLog(ml.inittime, tp, &tdif);
    ml.count++;

    int retprint = fprintf(ml.log, "E %d %ld %d %ld.%.9ld %ld %ld\n",
                           ml.fase, ml.count, id, tdif.tv_sec, tdif.tv_nsec, pos, tam);
    assert(retprint >= 0);
    return 0;
}

int finalizaMemLog() {
    struct timespec tp, tdif;
    if (clock_gettime(ml.clk_id, &tp) != 0) return -1;

    clkDifMemLog(ml.inittime, tp, &tdif);
    ml.count++;

    int retprint = fprintf(ml.log, "F %ld %ld.%.9ld %ld.%.9ld\n", ml.count,
                           tp.tv_sec, tp.tv_nsec, tdif.tv_sec, tdif.tv_nsec);
    assert(retprint >= 0);

    if (fclose(ml.log) != 0) {
        fprintf(stderr, "Erro ao fechar o arquivo de log.\n");
        return -1;
    }

    ml.ativo = MLINATIVO;
    return 0;
}
