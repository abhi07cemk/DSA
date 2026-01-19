void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char* s, int sSize) 
{
    if(sSize < 1)
    {
        return;
    }
    swap(&s[0], &s[sSize-1]);

    return reverseString(s+1, sSize-2);
}