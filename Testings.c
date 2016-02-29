    //strcmp char literal and char pointer
    char temp[2] = "R\0";
    char * a = (char*)malloc(2 * sizeof(char));
    strcpy(a, temp);
    printf("%s\n" ,a);
    int val = strcmp (a, "R");
    printf("%d\n", val);
