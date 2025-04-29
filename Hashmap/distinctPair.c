#include "stdlib.h"
#include "stdio.h"

#define size 100000

typedef struct hashMap{
    int table[size];
    int negTable[size];
}hashMap;

void initHash(hashMap* map){
    for(int i=0; i<size; i++){
        map->table[i]=0;
        map->negTable[i]=0;
    }
}

int hash(int val){
    return val%size;
}

void insert(hashMap* map, int val){
    int index=hash(abs(val));
    if(val>=0)
    map->table[index]++;
    else
    map->negTable[index]++;
}

int disSum(hashMap* map){
    int sum=0;
    for(int i=0; i<size; i++){
        if(map->table[i]==1)
            sum+=i;
        if(map->negTable[i]==1)
            sum-=i;
    }
    return sum;
}

int sum(int arr[], int n){
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=arr[i];
    return sum;
}

void pair(hashMap* map, int arr[], int n, int sum){
    for(int i=0;i<n;i++){
        int find=hash(sum-arr[i]);
        if(find>=0){
            if(map->table[find]>0){
                printf("%d:%d\n", arr[i], find);
                map->table[find]=0;
                if(arr[i]>=0){
                    map->table[arr[i]]=0;
                }else{
                    map->negTable[arr[i]*-1]=0;
                }
            }
        }else{
            if(map->negTable[find]>0){
                printf("%d:%d\n", arr[i], find);
                map->negTable[find]=0;
                if(arr[i]>=0){
                    map->table[arr[i]]=0;
                }else{
                    map->negTable[arr[i]*-1]=0;
                }
            }
        }
        
    }
}

int main(){
    hashMap map;
    initHash(&map);
    
    int arr[]={2,-1,1,-2,-3,3,-4,5,0};
    int n=9;
    for(int i=0; i<n; i++)
        insert(&map, arr[i]);
    
    printf("Distrint sum: %d\n", disSum(&map));
    printf("Sum is: %d\n", sum(arr, n));
    
    pair(&map, arr, n, disSum(&map));
    
    return 0;
}