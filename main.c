#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Replace variable name
struct S{
    char* firstName;
    char* lastName;
    int phone;
    char* emailAddress;
};

static int count;

int findFirstName(struct S** ss, char* s){
    int i;
    for(i = 0; i < count; i++){
        // C cannot do this, use the stringcompare method
        // Same for all except phone, since its an int
        if(ss[i]->firstName == s)
            return 1;
    }
    return 0;
}

int findLastName(struct S** ss, char* s){
    int i;
    for(i = 0; i < count; i++){
        if(ss[i]->lastName == s)
            return 1;
    }
    return 0;
}

int findEmail(struct S** ss, char* s){
    int i;
    for(i = 0; i < count; i++){
        if(ss[i]->emailAddress == s)
            return 1;
    }
    return 0;
}

int findPhone(struct S** ss, int s){
    int i;
    for(i = 0; i < count; i++){
        if(ss[i]->phone == s)
            return 1;
    }
    return 0;
}

int main(int argc, char ** argv) {
    int i, c;
    int count = 0;
    (void)argc;
    
    // 242 code, maybe bst where you str copy in memory allocation so it never overrises itself and thats how you fi the problem good luck me
    struct S** ss = (struct S**) malloc(100*sizeof(ss[0]));
    struct S* s = malloc(sizeof(*s));

    FILE *f = fopen(argv[1], "r");

    while((c = fgetc(f)) != EOF){

        // Figure that shit out
        s->firstName = (char*) malloc(80 * sizeof(s->firstName[0]));
        s->lastName = (char*) malloc(80 * sizeof(s->firstName[0]));
        s->emailAddress = (char*) malloc(80 * sizeof(s->firstName[0]));

	fscanf(f, "%s %s %d %s", s->firstName, s->lastName, &s->phone, s->emailAddress);
	
	ss[count] = s;
        count += 1;
    }
    fclose(f);

    // Scan user input for command
    int command = 10;
    while(command != 0){
        //Should be correct
        char* val = malloc(100*sizeof(val[0]));

        //Command + " " + lookingforinput(eg finn)
        switch(command){
            // Check to see if input is correct
            case 1:
                printf("Looking for firstname %s\n", val);
                printf("found it? %d\n", findFirstName(ss, val));
                break;
            case 2:
                printf("looking for lastname %s\n", val);
                printf("found it? %d\n", findLastName(ss, val));
                break;
            case 3:
                printf("looking for phone %s\n", val);
                printf("found it? %d\n", findPhone(ss, atoi(val)));
                break;
            case 4:
                printf("looking for email %s\n", val);
                printf("found it? %d\n", findEmail(ss, val));
                break;
            default:
                fprintf(stderr, "Invalid input. Please input 1, 2, 3, or 4");
                break;
        }
    }
}

