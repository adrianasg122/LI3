#include <stdlib.h>
#include <string.h>
#include "clients.h"

#define MAX_BUFF 10
#define CLIENT_LENGTH 6

struct client{
	char *str;
};

/** Inicia o Catálogo de Clientes
 * @param void
 * @return Catálogo de Clientes novo
 */
CLIENTCAT initClientCat() {
    return initCatalog();
}

/** Insere cliente no catálogo de Clientes.
 * @param CLIENTCAT Catálogo de Clientes
 * @param CLIENT Cliente a inserir
 * @return Catálogo de Clientes com o novo cliente inserido.
 */
CLIENTCAT insertClient(CLIENTCAT catalog, CLIENT client) {
	return insertCatalog(catalog, client->str);
}

/** Verifica se um dado cliente existe num dado catálogo
 * @param CLIENTCATALOG Catálogo de Clientes
 * @param CLIENT Cliente a procurar
 * @return 1 se encontrou, 0 caso contrário
 */
bool lookUpClient(CLIENTCAT catalog, CLIENT client) {
	return lookUpCatalog(catalog, client->str);
}

/** Liberta o espaço ocupado pelo Catálogo de Clientes
 * @param CLIENTCAT Catálogo de Clientes
 * @return void
 */
void freeClientCat(CLIENTCAT catalog) {
	freeCatalog(catalog);
}

/** Converte String para CLIENT
 *  @param char* String a converter
 *  @return CLIENT
 */
CLIENT toClient(char *str) {
	CLIENT r = malloc(sizeof (*r));

/*	if (!isClient(str))
		return NULL;
*/
	r->str = malloc (MAX_BUFF);
	strncpy(r->str, str, MAX_BUFF);

	return r;
}

bool isClient(char *str) {
	int i;
	bool client = 1;

	for (i = 0; client && i < CLIENT_LENGTH; i++){
		switch (i){
			case 0: client = (str[i] >= 'A' && str[i] <= 'Z');
					break;
			case 1: client = (str[i] >= '1' && str[i] <= '5');
					break;
			case 2:
			case 3:
			case 4: client = (str[1] == '5' && str[i] == '0') ||
							   (str[1] != '5' && str[i] >= '0' && str[i] <= '9');
					break;
		}
	}

	return client;
}
