#include<stdio.h>
typedef struct hash{
    int key;
    int value;
    struct hash *next;
} hash;
void display(hash ar[],int n);
void search(hash ar[],int n);
void insert(hash ar[],int n);
void main(){
    int i,z,n,j;
    struct hash hash_func[20];
    printf("enter th size of hash fuction");
    scanf("%d",&n);
    j=0;
    while(j<n){
        hash_func[j].next=NULL;
        j++;
    }
    j=0;
    while(j<n){
        hash_func[j].value=-1;
        j++;
    }
    
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
        printf("%d\t%d\t",ar[i].key,ar[i].value);
        hash *ptr;
        ptr=ar[i].next;
        while(ptr!=NULL){
            printf("%d",ptr->value);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
void search(hash ar[],int n){
    int i ,x;
    hash *pt;
    printf("\nenter the value for search");
    scanf("%d",&x);
        pt=ar[x%n].next;
    
        if(ar[x%n].value==x){
            printf("\nelement is present at: %d",x%n);
        }
        else if(x==pt->value){
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
    if(ar[k%n].value==-1){
    ar[k%n].value=k;
    }
    else{
        hash *pair;
        pair=(hash*)malloc(sizeof(hash));
        pair->value=k;
        pair->next=NULL;
        ar[k%n].next=pair;
    }
}