#include <stdio.h>
#include <math.h>
// Yaz�lmas� beklenen algoritmik program.
int main()
{
    //��renci say�s� al�n�r.
    int studentNumber;
    scanf("%d",&studentNumber);
    int i,sayi,arr[studentNumber],res[studentNumber];

    //��rencilerin notlar� girilir.
    i=0;
    while (i < studentNumber)
    {
        scanf("%d",&sayi);
        arr[i]= sayi;
    i++;
    }

    //notlar kar��la�t�r�l�r ve yuvarlamalar yap�l�r.
    i=0;
    while (i < studentNumber)
    {
        if (arr[i] % 5 > 2 && !(arr[i] < 38)){
            res[i]= arr[i] + (5 - arr[i] % 5);
        }
        else{
            res[i]= arr[i];
        }
        printf("%d\n",res[i]);
    i++;

    }
}

