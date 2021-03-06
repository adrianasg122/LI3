#ifndef __AVL__
#define __AVL__

#include "generic.h"
#include "set.h"

typedef struct avl *AVL;
typedef struct element *ELEMENT;

/**
 * Inicia uma AVL com as funções auxiliares dadas.
 * @param equals Verifica se dois conteúdos são iguais
 * @param clone Função capaz de clonar o conteúdo de um element da árvore
 * @param free Responsável por libertar toda a memória ocupada pelo conteúdo de um elemento
 */
AVL initAVL (condition_t equals, clone_t clone, free_t free);

/**
 * Altera as operações com que a árvore foi inicializada.
 * @param tree Árvore cujas operações serão mudadas
 * @param equals Verifica se dois conteúdos são iguais
 * @param clone Função capaz de clonar o conteúdo de uma árvore
 * @param free Responsável por libertar toda a memória ocupada pelo conteúdo
 */
AVL changeOps (AVL tree, condition_t equals, clone_t clone, free_t free);

/**
 * Insere na árvore um nodo com a hash e o conteúdo dados. Se o nodo já existe, nada faz.
 * @param tree Árvore onde vai ser inserido o nodo
 * @param hash String que identifica o nodo
 * @param content Conteúdo a ser colocado no nodo
 * @result Árvore onde o nodo foi inserido
 */
AVL insertAVL (AVL tree, char *hash, void *content);

/**
 * Clona a árvore dada, incluindo as suas operações. Se a função auxiliar clone existir,
 * o conteúdo dos elementos é também clonado.
 */
AVL cloneAVL (AVL tree);

/**
 * Cria um novo elemento vazio. Um elemento pode ser associado um nodo para atualizar
 * rapidamente o seu conteúdo.
 */
ELEMENT newElement();

/** 
 * Devolve o conteúdo do nodo com a hash dada.
 * @param tree Árvore
 * @param hash Identificador do elemento pretendido
 * @param elem Elemento (opcional) que será associado a um nodo para que o seu conteúdo
 * ser rapidamente atualizado. 
 * @return Conteúdo do nodo
 */
void* getAVLcontent (AVL tree, char *hash, ELEMENT elem);

/**
 * Atualiza o conteúdo do nodo associado ao elemento dado.
 * @param elem Elemento associado ao nodo a ser atualizado
 * @param content Conteúdo que será inserido no nodo.
 */
void updateElement(ELEMENT elem, void* content);

/**
 * Liberta a memória associada a um elemento.
 */
void freeElement(ELEMENT element);

/**
 * Verifica se existe um nodo com o identificador hash.
 * @param tree Árvore a ser verificada
 * @param hash Identificador do elemento procurado
 */
bool lookUpAVL (AVL tree, char *hash);

/**
 * Verifica se a AVL está vazia ou não.
 * @return true caso seja vazia, false caso contráio
 */
bool isEmptyAVL (AVL tree);

/**
 * Verifica se duas árvores são iguais. Duas árvores são iguais se tiverem as mesmas
 * operações e os mesmos nodos. Se existir uma operação equals no set de operações
 * da árvore, é também verificado se o conteúdo de cada nodo de cada árvore é igual.
 */
bool equalsAVL (AVL tree, AVL b);

/*
 * Determina o número de nodos existentes na árvore.
 */
int countNodes (AVL tree);

/**
 * Liberta o espaço ocupado pelos nodos da árvore. Se existir uma função free no conjunto de
 * operações da árvore, o conteúdo de cada nodo é também libertado.
 */
void freeAVL (AVL n);

/**
 * Adiciona os elementos de uma AVL ao set dado. O conteúdo dos nodos apenas é copiado
 * caso exista uma função clone no set de funções da árvore.
 * @param s Set onde serão adicionados os elementos
 * @param tree Árvore cujos elementos serão adicionados
 * @return Set s, agora com os elementos adicionados
 */
SET addAVLtoSet (SET s, AVL tree);

/**
 * Adiciona ao conjunto de dados indicado uma cópia de todos os elementos da árvore
 * para a qual a condição dada é verdadeira.
 * @param tree Árvore cujos nodos serão filtrados
 * @param s Conjunto de dados onde serão adicionados os novos elementos
 * @param condition Condição a que cada nodo será submetido
 * @param arg Argumento opcional para a condição
 * @return Set s, agora com os elementos adicionados
 */
SET filterAVL (AVL tree, SET s, condition_t condition, void* arg);

/**
 * Transforma o conteúdo de cada nodo, usando a função dumper dada. O resultado do dumper
 * é então adicionado, juntamente com a hash do elemento, ao set dado.
 * 
 * @param tree Árvore com a informação a ser extraida
 * @param set Local onde a informação será guardada
 * @param dumper Função responsável por extrair o conteúdo dos nodos. O primeiro argumento
 * corresponde à estrutura de dados onde vai ser guardada a informação (data). O segundo
 * argumento corresponde à estrutura de dados presente no conteúdo de cada nodo
 * @return Estrutura de dados com toda a informação
 */
SET dumpAVL(AVL tree, SET set, void* (*dumper)(void*));

#endif
