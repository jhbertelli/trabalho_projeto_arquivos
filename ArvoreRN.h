enum coloracao
{
    Vermelho,
    Preto
};

typedef enum coloracao Cor;

typedef struct noRN
{
    struct noRN *pai;
    struct noRN *esquerda;
    struct noRN *direita;
    Cor cor;
    int valor;
} NoRN;

typedef struct
{
    struct noRN *raiz;
    struct noRN *nulo;
} ArvoreRN;

extern NoRN *criarNoRN(ArvoreRN *, NoRN *, int);
extern void balancearRN(ArvoreRN *, NoRN *);
extern void rotacionarEsquerda(ArvoreRN *, NoRN *);
extern void rotacionarDireita(ArvoreRN *, NoRN *);

extern ArvoreRN *criarRN();
extern int vaziaRN(ArvoreRN *);
extern NoRN *adicionarRN(ArvoreRN *, int);
extern NoRN *localizarRN(ArvoreRN *arvore, int valor);

extern void percorrerProfundidadePreOrder(ArvoreRN *arvore, NoRN *no, void (*callback)(int));
extern void percorrerProfundidadePosOrder(ArvoreRN *arvore, NoRN *no, void(callback)(int));
extern void percorrerProfundidadeInOrder(ArvoreRN *arvore, NoRN *no, void (*callback)(int));
