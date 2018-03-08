#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll id = 1;
struct Node {
    ll process_id;
    ll memory;
    ll used;
    struct Node* next;
};
struct Node* initialize_node(struct Node* list,ll mleft){
    list = (struct Node*)malloc(sizeof(struct Node));
    list->memory = mleft;
    list->used = 0;
    list->process_id = id;
    id++;
    list->next = NULL;
    return list;
}

ll add_node (struct Node** list,ll memory){
    struct Node* temp = *list;
    struct Node* prev_temp = temp;
    while(temp != NULL){
        if(temp->used == 0){
            if(temp->memory > memory){
                struct Node* second_temp = temp->next;
                struct Node* third_temp = NULL;
                temp->next = initialize_node(third_temp,temp->memory-memory);
                temp->memory = memory;
                temp->used = memory;
                temp->next->next = second_temp;
                return 1;
            }else if(temp->memory == memory){
                temp->used = memory;
                return 1;
            }
        }
        prev_temp = temp;
        temp = temp->next;
    }
    if (prev_temp->used == 0 && prev_temp->memory > memory) {
        prev_temp->next = initialize_node(prev_temp->next,prev_temp->memory-memory);
        prev_temp->memory = memory;
        prev_temp->used = memory;
        return 1;
    }else if (prev_temp->used == 0 && prev_temp->memory == memory) {
        prev_temp->memory = memory;
        prev_temp->used = memory;
        return 1;
    }else {
        return 0;
    }
}

ll best_add_node (struct Node** list,ll memory){
    struct Node* temp = *list;
    struct Node* emptymax = NULL;
    struct Node* prev_temp = temp;
    while(temp != NULL){
        if(temp->used == 0){
            if(temp->memory > memory && (emptymax == NULL || temp->memory < emptymax->memory)){
                emptymax = temp;
            }else if(temp->memory == memory){
                temp->used = memory;
                return 1;
            }
        }
        prev_temp = temp;
        temp = temp->next;
    }
    temp = emptymax;
    if(temp!=NULL){
        struct Node* second_temp = temp->next;
        struct Node* third_temp = NULL;
        temp->next = initialize_node(third_temp,temp->memory-memory);
        temp->memory = memory;
        temp->used = memory;
        temp->next->next = second_temp;
        return 1;
    }
    if (prev_temp->used == 0 && prev_temp->memory > memory) {
        prev_temp->next = initialize_node(prev_temp->next,prev_temp->memory-memory);
        prev_temp->memory = memory;
        prev_temp->used = memory;
        return 1;
    }else if (prev_temp->used == 0 && prev_temp->memory == memory) {
        prev_temp->memory = memory;
        prev_temp->used = memory;
        return 1;
    }else {
        return 0;
    }
}

ll worst_add_node (struct Node** list,ll memory){
    struct Node* temp = *list;
    struct Node* emptymax = NULL;
    struct Node* prev_temp = temp;
    while(temp != NULL){
        if(temp->used == 0){
            if(temp->memory >= memory && (emptymax == NULL || temp->memory > emptymax->memory)){
                emptymax = temp;
            }
        }
        prev_temp = temp;
        temp = temp->next;
    }
    temp = emptymax;

	if(temp&&temp->memory == memory){
		temp->used = memory;
        return 1;
	}

    if(temp!=NULL){
        struct Node* second_temp = temp->next;
        struct Node* third_temp = NULL;
        temp->next = initialize_node(third_temp,temp->memory-memory);
        temp->memory = memory;
        temp->used = memory;
        temp->next->next = second_temp;
        return 1;
    }
    if (prev_temp->used == 0 && prev_temp->memory > memory) {
        prev_temp->next = initialize_node(prev_temp->next,prev_temp->memory-memory);
        prev_temp->memory = memory;
        prev_temp->used = memory;
        return 1;
    }else if (prev_temp->used == 0 && prev_temp->memory == memory) {
        prev_temp->memory = memory;
        prev_temp->used = memory;
        return 1;
    }else {
        return 0;
    }
}


void print_list(struct Node* list){
    struct Node* temp = list;
    cout<<"Id\tUsed\tfree memory"<<endl;
    while(temp){
        cout<<temp->process_id<<"\t"<<temp->used<<"\t"<<temp->memory-temp->used<<endl;
        temp=temp->next;
    }
}

void check_combinations(struct Node** list){
    struct Node* temp = *list;
    while(temp->next){
        if(temp->used ==0 &&temp->next&&temp->next->used == 0){
            temp->memory = temp->memory + temp->next->memory;
            struct Node* second_temp = temp->next;
            temp->next = temp->next->next;
            free(second_temp);
            if(temp->next == NULL){
                break;
            }
        }
        temp = temp->next;
    }
}

void delete_id(struct Node** list,ll idd){
    struct Node* temp = *list;
    while(temp){
        cout<<temp->process_id<<" ";
        if(temp->process_id == idd){
            temp->used = 0;
            if(temp->next&&temp->next->used == 0){
                temp->memory = temp->memory + temp->next->memory;
                struct Node* second_temp = temp->next;
                temp->next = temp->next->next;
                free(second_temp);
                check_combinations(list);
                return;
            }else {
                check_combinations(list);
                return;
            }
        }
        temp=temp->next;
    }
    check_combinations(list);
}

ll sum(struct Node* list){
	struct Node* temp = list;
	ll s = 0;
	while(temp){
		if(temp->used == 0){
			s+=temp->memory;
		}
		temp=temp->next;
	}
	return s;
}

int main(){
    struct Node* list;
    cout<<"Enter size of memory"<<endl;
    ll m;
    cin>>m;
    ll mleft;
    mleft = m;
    list = initialize_node(list,mleft);
    ll i=0;
    ll pm;
    while(1){
        cout<<"Enter 1 to continue and 0 to exit"<<endl;
        ll type;
        cin>>type;
        if(type == 0){
            break;
        }
        cout<<"Enter size of process "<<id<<endl;
        cin>>pm;
        xxx:
        ll check = worst_add_node(&list,pm);
        if(check == 1){

        }else {
            cout<<"Enter the process id you want to delete\n";
            ll idd;
            cin>>idd;
            delete_id(&list,idd);
            ll su = sum(list);
            if(su >= pm){
            	cout<<"External Fragment is "<<su<<endl;
            }
            print_list(list);
            goto xxx;
        }
        print_list(list);
    }
}