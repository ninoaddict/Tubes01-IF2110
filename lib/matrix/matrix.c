#include "matrix.h"

void CreateMatrix(Matrix *mat)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j += 2)
        {
            mat->Buffer[i][j] = 'R';
        }
        for (int j = 1; j < 10; j += 2)
        {
            mat->Buffer[i][j] = '*';
        }
    }
}

void displayMatrix(Matrix mat){
    for (int i=0; i<ROW_EFF(mat); i++){
        for (int j=0; j<COL_EFF(mat); j++){
            if (j==COL_EFF(mat)-1){
                printf("%d\n",ELMT(mat,i,j));
            }
            else {
                printf("%d ",ELMT(mat,i,j)); 
            }
        }
    }
}