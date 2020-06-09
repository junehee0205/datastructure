#include <iostream>

void my_sort(int a[], int num){
    int i,j,m,term;
    for(i=0; i<num; i++){
        m = i;
        for(j =i+1; j<num; j++){
            if(a[j]<a[m]){
                m = j;
            }   
        }
        term = a[i];
        a[i] = a[m];
        a[m] = term;
    }
}

int main( )
{
int  list[10] = { 23, 11, 15, 8, 17, 33, 7, 14, 19, 21 };
int  i ;
      my_sort(list, 10);   // 배열 list의 원소 10개를 sort하는 함수
      for (i = 0; i< 10; i++)
              std::cout << list[i] << "\n";
      return 0;
}
