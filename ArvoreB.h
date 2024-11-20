typedef struct noB
{
    int total;
    int *chaves;
    struct noB **filhos;
    struct noB *pai;
} NoB;

typedef struct
{
    NoB *raiz;
    int ordem;
} ArvoreB;

extern ArvoreB *criaArvoreB(int);
extern NoB *criaNoB(ArvoreB *);
extern void percorreArvoreB(NoB *);
extern int pesquisaBinariaB(NoB *no, int chave, int* pQtdOperacoes);
extern int localizaChave(ArvoreB *arvore, int chave, int* pQtdOperacoes);
extern NoB *localizaNoB(ArvoreB *arvore, int chave, int* pQtdOperacoes);
extern void adicionaChaveNo(NoB *no, NoB *novo, int chave, int* pQtdOperacoes);
extern int transbordo(ArvoreB *arvore, NoB *no, int* pQtdOperacoes);
extern NoB *divideNo(ArvoreB *arvore, NoB *no, int* pQtdOperacoes);
extern void adicionaChaveRecursivo(ArvoreB *arvore, NoB *no, NoB *novo, int chave, int* pQtdOperacoes);
extern void adicionaChaveB(ArvoreB *arvore, int chave, int* pQtdOperacoes);
extern void removerChaveB(ArvoreB* arvore, int chave, int* pQtdOperacoes);