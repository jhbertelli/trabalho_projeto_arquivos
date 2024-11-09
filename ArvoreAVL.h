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

extern void balanceamentoAVL(ArvoreAVL *, NoAVL *, int* pQtdOperacoes);
extern int alturaAVL(NoAVL *);
extern int fb(NoAVL *, int* pQtdOperacoes);
extern NoAVL *rsd(ArvoreAVL *, NoAVL *, int* pQtdOperacoes);
extern NoAVL *rse(ArvoreAVL *, NoAVL *, int* pQtdOperacoes);
extern NoAVL *rdd(ArvoreAVL *, NoAVL *, int* pQtdOperacoes);
extern NoAVL *rde(ArvoreAVL *, NoAVL *, int* pQtdOperacoes);
extern void adicionarAVL(ArvoreAVL *arvore, int valor, int* pQtdOperacoes);
extern int vaziaAVL(ArvoreAVL *arvore);
extern ArvoreAVL *criarAVL();

extern void percorrerAVL(NoAVL *no, void (*callback)(int));