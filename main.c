#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct CustRecord{
    char* firstName;
    char* lastName;
    char* phone;
    char* emailAddress;
};

static int count;

int findFirstName(struct CustRecord** ss, char* s){
    int i;
    for(i = 0; i < count; i++){
        if(strcmp(ss[i]->firstName, s) == 0) return i;
    }
    return -1;
}

int findLastName(struct CustRecord** ss, char* s){
    int i;
    for(i = 0; i < count; i++){
        if(strcmp(ss[i]->lastName, s) == 0) return i;
    }
    return -1;
}

int findEmail(struct CustRecord** ss, char* s){
    int i;
    for(i = 0; i < count; i++){
        if(strcmp(ss[i]->emailAddress, s) == 0) return i;
    }
    return -1;
}

int findPhone(struct CustRecord** ss, char* s){
    int i;
    for(i = 0; i < count; i++){
        if(strcmp(ss[i]->phone, s) == 0) return i;
    }
    return -1;
}

int main(int argc, char *argv[]) {

    char firstName[40];
    char lastName[40];
    char phone[40];
    char emailAddress[40];
    int command = 0;
    
    struct CustRecord** ss = (struct CustRecord**) malloc(100*sizeof(ss[0]));
    struct CustRecord* s;

    FILE *f;
    char *inputFile;
    
    (void)argc;

    inputFile = argv[1];
    f=fopen(inputFile, "r");
   
    if(f != NULL){

        while(fscanf(f, "%s %s %s %s", firstName, lastName, phone, emailAddress) != EOF){

            s = malloc(sizeof(*s));
            
            s->firstName = (char*) malloc(80 * sizeof(s->firstName[0]));
            s->lastName = (char*) malloc(80 * sizeof(s->firstName[0]));
            s->emailAddress = (char*) malloc(80 * sizeof(s->firstName[0]));
            s->phone = (char*) malloc(80 * sizeof(s->phone[0]));
            
            s->firstName = strcpy(s->firstName, firstName);
            s->lastName = strcpy(s->lastName, lastName);
            s->emailAddress = strcpy(s->emailAddress, emailAddress);
            s->phone = strcpy(s->phone, phone);
            
            ss[count] = s; 
            
            count += 1;
        }
    } else {
        perror("fopen:");
    }
    fclose(f);

    printf("Please enter the # of a search category.\n1: First Name\n2: Last Name\n3: Phone Number\n4: Email Address\n");
    scanf("%d", &command);
    printf("__________________\n");
    while(command != 0){

        char* val = malloc(100*sizeof(val[0]));
        printf("Please enter what you are searching for\n");
        fscanf(stdin, "%s", val);
        
        switch(command){
            case 1:
                printf("Looking for first name %s\n", val);
                if(findFirstName(ss, val) >= 0){
                    printf("Found in customer record %d\n", findFirstName(ss, val));
                }else{
                    printf("Does not exist in customer records\n");
                }
                command = 0;
                break;
            case 2:
                printf("looking for last name %s\n", val);
                if(findLastName(ss, val) >= 0){
                    printf("Found in customer record %d\n", findLastName(ss, val));
                }else{
                    printf("Does not exist in customer records\n");
                }
                command = 0;
                break;
            case 3:
                printf("looking for phone number %s\n", val);
                if(findPhone(ss, val) >= 0){
                    printf("Found in customer record %d\n", findPhone(ss, val));
                }else{
                    printf("Does not exist in customer records\n");
                }
                command = 0;
                break;
            case 4:
                printf("looking for email address %s\n", val);
                if(findEmail(ss, val) >= 0){
                    printf("Found in customer record %d\n", findEmail(ss, val));
                }else{
                    printf("Does not exist in customer records\n");
                }
                command = 0;
                break;
            default:
                fprintf(stderr, "Invalid input. Please input 1, 2, 3, or 4\n");
                command = 0;
                break;
        }
    }
}

