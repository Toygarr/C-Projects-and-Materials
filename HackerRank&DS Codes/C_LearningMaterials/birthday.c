#include <stdio.h>

int age_func(int age)
{
    //De�erlerimizi tan�mlad�k
    int i,sayi,j,max;
    scanf("%d",&age);
    int arr[age];
    int max_counter = 0;
    //Burada ama� diziye(pastaya) �ocu�un ya�� ka�sa o kadar mum eklemek
    i=0;
    while (i < age)
    {
        scanf("%d",&sayi);
        arr[i]=sayi;
        i++;
    }
    //Burada max de�eri ay�klamak i�in ayr� bir d�ng� a��yoruz
    max = arr[0];
    j=0;
    while (j < age)
    {
        if (arr[j] > max){
            max = arr[j];
        }
    j++;
    }
    //Ay�klad���m�z maximum b�y�kl�kteki mumlar� saya� yard�m�yla say�yoruz
    i=0;
    while (i < age)
    {
        if (max == arr[i]){
            max_counter = max_counter + 1;
        }
    i++;
    }
    printf("%d",max_counter);
    return max_counter;
}

int main()
{
    int max_counter;
    age_func(max_counter);

}

