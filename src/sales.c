#include <stdlib.h>
#include "sales.h"

/**
 * Estrutura usada para representar vendas;
 */
struct sale {
	PRODUCT prod; /** Produto comprado */
	CLIENT client; /** Cliente que efetuou a compra */
	double price; /** Preço da compra */
	unsigned int quantity; /** Quantidade comprada */
	unsigned int month; /** Mês em que a compra foi efetuada */
	unsigned int branch; /** Filial onde foi efetuada a venda */
};

/**
 * Verifica se uma SALE é válida.
 * @param sale SALE a verificar
 * @param prodCat Catálogo de Produtos
 * @param clientCat Cátalogo de Clientes
 * @return true se for válida, false caso contrário
 */
bool isSale(SALE sale, PRODUCTCAT prodCat, CLIENTCAT clientCat) {
	return (lookUpProduct(prodCat, sale->prod) && 
		 lookUpClient(clientCat, sale->client));
}

/**
 * Cria um SALE novo.
 * @param p Produto
 * @param c Client
 * @param price Preço da venda
 * @param quant Quantidade comprada
 * @param month Mês da compra
 * @param branch Filial onde foi efetuada a compra
 * @return nova SALE
 */
SALE toSale(PRODUCT p, CLIENT c, double price, int quant, int month, int branch) {

	SALE s = malloc (sizeof(*s));

	s->prod = cloneProduct(p);
	s->client = cloneClient(c);
	s->price = price;
	s->quantity = quant;
	s->month = month;
	s->branch = branch;
	
	return s;
}