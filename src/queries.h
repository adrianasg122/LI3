#ifndef __QUERIES_H__
#define __QUERIES_H__

#include "interpreter.h"
#include "fatglobal.h"
#include "branchsales.h"

typedef struct page *PAGE;

void query2(PRODUCTCAT pcat);
void query3(FATGLOBAL fat, PRODUCTCAT pcat);
void query4(FATGLOBAL fat);
void query5(BRANCHSALES* bs, CLIENTCAT ccat);
void query6(FATGLOBAL fat);
void query7(BRANCHSALES* bs); 
void query8(BRANCHSALES* bs, PRODUCTCAT pcat);
void query9(BRANCHSALES* bs, CLIENTCAT ccat); 
void query10(BRANCHSALES* bs);
void query11 (BRANCHSALES* bs, CLIENTCAT ccat); 
void query12 (BRANCHSALES* bs, FATGLOBAL fat);

#endif
