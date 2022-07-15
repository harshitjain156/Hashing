#include<stdio.h>
typedef struct hash{
    int key;
    int value;
} hash;
void display(hash ar[],int n);
void search(hash ar[],int n);
void insert(hash ar[],int n);
void main(){
    int i,z,n;
    struct hash hash_func[20];
    printf("enter th size of hash fuction");
    scanf("%d",&n);
    printf("Enter the data in hash Table");
    for(i=0;i<n;i++){
        scanf("%d",&z);
        hash_func[z%n].key=z%n;
        hash_func[z%n].value=z;
    }
    display(hash_func,n);
    search(hash_func,n);
    insert(hash_func,n);
    display(hash_func,n);
    
}
void display(hash ar[],int n){
    int i;
    printf("data\tkey\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\n",ar[i].value,ar[i].key);
    }
}
void search(hash ar[],int n){
    int i ,x;
    printf("\nenter the value for search");
    scanf("%d",&x);
    
        if(ar[x%n].value==x){
            printf("\nelement is present at: %d",x%n);
        }
        else{
            printf("Element not present in tha Table");
        }
    
}
void insert(hash ar[],int n){
    int k;
    printf("\nEnter the value to insert");
    scanf("%d",&k);
    ar[k%n].value=k;
}