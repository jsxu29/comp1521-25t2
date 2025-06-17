char *string = "....";
char *s = &string[0];
int   length = 0; // INIT

while (*s != '\0') { // COND
   // BODY
   length++;  // increment length

   // STEP 
   s++;       // move to next char
}

// POST
