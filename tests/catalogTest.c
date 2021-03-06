#include <stdio.h>

#include "catalogTest.h"
#include "../src/catalog.h"

#define INSERT_CATALOG_NUM 3
#define UPDATE_CATALOG_NUM 4

static int test_insertCatalog();
static int test_replaceCatalog(); 

int test_Cat() {

	int res, passed_tests = 0;

	res = test_insertCatalog();
	passed_tests += res;
	printf("insertCatalog: %d/%d\n", res, INSERT_CATALOG_NUM );

	res = test_replaceCatalog();
	passed_tests += res;
	printf("replaceCatalog: %d/%d\n", res, UPDATE_CATALOG_NUM); 

	return passed_tests;
}

static int test_insertCatalog() {

	int testes_passou = 0;
	CATALOG c = initCatalog(10, NULL, NULL, NULL, NULL, NULL);

	c = insertCatalog(c, 0, "Cientista", NULL);
	c = insertCatalog(c, 0, "Escolhido", NULL);
	c = insertCatalog(c, 2, "Candance", NULL);

	c = insertCatalog(c, 0, "Carlos", NULL);

	if (countCatElems(c, 0) == 3) { printf("Passou 1\n"); testes_passou++; }
	if (countCatElems(c, 2) == 1) { printf("Passou 2\n"); testes_passou++; }
	if (countCatElems(c, 8) == 0) { printf("Passou 3\n"); testes_passou++; }

	freeCatalog(c);

	return testes_passou;
}

static int test_replaceCatalog() {
	
	int testes_passou = 0;
	CATALOG c = initCatalog(10,NULL,  NULL, NULL, NULL, NULL);
	char *cont1 = "Olá", *cont2 = "Disquete", *cont3 = "Maria Amélia";

	c = insertCatalog(c, 0, "Cientista", NULL);
	c = insertCatalog(c, 0, "Escolhido", NULL);
	c = insertCatalog(c, 2, "Candance", NULL);
	c = insertCatalog(c, 0, "Carlos", cont1);

	replaceCatalog(c, 0, "Cientista", cont1);	
	replaceCatalog(c, 0, "Escolhido", cont2);	
	replaceCatalog(c, 3, "Candance", cont3);
	replaceCatalog(c, 0, "Cientista", cont2);	
	
	if (getCatContent(c, 0, "Cientista") == cont2) { printf("Passou 1\n"); testes_passou++; }
	if (getCatContent(c, 2, "Candance")  == NULL ) { printf("Passou 2\n"); testes_passou++; }	
	if (getCatContent(c, 3, "Candance")  == NULL ) { printf("Passou 3\n"); testes_passou++; }
	if (getCatContent(c, 0, "Carlos") == cont1) { printf("Passou 4\n"); testes_passou++; }

	return testes_passou;
}
