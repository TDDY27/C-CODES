#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
 
struct employee{
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
};
typedef struct employee Employee;
 
void init_storage(Employee **storage, int n);
void free_storage(Employee **storage);
Employee* find_employee_by_id( Employee *set, int n, int id );
Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name );
Employee* find_root_boss( Employee *set, int n, Employee *employee );
int check_relationship(Employee *set, int n, Employee *A, Employee *B);
 
Employee* find_employee_by_id( Employee *set, int n, int id ){
    for(int i=0;i<n;i++) if(set[i].id==id) return &set[i];
}
Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name ){
    for(int i=0;i<n;i++) if(strcmp(first_name,set[i].first_name)==0 && strcmp(last_name,set[i].last_name)==0) return &set[i];
}
Employee* find_root_boss( Employee *set, int n, Employee *employee ){
    Employee* bss=find_employee_by_id(set,n,employee->boss_id);
    if(bss==employee) return bss;
    Employee*rbss=find_root_boss(set,n,bss);
    return rbss;
}

int check_relationship(Employee *set, int n, Employee *A, Employee *B){
    Employee *tmp=A;
    while(tmp!=find_employee_by_id(set,n,tmp->boss_id)){
        tmp=find_employee_by_id(set,n,tmp->boss_id);
        if(tmp==B) return 1;
    }
    tmp=B;
    while(tmp!=find_employee_by_id(set,n,tmp->boss_id)){
        tmp=find_employee_by_id(set,n,tmp->boss_id);
        if(tmp==A) return 2;
    }
    if(find_root_boss(set,n,A)==find_root_boss(set,n,B)) return 3;
    return 4;
}

void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}

#endif




 
// int main()
// {
//     int n, m;
//     int i;
//     Employee *set = NULL;
 
//     scanf("%d", &n);
//     init_storage(&set, n);
//     for ( i = 0 ; i < n ; i++ )
//         scanf("%d %s %s %d", &(set[i].id), set[i].first_name, set[i].last_name, &(set[i].boss_id));
//     char first_name_A[32], first_name_B[32];
//     char last_name_A[32], last_name_B[32];
//     Employee *A, *B;
//     int type;
 
//     scanf("%d", &m);
//     for ( i = 0 ; i < m ; i++ )
//     {
//         scanf("%s %s", first_name_A, last_name_A);  
//         A = find_employee_by_name(set, n, first_name_A, last_name_A);
//         // printf("%d", A->id);
 
//         scanf("%s %s", first_name_B, last_name_B);  
//         B = find_employee_by_name(set, n, first_name_B, last_name_B);
//         // printf("%d", B->id);
 
//         type = check_relationship(set, n, A, B);
//         switch(type){
//             case 1:
//                 printf("subordinate\n"); break;
//             case 2:
//                 printf("supervisor\n"); break;
//             case 3:
//                 printf("colleague\n"); break;
//             default:
//                 printf("unrelated\n"); break;
//         }
//     }
//     free_storage(&set);
//     return 0;
// }