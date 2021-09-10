/**

PseudoCode here 

fun mergesort( array a0)
   if ( n == 1 ) return a  // if length of array is one then its already sorted 

   array One = a[0] ... a[n/2]
   array Two = a[n/2+1] ... a[n]

   One = mergesort( One )
   Two = mergesort( Two )

   return merge( One, Two )
end fun

fun merge( array a , array b )

   array c 
   while ( a and b have elements )
      if ( a[0] > b[0] )
         add b[0] to the end of c
         remove b[0] from b
      else
         add a[0] to the end of c
         remove a[0] from a
      end if
   end while
   
   while ( a has elements )
      add a[0] to the end of c
      remove a[0] from a
   end while
   
   while ( b has elements )
      add b[0] to the end of c
      remove b[0] from b
   end while
   
   return c
 
end fun

**/

#include <stdio.h>
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);

int main(){
    int a[30],n,i;
    printf("Enter no of elements:");
    scanf("%d",&n);
    printf("Enter array elements:");

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    printf("\nSorted array is :");

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    
    return 0;
}

void mergesort(int a[],int i,int j){

    int mid;
    if(i<j){
        mid=(i+j)/2;
        mergesort(a,i,mid);        //left recursion
        mergesort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }


}

void merge(int a[],int i1,int j1,int i2,int j2){
    int temp[50];    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;
    while(i<=j1 && j<=j2){    //while elements in both lists
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];
    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];
    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];

}