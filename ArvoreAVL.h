typedef struct noAVL
{
    struct noAVL *pai;
    struct noAVL *esquerda;
    struct noAVL *direita;
    int valor;
    int altura;
} NoAVL;

typedef struct
{
    struct noAVL *raiz;
} ArvoreAVL;

extern void balanceamentoAVL(ArvoreAVL *, NoAVL *);
extern int alturaAVL(NoAVL *);
extern int fb(NoAVL *);
extern NoAVL *rsd(ArvoreAVL *, NoAVL *);
extern NoAVL *rse(ArvoreAVL *, NoAVL *);
extern NoAVL *rdd(ArvoreAVL *, NoAVL *);
extern NoAVL *rde(ArvoreAVL *, NoAVL *);
extern void adicionarAVL(ArvoreAVL *arvore, int valor);
extern int vaziaAVL(ArvoreAVL *arvore);
extern ArvoreAVL *criarAVL();

extern void percorrerAVL(NoAVL *no, void (*callback)(int));