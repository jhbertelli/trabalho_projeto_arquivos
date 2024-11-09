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
int pesquisaBinariaB(NoB *, int);
int localizaChave(ArvoreB *, int);
NoB *localizaNoB(ArvoreB *, int);
void adicionaChaveNo(NoB *, NoB *, int);
int transbordo(ArvoreB *, NoB *);
NoB *divideNo(ArvoreB *, NoB *);
void adicionaChaveRecursivo(ArvoreB *, NoB *, NoB *, int);
void adicionaChaveB(ArvoreB *, int);
