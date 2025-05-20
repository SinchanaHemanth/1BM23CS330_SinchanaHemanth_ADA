char* removeDuplicates(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc((len+1)*sizeof(char));
    int TOP=-1;
    for(int i=0;i<len;i++) {
        if(TOP>=0 && stack[TOP]==s[i]) {
            TOP--;
        }
        else {
            stack[++TOP]=s[i];
        }
    }
    stack[TOP+1]='\0';
    return stack;
}
