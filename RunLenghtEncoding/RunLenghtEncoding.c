#include <stdio.h>
#define SIZE 100
#define SIZE2 10000

int main()
{
	int N,M,row,column,num,first_qua,current_element,previous_element,k=0,counter=1,new_qua=0,element=0;
	scanf("%d %d",&N,&M);		// matris boyutu
	first_qua = N*M;
	int arr[SIZE][SIZE];	
	int new_array[SIZE2];			// compression i�lemini kolayla�t�rmak i�in 
	int new_matrix[SIZE][SIZE]
	
	printf("Enter your elements:\n");
	for(row=0; row<N; row++){						// elemanlar� al�yoruz
		for (column=0; column<M; column++){
			scanf("%d",&num);
			arr[row][column] = num;
		}
	}
	
	// EK **************************************************************
	printf("\n---Before Compression---\n");
	for(row=0; row<N; row++){						// elemanlar� bas�yoruz
		for (column=0; column<M; column++){
			printf("%d ",arr[row][column]);
		}
		printf("\n");
	}
	////////////////////////////////////////////////////////////////////
	column=1;	// Column 1 'den ba�lar ��nk� previous'a sahibiz, elimizdeki mevcut alana ula�mal�y�z.
	for(row=0; row<N; row++){
		while(column<M){     // Initializing en altta yap�l�yor
			if( column == 0){			// Current-> Column 0 durumu i�in matriste atlama ger�ekle�ir ve sistemi bozar(previous'un row'u bir �nceki kalmal�), bunu engellemek i�in koyulan if			
				previous_element = arr[row-1][M-1];		//Kuyruk olarak takip eden kontrol elementi
				current_element = arr[row][column];		//Bulundu�umuz konum
			}
			else{
				previous_element = arr[row][column-1];
				current_element = arr[row][column];
			}	
			
			if ( current_element == previous_element )	// Ard� ard�na gelen ayn� elemanlar� say�yoruz
				counter++;
				
			else {									// Ayn� olmamas� halinde geride 
				new_array[k]=counter;
				new_array[k+1]=previous_element;
				counter = 1;
				k += 2;
				new_qua = k;
			}
			
			if ( first_qua == (row+1)*(column+1) ) {     //  Matrisin son eleman�na geldi�inde
				new_array[k]=counter;			   //  Current'�n tuttu�u eleman�n ��pe at�lmamas� i�in
				new_array[k+1]=current_element;	   //	bu if'i a��yoruz
				k += 2;
				new_qua = k;
			}
		column++;
		}
			column=0;	//�lk ba�lang�� harici 0. s�tun s�k�nt� ��karm�yor. Bu y�zden hata yapmamak i�in 0'a sarmal�y�z, her sat�r de�i�ikli�inde.		
	}
	
	printf("\n-After compression- New array-\n");
	for (element = 0; element < new_qua; element++){
		printf("%d ",new_array[element]);
	}
	float res;
	res = new_qua / (float)first_qua;			
	printf("\nCompression Ratio : %.2f\n", (1-res) );
	
	int r=0;
	current_element = new_array[r+1];
	// EK DECODING**************************************************************
	printf("\nA new matrix after Decompression\n");
	for(row=0; row<N; row++){						// Arraye decode uygulayarak yeni matris �retiliyor.
		for (column=0; column<M; column++){
			if( r == 0 &&  new_array[r] > 0 ){
				new_array[r]--;
				new_matrix[row][column] = current_element;
			}
			else if( new_array[r] > 1){
				new_array[r]--;
				new_matrix[row][column] = current_element;
			}
			else{
				r+=2;
				current_element = new_array[r+1];
				new_matrix[row][column] = current_element;
			}
		
			printf("%d ",new_matrix[row][column]);
		}
		printf("\n");
	}
	////////////////////////////////////////////////////////////////////

	return 0;
}
