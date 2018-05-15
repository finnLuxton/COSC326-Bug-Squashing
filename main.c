#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct S{
    char* firstName;
    char* lastName;
    int phone;
    char* emailAddress;
};

// This is public visiblity, will be fucked for multiple uses. Place inside of all searches
static int i;
static int count;

int ffn(struct S** ss, char* s){
    //++i doesnt work for these, swap to for loops
    while(++i < count){
        // C cannot do this, use the stringcompare method
        // Same for all except phone, since its an int
        if(ss[i]->firstName == s)
            return 1;
    }
    return 0;
}

int fln(struct S** ss, char* s){
    while(++i < count){
        if(ss[i]->lastName == s)
            return 1;
    }
    return 0;
}

int fem(struct S** ss, char* s){
    while(++i < count){
        if(ss[i]->emailAddress == s)
            return 1;
    }
    return 0;
}

int fph(struct S** ss, int s){
    while(++i < count){
        if(ss[i]->phone == s)
            return 1;
    }
    return 0;
}

int main(int argc, char ** argv) {
    int i;
    int count = 0;
    (void)argc;
    
    struct S** ss = (struct S**) malloc(100*sizeof(ss[0]));
    struct S* s = malloc(sizeof(*s));

    FILE *f = fopen(argv[1], "r");

    // Change to while loop until file is entirely read
    for(i = 0; i < 50; i++){

        // Figure that shit out
        s->firstName = (char*) malloc(80 * sizeof(s->firstName[0]));
        s->lastName = (char*) malloc(80 * sizeof(s->firstName[0]));
        s->emailAddress = (char*) malloc(80 * sizeof(s->firstName[0]));

        
	fscanf(f, "%s %s %d %s", s->firstName, s->lastName, &s->phone, s->emailAddress);
	
	ss[count] = s;
        count += 1;
    }
    // Scan user input for command
    int command = 10;
    while(command != 0){
        //Should be correct
        char* val = malloc(100*sizeof(val[0]));
        // 4 lines below should be useless


        //Command + " " + lookingforinput(eg finn)
        switch(command){
            // Change order of cases and fix their calls and method names for find methods
            case 1:
                printf("looking for email %s\n", val);
                printf("found it? %d\n", fem(ss, val));
                break;
            case 2:
                printf("looking for firstname %s\n", val);
                printf("found it? %d\n", ffn(ss, val));
                break;
            case 3:
                printf("looking for lastname %s\n", val);
                printf("found it? %d\n", fln(ss, val));
                break;
            case 4:
                printf("looking for email %s\n", val);
                printf("found it? %d\n", fph(ss, atoi(val)));
                break;
            default:
                // Add error message
                break;
        }
    }
}

