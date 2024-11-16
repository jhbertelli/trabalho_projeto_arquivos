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

ArvoreB *criaArvoreB(int);
NoB *criaNoB(ArvoreB *);
void percorreArvoreB(NoB *);
int pesquisaBinariaB(NoB *no, int chave, int* pQtdOperacoes);
int localizaChave(ArvoreB *arvore, int chave, int* pQtdOperacoes);
NoB *localizaNoB(ArvoreB *arvore, int chave, int* pQtdOperacoes);
void adicionaChaveNo(NoB *no, NoB *novo, int chave, int* pQtdOperacoes);
int transbordo(ArvoreB *arvore, NoB *no, int* pQtdOperacoes);
NoB *divideNo(ArvoreB *arvore, NoB *no, int* pQtdOperacoes);
void adicionaChaveRecursivo(ArvoreB *arvore, NoB *no, NoB *novo, int chave, int* pQtdOperacoes);
void adicionaChaveB(ArvoreB *arvore, int chave, int* pQtdOperacoes);
