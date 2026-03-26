extern int my_printf(const char *fmt, ...);

int main()
{
    char ch1 = 'Q';
    char* str1 = "i am cockblock";
    
    // my_printf("robots are attacking!!! %c %c %c", 'A', 'B', 'C');
    // my_printf("hello world! %c %s\n", ch1, str1);
    my_printf("pisya popa %x %%x %x",1234, 0x0ea, 0x000000d);
    return 0;
}