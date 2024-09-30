#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) 
{
    Item* item;
    item = (Item*)malloc( sizeof(Item));
    item->sku = (char*)malloc(strlen(sku));
    item->category= (char*)malloc(strlen(category));
    item->name = (char*)malloc(strlen(name));
    item->price = price;
    item->sku = sku;
    item->category = category;
    item->name = name;
    item_list[index]=*item;

}


void free_items(Item *item_list, int size) 
{
    
    for (int i = 0; i < size; i++) 
    {
        
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
    }
}

double average_price(Item *item_list, int size)
{
    double average = 0.0;
    for (int i = 0; i < size; i++) 
    {
        average+=item_list[i].price;
    }
    return average/(double)size;
}

void print_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %f\n", item_list[i].price);
    }
}

void find_item_by_sku(Item *item_list, int size) 
{
    char sku[50]; 
    int check=0;
    printf("\nType a SKU: ");
    scanf("%s", sku);  

    
    for (int i = 0; i < size; i++) {
        if (strcmp(item_list[i].sku, sku) == 0) {  
            
            printf("Item found:\n");
            printf("Name: %s\n", item_list[i].name);
            printf("SKU: %s\n", item_list[i].sku);
            printf("Category: %s\n", item_list[i].category);
            printf("Price: %f\n", item_list[i].price);
            return;  
        }
        else 
        {
            check++;
        }    
    }
    if (check==size)
    {
        printf("\nItem not found");
        return;
    }
}
int main() {
    
   Item* item_list ;
   double average = 0.0;
   char sku_to_look_for;
   
   item_list = (Item*)malloc( 5* sizeof(Item));

   add_item(item_list,5.99,"4567","fruits","apples",0);
   add_item(item_list,9.99,"3268","condiments","salt",1);
   add_item(item_list,0.99,"9352","candies","chewing-gum",2);
   add_item(item_list,9.0,"8329","grains","rice",3);
   add_item(item_list,10.47,"4782","fruits","mangos",4);

  print_items(item_list,5);
  average=average_price(item_list,5);
  printf("\nAverage price : %f",average);
  find_item_by_sku(item_list,5);

  return 0;
}
