
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define subString_SIZE 5
#define action_SIZE 4

struct node{
    int data;
    struct node* next;
};

int main()
{
    int n;
    char subString[subString_SIZE];
    int move1;
    int move2;
    int num1;
    int num2;
    int *action[action_SIZE] = {&move1, &num1, &move2, &num2};
    int index;
    int k;
    while(scanf("%d", &n) != EOF){
        // build linked list
        struct node **arr = (struct node**)malloc(sizeof(struct node*)*n);
        for (int i=0; i<n; ++i){
            arr[i] = (struct node*)malloc(sizeof(struct node));
            arr[i] -> data = i;
            arr[i] -> next = NULL;
        }
        
        // read every action
        k = 0;
        while (scanf("%s", subString) != EOF){
            index = k%4;
            if (strcmp(subString, "quit") == 0){
                break;
            }
            else{
                if (index ==0){
                    if (strcmp(subString, "move") == 0) *action[index] = 0;
                    else if (strcmp(subString, "pile") == 0) *action[index] = 1;
                }
                else if (index == 2){
                    if (strcmp(subString, "onto") == 0) *action[index] = 0;
                    else if (strcmp(subString, "over") == 0) *action[index] = 1;
                }
                else{
                    *action[index] = atoi(subString);
                }
            }
            ++k;
            
            // execute action
            if (index==3){
                // illegal 1
                if (action[1] == action[3]) continue;
                
                // illegal 2
                struct node *cur;
                int num1_index;
                int num2_index;
                for (int i=0; i<n; ++i){
                    cur = arr[i];
                    while (cur){
                        if (cur -> data == *action[1]) num1_index = i;
                        if (cur -> data == *action[3]) num2_index = i;   
                        cur = cur -> next;
                    }
                }
                if (num1_index == num2_index) continue;
                

                // legal 
                struct node *last;
                struct node *a;
                struct node *b;
                int m = 0;
                int temp;
                if (*action[0] == 0 && *action[2] == 0){
                    // a
                    cur = arr[num1_index];
                    while (cur -> data != *action[1]){
                        last = cur;
                        cur = cur -> next;
                        ++m;
                    }
                    if (m == 0) arr[num1_index] = NULL;
                    else last -> next = NULL;

                    a = cur;
                    cur = cur -> next;
                    while (cur){
                        arr[cur -> data] = cur;
                        temp = cur -> data;
                        cur = cur -> next;
                        arr[temp] -> next = NULL;
                    }
 
                    // b
                    cur = arr[num2_index];
                    while (cur -> data != *action[3]){
                        cur = cur -> next;
                    }
                    
                    b = cur;
                    cur = cur -> next;
                    while (cur){
                        arr[cur -> data] = cur;
                        temp = cur -> data;
                        cur = cur -> next;
                        arr[temp] -> next = NULL;
                    }                  
                    b -> next = a;
                    a -> next = NULL;
                }
                
                else if (*action[0] == 0 && *action[2] == 1){
                    // a
                    cur = arr[num1_index];
                    while (cur -> data != *action[1]){
                        last = cur;
                        cur = cur -> next;
                        ++m;
                    }
                    if (m == 0) arr[num1_index] = NULL;
                    else last -> next = NULL;

                    a = cur;
                    cur = cur -> next;
                    while (cur){
                        arr[cur -> data] = cur;
                        temp = cur -> data;
                        cur = cur -> next;
                        arr[temp] -> next = NULL;
                    }

                    // b
                    cur = arr[num2_index];
                    while (cur -> next != NULL){
                        cur = cur -> next;
                    }
                    cur -> next = a;
                    a -> next = NULL;
                }
                
                else if (*action[0] == 1 && *action[2] == 0){
                    // a
                    cur = arr[num1_index];
                    while (cur -> data != *action[1]){
                        last = cur;
                        cur = cur -> next;
                        ++m;
                    }
                    if (m == 0) arr[num1_index] = NULL;
                    else last -> next = NULL;
                    a = cur;
                    
                    // b
                    cur = arr[num2_index];
                    while (cur -> data != *action[3]){
                        last = cur;
                        cur = cur -> next;
                    }
                    
                    b = cur;
                    cur = cur -> next;
                    while (cur){
                        arr[cur -> data] = cur;
                        temp = cur -> data;
                        cur = cur -> next;
                        arr[temp] -> next = NULL;
                    }                  
                    b -> next = a;
                }
                
                else if (*action[0] == 1 && *action[2] == 1){
                    // a
                    cur = arr[num1_index];
                    while (cur -> data != *action[1]){
                        last = cur;
                        cur = cur -> next;
                        ++m;
                    }
                    if (m == 0) arr[num1_index] = NULL;
                    else last -> next = NULL;
                    a = cur;
                    
                    // b
                    cur = arr[num2_index];
                    while (cur -> next != NULL){
                        cur = cur -> next;
                    }
                    cur -> next = a;
                }
                
            }
        }
        
        //print result
        struct node *cur;
        for (int i=0; i<n; ++i){
            printf("%d: ", i);
            cur = arr[i];
            while (cur){
                printf("%d ", cur -> data);
                cur = cur -> next;
            }
            printf("%s", "\n");
        }
    }

    return 0;
}
